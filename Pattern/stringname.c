#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ---------------- LETTER PATTERNS ----------------

void printA(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1 || i==n/2 || i==0 && j>0 && j<n-1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void printB(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || (i==0||i==n/2||i==n-1)&&j<n-1 || j==n-1&&(i!=0&&i!=n/2&&i!=n-1))
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printC(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0 && j>0 || i==n-1 && j>0)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printD(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || (i==0||i==n-1)&&j<n-1 || j==n-1&&i>0&&i<n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printE(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0 || i==n/2 || i==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printF(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0 || i==n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printG(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0 && j>0 || i==n-1 && j>0 || j==n-1&&i>=n/2 || i==n/2&&j>=n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printH(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1 || i==n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printI(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printJ(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==n/2 || i==n-1 && j<n/2 || j==0 && i>=n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printK(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-i-1 && i<=n/2 || j==i && i>=n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printL(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printM(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1 || (i==j && i<=n/2) || (i+j==n-1 && i<=n/2))
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printN(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1 || i==j)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printO(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==0||j==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printP(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0 && j<n-1 || i==n/2 && j<n-1 || j==n-1 && i<n/2 && i>0)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printQ(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==0||j==n-1||(i==j&&i>=n/2))
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printR(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || i==0&&j<n-1 || i==n/2&&j<n-1 || j==n-1&&i<n/2 && i>0 || i-j==n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printS(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n/2||i==n-1||j==0&&i<n/2||j==n-1&&i>n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printT(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printU(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0 || j==n-1 || i==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printV(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2 - 1; j++) {
            if (j == i || j == (2 * n - 2 - i))
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }
}

void printW(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0||j==n-1||(i==j&&i>=n/2)||(i+j==n-1&&i>=n/2))
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printX(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||i+j==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printY(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i==j&&i<n/2)||(i+j==n-1&&i<n/2)||j==n/2&&i>=n/2)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

void printZ(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||i+j==n-1)
                printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

// ---------------- DISPATCH FUNCTION ----------------

void printLetter(char ch, int size) {
    ch = toupper(ch);
    switch (ch) {
        case 'A': 
            printA(size); 
            break;
        case 'B':
            printB(size); 
            break;
        case 'C': 
            printC(size); 
            break;
        case 'D': 
            printD(size); 
            break;
        case 'E': 
            printE(size); 
            break;
        case 'F': 
            printF(size); 
            break;
        case 'G': 
            printG(size); 
            break;
        case 'H': 
            printH(size); 
            break;
        case 'I': 
            printI(size); 
            break;
        case 'J': 
            printJ(size); 
            break;
        case 'K': 
            printK(size); 
            break;
        case 'L':
            printL(size); 
            break;
        case 'M':
            printM(size); 
            break;
        case 'N': 
            printN(size); 
            break;
        case 'O': 
            printO(size); 
            break;
        case 'P': 
            printP(size); 
            break;
        case 'Q': 
            printQ(size); 
            break;
        case 'R': 
            printR(size); 
            break;
        case 'S': 
            printS(size); 
            break;
        case 'T': 
            printT(size); 
            break;
        case 'U': 
            printU(size); 
            break;
        case 'V': 
            printV(size); 
            break;
        case 'W': 
            printW(size); 
            break;
        case 'X': 
            printX(size); 
            break;
        case 'Y': 
            printY(size); 
            break;
        case 'Z': 
            printZ(size); 
            break;
        default: 
            printf("Character %c not supported.\n", ch);
    }
}

// ---------------- MAIN PROGRAM ----------------

int main(){
    char text[100];
    char dir;
    int size;

    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter size of pattern (recommended 5-7): ");
    scanf("%d", &size);

    printf("Print Horizontally or Vertically (H/V): ");
    scanf(" %c", &dir);

    if(toupper(dir) == 'V') {
        for(int i=0; text[i]!='\0'; i++) {
            if(text[i] == ' ') continue;
            printLetter(text[i], size);
            printf("\n");
        }
    } else {
        for(int i=0; text[i]!='\0'; i++) {
            if(text[i] == ' ') continue;
            printLetter(text[i], size);
            printf("\n");
        }
    }

    return 0;
}
