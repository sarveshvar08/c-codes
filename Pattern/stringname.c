// MY PATTERN PRINTING PROGRAM
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Alphabets functions
void patternA(int n, int arr[n][2*n]) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||i==n/2||(i==0&&j>0&&j<n-1));
}
void patternB(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||(i==0||i==n/2||i==n-1)&&j<n-1||j==n-1&&(i!=0&&i!=n/2&&i!=n-1));
}
void patternC(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||(i==0&&j>0)||(i==n-1&&j>0));
}
void patternD(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||((i==0||i==n-1)&&j<n-1)||(j==n-1&&i>0&&i<n-1));
}
void patternE(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||i==0||i==n/2||i==n-1);
}
void patternF(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||i==0||i==n/2);
}
void patternG(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||(i==0&&j>0)||(i==n-1&&j>0)||(j==n-1&&i>=n/2)||(i==n/2&&j>=n/2));
}
void patternH(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||i==n/2);
}
void patternI(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||j==n/2);
}
void patternJ(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||j==n/2||(i==n-1&&j<n/2)||(j==0&&i>=n/2));
}
void patternK(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-i-1&&i<=n/2||j==i&&i>=n/2);
}
void patternL(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||i==n-1);
}
void patternM(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||(i==j&&i<=n/2)||(i+j==n-1&&i<=n/2));
}
void patternN(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||i==j);
}
void patternO(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||j==0||j==n-1);
}
void patternP(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||i==0&&j<n-1||i==n/2&&j<n-1||j==n-1&&i<n/2&&i>0);
}
void patternQ(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||j==0||j==n-1||(i==j&&i>=n/2));
}
void patternR(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||i==0&&j<n-1||i==n/2&&j<n-1||j==n-1&&i<n/2&&i>0||i-j==n/2);
}
void patternS(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n/2||i==n-1||(j==0&&i<n/2)||(j==n-1&&i>n/2));
}
void patternT(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||j==n/2);
}
void patternU(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||i==n-1);
}
void patternV(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<2*n-1;j++)
            arr[i][j]=(j==i||j==(2*n-2-i));
}
void patternW(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==0||j==n-1||(i==j&&i>=n/2)||(i+j==n-1&&i>=n/2));
}
void patternX(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==j||i+j==n-1);
}
void patternY(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=((i==j&&i<n/2)||(i+j==n-1&&i<n/2)||(j==n/2&&i>=n/2));
}
void patternZ(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i+j==n-1);
}
// Numbers functions
void pattern0(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||j==0||j==n-1||(i==j&&i>=n/2));
}
void pattern1(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==n/2||i==n-1||i==0&&j==n/2);
}
void pattern2(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i==n/2||i<n/2&&j==n-1||i>n/2&&j==0);
}
void pattern3(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i==n/2||j==n-1);
}
void pattern4(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(j==n-1||i==n/2||j==0&&i<n/2);
}
void pattern5(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i==n/2||i<n/2&&j==0||i>n/2&&j==n-1);
}
void pattern6(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i==n/2||j==0||i>n/2&&j==n-1);
}
void pattern7(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||j==n-1-i);
}
void pattern8(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n-1||i==n/2||j==0||j==n-1);
}
void pattern9(int n, int arr[n][2*n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=(i==0||i==n/2||i==n-1||j==n-1||i<n/2&&j==0);
}
// Function caller
int getPattern(char ch, int n, int arr[n][2*n]){
    memset(arr, 0, sizeof(int)*n*2*n);
    ch = toupper(ch);
    switch(ch){
        case 'A': 
            patternA(n, arr); 
            return n;
        case 'B': 
            patternB(n, arr); 
            return n;
        case 'C': 
            patternC(n, arr); 
            return n;
        case 'D': 
            patternD(n, arr); 
            return n;
        case 'E': 
            patternE(n, arr); 
            return n;
        case 'F': 
            patternF(n, arr); 
            return n;
        case 'G': 
            patternG(n, arr); 
            return n;
        case 'H': 
            patternH(n, arr); 
            return n;
        case 'I': 
            patternI(n, arr); 
            return n;
        case 'J': 
            patternJ(n, arr); 
            return n;
        case 'K': 
            patternK(n, arr); 
            return n;
        case 'L': 
            patternL(n, arr); 
            return n;
        case 'M': 
            patternM(n, arr); 
            return n;
        case 'N': 
            patternN(n, arr); 
            return n;
        case 'O': 
            patternO(n, arr); 
            return n;
        case 'P': 
            patternP(n, arr); 
            return n;
        case 'Q': 
            patternQ(n, arr); 
            return n;
        case 'R': 
            patternR(n, arr); 
            return n;
        case 'S': 
            patternS(n, arr); 
            return n;
        case 'T': 
            patternT(n, arr); 
            return n;
        case 'U': 
            patternU(n, arr); 
            return n;
        case 'V': 
            patternV(n, arr); 
            return 2*n-1;
        case 'W': 
            patternW(n, arr); 
            return n;
        case 'X': 
            patternX(n, arr); 
            return n;
        case 'Y': 
            patternY(n, arr); 
            return n;
        case 'Z': 
            patternZ(n, arr); 
            return n;

        case '0': 
            pattern0(n, arr); 
            return n;
        case '1': 
            pattern1(n, arr); 
            return n;
        case '2': 
            pattern2(n, arr); 
            return n;
        case '3': 
            pattern3(n, arr); 
            return n;
        case '4': 
            pattern4(n, arr); 
            return n;
        case '5': 
            pattern5(n, arr); 
            return n;
        case '6': 
            pattern6(n, arr); 
            return n;
        case '7': 
            pattern7(n, arr); 
            return n;
        case '8': 
            pattern8(n, arr); 
            return n;
        case '9': 
            pattern9(n, arr); 
            return n;
        default: 
            return 0;
    }
}

// MAIN PROGRAM
int main(){
    char again;
    do {
        char text[100], dir;
        int size;
        printf("Enter any word or line or letter (A-Z, 0-9): ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        printf("Enter size of pattern to be printed (recommended 5-7): ");
        scanf("%d", &size);
        printf("Which MODE (H for Horizontally or V for Vertically [H/V]): ");
        scanf(" %c", &dir);

        if(toupper(dir)=='V'){
            for(int i=0;text[i];i++){
                if(text[i]==' ') continue;
                int arr[size][2*size];
                int width=getPattern(text[i], size, arr);
                if(!width) continue;
                for(int r=0;r<size;r++){
                    for(int c=0;c<width;c++)
                        printf("%c", arr[r][c]?'*':' ');
                    printf("\n");
                }
                printf("\n");
            }
        } else {
            int len=strlen(text);
            int widths[len];
            int patterns[len][size][2*size];
            for(int i=0;i<len;i++){
                if(text[i]==' '){
                    widths[i]=2;
                    memset(patterns[i],0,sizeof(patterns[i]));
                    continue;
                }
                widths[i]=getPattern(text[i], size, patterns[i]);
            }
            for(int r=0;r<size;r++){
                for(int i=0;i<len;i++){
                    if(text[i]==' '){ printf("   "); continue; }
                    for(int c=0;c<widths[i];c++)
                        printf("%c", patterns[i][r][c]?'*':' ');
                    printf("   ");
                }
                printf("\n");
            }
        }

        printf("\nDo you want to print another pattern? (Y/N): ");
        scanf(" %c", &again);
        getchar(); 

    } while(toupper(again) == 'Y');
    printf("\nTHANK YOU!!\n");
    return 0;
}
// PROGRAM END