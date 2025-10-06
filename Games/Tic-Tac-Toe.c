#include <stdio.h>
#include <stdlib.h>

char board[3][3];

// -------- Function Declarations --------
void initializeBoard();
void printBoard();
int checkWin();
int checkDraw();
int isValidMove(int choice);
void makeMove(int choice, char mark);
int computerMove();

// -------- Function Definitions --------

// Initialize the board with numbers 1–9
void initializeBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count + '0';
            count++;
        }
    }
}

// Print the board
void printBoard() {
    system("clear"); // use "cls" on Windows
    printf("\nTic Tac Toe (You = X | Computer = O)\n\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Check win condition
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

// Check draw condition
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

// Check if a move is valid
int isValidMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O')
        return 1;
    return 0;
}

// Place mark on the board
void makeMove(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = mark;
}

// Computer's move: win > block > first free cell
int computerMove() {
    // Try to win
    for (int i = 1; i <= 9; i++) {
        if (isValidMove(i)) {
            makeMove(i, 'O');
            if (checkWin()) return i; // winning move
            else board[(i - 1) / 3][(i - 1) % 3] = i + '0'; // undo
        }
    }
    // Try to block player
    for (int i = 1; i <= 9; i++) {
        if (isValidMove(i)) {
            makeMove(i, 'X');
            if (checkWin()) {
                board[(i - 1) / 3][(i - 1) % 3] = 'O'; // block here
                return i;
            } else board[(i - 1) / 3][(i - 1) % 3] = i + '0'; // undo
        }
    }
    // Pick first available spot
    for (int i = 1; i <= 9; i++) {
        if (isValidMove(i)) {
            makeMove(i, 'O');
            return i;
        }
    }
    return -1;
}

// -------- Main Function --------
int main() {
    int choice,x;
    start:

    initializeBoard();

    while (1) {
        printBoard();

        // Player move
        printf("Your turn (1-9): ");
        scanf("%d", &choice);

        if (!isValidMove(choice)) {
            printf("Invalid move! Try again.\n");
            getchar();
            continue;
        }
        makeMove(choice, 'X');

        if (checkWin()) {
            printBoard();
            printf("You win!\n");
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Computer move
        computerMove();

        if (checkWin()) {
            printBoard();
            printf("Computer wins!\n");
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
    // Condition to play again.
    printf("Enter your choice[1 for Yes]:");
    scanf("%d",&x);
    if(x==1){
        goto start;    //goto : Repeat the main()
    }
    else{
        return 0;
    }
}
