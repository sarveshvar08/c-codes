
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else
  #define CLEAR_CMD "clear"
#endif

#define MAX_PLAYERS 11
#define NAME_LEN 32

typedef enum {MODE_0_6, MODE_1_6} NumberMode;
typedef enum {GM_PVC, GM_PVP, GM_TEAM_TEAM, GM_TEAM_CPU} GameMode;
typedef enum {AI_EASY, AI_MEDIUM} AIDifficulty;

typedef struct {
    char name[NAME_LEN];
    int runs;
    int balls;
    int out; // 0 not out, 1 out
} Batter;

typedef struct {
    char team_name[NAME_LEN];
    int n; // number of players
    Batter players[MAX_PLAYERS];
    int total_runs;
    int wickets;
} Team;

void clear_screen() {
    system(CLEAR_CMD);
}

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int safe_int(const char *prompt, int min, int max) {
    char buf[64];
    int x;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) { clearerr(stdin); continue; }
        if (sscanf(buf, "%d", &x) != 1) {
            printf("Please enter a number.\n");
            continue;
        }
        if (x < min || x > max) {
            printf("Enter a number between %d and %d.\n", min, max);
            continue;
        }
        return x;
    }
}

void read_str(const char *prompt, char *out, int len) {
    printf("%s", prompt);
    if (!fgets(out, len, stdin)) {
        out[0] = '\0';
        return;
    }
    size_t L = strlen(out);
    if (L > 0 && out[L-1] == '\n') out[L-1] = '\0';
}

/* AI moves */
int ai_easy(NumberMode nm) {
    int lo = (nm == MODE_1_6) ? 1 : 0;
    return lo + rand() % (7 - lo);
}

int ai_medium(NumberMode nm, int batting) {
    int lo = (nm == MODE_1_6) ? 1 : 0;
    int hi = 6;
    // weights array for values 0..6 (ignore below lo)
    int weights[7] = {0,0,0,0,0,0,0};
    for (int i = lo; i <= hi; ++i) weights[i] = 1;
    if (batting) {
        // batting: favor 3..6
        for (int i = 3; i <= 6; ++i) weights[i] += 2;
    } else {
        // bowling: favor 1..4 to try to match common human picks
        for (int i = lo; i <= 4; ++i) weights[i] += 2;
    }
    int total = 0;
    for (int i = lo; i <= hi; ++i) total += weights[i];
    int r = rand() % total;
    int acc = 0;
    for (int i = lo; i <= hi; ++i) {
        acc += weights[i];
        if (r < acc) return i;
    }
    return hi;
}

/* Initialize team structure */
void init_team(Team *t, const char *name, int players) {
    strncpy(t->team_name, name, NAME_LEN-1);
    t->team_name[NAME_LEN-1] = '\0';
    t->n = players;
    t->total_runs = 0;
    t->wickets = 0;
    for (int i = 0; i < players; ++i) {
        snprintf(t->players[i].name, NAME_LEN, "P%d", i+1);
        t->players[i].runs = 0;
        t->players[i].balls = 0;
        t->players[i].out = 0;
    }
}

/* Print a compact scoreboard */
void print_score(const Team *t) {
    printf("%s: %d/%d\n", t->team_name, t->total_runs, t->wickets);
    for (int i = 0; i < t->n; ++i) {
        printf(" %2d. %-10s %3d (%2d) %s\n", i+1, t->players[i].name,
               t->players[i].runs, t->players[i].balls,
               t->players[i].out ? "OUT" : "NOTOUT");
    }
}

/* Core innings engine for batting team */
void innings_engine(Team *bat, Team *bowl, NumberMode nm, AIDifficulty aiDiff,
                    GameMode gm, int overs_limit, int isSecondInnings, int target) {
    int lo = (nm == MODE_1_6) ? 1 : 0;
    int maxBalls = (overs_limit == 0) ? -1 : overs_limit * 6;
    int balls = 0;
    int current = 0; // current batter index

    printf("\n=== %s batting ===\n", bat->team_name);
    printf("Press Enter to begin...\n"); getchar();

    while (1) {
        if (bat->wickets >= bat->n) {
            printf("All out for %s!\n", bat->team_name);
            break;
        }
        if (maxBalls != -1 && balls >= maxBalls) {
            printf("Overs complete for %s.\n", bat->team_name);
            break;
        }
        Batter *cur = &bat->players[current];

        int batter_move = -1, bowler_move = -1;

        /* Determine who enters values: humans vs computer team */
        int batting_is_cpu = (strcmp(bat->team_name, "Computer") == 0);
        int bowling_is_cpu = (strcmp(bowl->team_name, "Computer") == 0);

        if (batting_is_cpu) {
            // Computer batting, human bowling
            if (aiDiff == AI_EASY) batter_move = ai_easy(nm);
            else batter_move = ai_medium(nm, 1);
            printf("%s (bowling) enter your number: ", bowl->team_name);
            bowler_move = safe_int("", lo, 6);
            clear_screen();
        } else if (bowling_is_cpu) {
            // Human batting, computer bowling
            printf("%s - %s enter your number: ", bat->team_name, cur->name);
            batter_move = safe_int("", lo, 6);
            clear_screen();
            if (aiDiff == AI_EASY) bowler_move = ai_easy(nm);
            else bowler_move = ai_medium(nm, 0);
        } else {
            // Both human sides (PvP or Team vs Team)
            printf("%s - %s enter your number: ", bat->team_name, cur->name);
            batter_move = safe_int("", lo, 6);
            clear_screen();
            printf("%s (bowling) enter your number: ", bowl->team_name);
            bowler_move = safe_int("", lo, 6);
            clear_screen();
        }

        balls++;
        cur->balls++;

        if (batter_move == bowler_move) {
            // OUT
            cur->out = 1;
            bat->wickets++;
            printf("OUT! %s is out (picked %d, bowled %d)\n", cur->name, batter_move, bowler_move);
            current++;
        } else {
            cur->runs += batter_move;
            bat->total_runs += batter_move;
            printf("%s scored %d (Team %s: %d/%d)\n", cur->name, batter_move, bat->team_name, bat->total_runs, bat->wickets);
        }

        // quick ball summary
        printf("Ball %d: %s %d vs %s %d\n", balls, cur->name, batter_move, bowl->team_name, bowler_move);

        if (isSecondInnings && bat->total_runs >= target) {
            printf("%s reached the target of %d!\n", bat->team_name, target);
            break;
        }
    }

    printf("\nEnd of innings: %s scored %d/%d\n", bat->team_name, bat->total_runs, bat->wickets);
}

/* Run a match according to the chosen mode and settings */
void run_match(GameMode gm, NumberMode nm, AIDifficulty aiDiff, int overs) {
    Team t1, t2;
    char tmp[NAME_LEN];

    if (gm == GM_PVC) {
        read_str: ;
        char player_name[NAME_LEN];
        read_str("Enter your name: ", player_name, NAME_LEN);
        init_team(&t1, player_name, 1);
        init_team(&t2, "Computer", 1);
        strncpy(t2.players[0].name, "Computer", NAME_LEN-1);
    } else if (gm == GM_PVP) {
        char p1[NAME_LEN], p2[NAME_LEN];
        read_str("Player 1 name: ", p1, NAME_LEN);
        read_str("Player 2 name: ", p2, NAME_LEN);
        init_team(&t1, p1, 1);
        init_team(&t2, p2, 1);
    } else if (gm == GM_TEAM_TEAM) {
        int n1 = safe_int("Team 1 size (1-11): ", 1, MAX_PLAYERS);
        int n2 = safe_int("Team 2 size (1-11): ", 1, MAX_PLAYERS);
        char tn1[NAME_LEN], tn2[NAME_LEN];
        read_str("Team 1 name: ", tn1, NAME_LEN);
        read_str("Team 2 name: ", tn2, NAME_LEN);
        init_team(&t1, tn1, n1);
        init_team(&t2, tn2, n2);
        for (int i = 0; i < n1; ++i) {
            char prompt[80];
            snprintf(prompt, sizeof(prompt), "Enter %s player %d name: ", tn1, i+1);
            read_str(prompt, t1.players[i].name, NAME_LEN);
        }
        for (int i = 0; i < n2; ++i) {
            char prompt[80];
            snprintf(prompt, sizeof(prompt), "Enter %s player %d name: ", tn2, i+1);
            read_str(prompt, t2.players[i].name, NAME_LEN);
        }
    } else { // GM_TEAM_CPU
        int n1 = safe_int("Your team size (1-11): ", 1, MAX_PLAYERS);
        char tn1[NAME_LEN];
        read_str("Your team name: ", tn1, NAME_LEN);
        init_team(&t1, tn1, n1);
        for (int i = 0; i < n1; ++i) {
            char prompt[80];
            snprintf(prompt, sizeof(prompt), "Enter %s player %d name: ", tn1, i+1);
            read_str(prompt, t1.players[i].name, NAME_LEN);
        }
        int n2 = safe_int("Computer team size (1-11): ", 1, MAX_PLAYERS);
        init_team(&t2, "Computer", n2);
        for (int i = 0; i < n2; ++i) {
            snprintf(t2.players[i].name, NAME_LEN, "CPU%d", i+1);
        }
    }

    // TOSS (simple odd/even)
    printf("\n--- TOSS ---\n");
    int call = safe_int("Choose call: 1) Odd  2) Even : ", 1, 2);
    int user_pick = safe_int("Enter your toss number: ", (nm==MODE_1_6)?1:0, 6);
    int opp_pick;
    if (gm == GM_PVC || gm == GM_TEAM_CPU) {
        // computer picks
        if (aiDiff == AI_EASY) opp_pick = ai_easy(nm);
        else opp_pick = ai_medium(nm, 0);
        printf("Opponent picked %d\n", opp_pick);
    } else {
        // human opponent
        char prompt[80];
        snprintf(prompt, sizeof(prompt), "%s, enter toss number: ", t2.team_name);
        opp_pick = safe_int(prompt, (nm==MODE_1_6)?1:0, 6);
    }
    int sum = user_pick + opp_pick;
    int isOdd = sum % 2;
    int userWins = (call == 1 && isOdd) || (call == 2 && !isOdd);
    Team *first = &t1, *second = &t2;
    if (!userWins) {
        // opponent won toss; choose randomly to bat or field (simple)
        int choice = (rand() % 2) + 1; // 1 bat 2 bowl
        if (choice == 1) {
            printf("%s chose to bat first.\n", t2.team_name);
            first = &t2; second = &t1;
        } else {
            printf("%s chose to bowl first.\n", t2.team_name);
            first = &t1; second = &t2;
        }
    } else {
        int ch = safe_int("You won toss: 1) Bat 2) Bowl : ", 1, 2);
        if (ch == 2) { first = &t2; second = &t1; }
    }

    clear_screen();
    // First innings
    innings_engine(first, second, nm, aiDiff, gm, overs, 0, 0);
    int target = first->total_runs + 1;
    printf("\nTarget for %s is %d\n", second->team_name, target);
    printf("Press Enter to start second innings...\n"); getchar();
    clear_screen();
    // Second innings
    innings_engine(second, first, nm, aiDiff, gm, overs, 1, target);

    // Show final scores and winner
    printf("\n--- Final Scores ---\n");
    print_score(&t1);
    printf("\n");
    print_score(&t2);
    printf("\n");
    if (t1.total_runs > t2.total_runs) printf("Winner: %s\n", t1.team_name);
    else if (t2.total_runs > t1.total_runs) printf("Winner: %s\n", t2.team_name);
    else printf("Match Tied!\n");
}

/* Main menu */
int main() {
    srand((unsigned int)time(NULL));
    printf("=== Hand Cricket (Compact) ===\n");
    while (1) {
        printf("\nMain Menu:\n");
        printf("1) Player vs Computer (single)\n");
        printf("2) Player vs Player (offline)\n");
        printf("3) Team vs Team (offline)\n");
        printf("4) Team vs Computer\n");
        printf("5) Exit\n");

        int choice = safe_int("Choose option: ", 1, 5);
        if (choice == 5) break;

        NumberMode nm = (safe_int("Number mode: 1) 0-6  2) 1-6 : ", 1, 2) == 1) ? MODE_0_6 : MODE_1_6;
        int overs = safe_int("Overs (0 = unlimited): ", 0, 100);
        AIDifficulty aiDiff = AI_EASY;
        if (choice == 1 || choice == 4) {
            int d = safe_int("AI difficulty: 1) Easy 2) Medium : ", 1, 2);
            aiDiff = (d==1) ? AI_EASY : AI_MEDIUM;
        }

        if (choice == 1) run_match(GM_PVC, nm, aiDiff, overs);
        else if (choice == 2) run_match(GM_PVP, nm, aiDiff, overs);
        else if (choice == 3) run_match(GM_TEAM_TEAM, nm, aiDiff, overs);
        else if (choice == 4) run_match(GM_TEAM_CPU, nm, aiDiff, overs);

        printf("\nPress Enter to return to main menu...\n");
        getchar();
        clear_screen();
    }

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
