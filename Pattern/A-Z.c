
#include <stdio.h>
int main(){
    char ch;
    printf("Enter a character[A,C,I]: ");
    scanf("%c",&ch);
    // Pattern for A
    if(ch=='A'){
    int n;
    printf("Enter the EVEN number: ");
    scanf("%d", &n);
    for (int i =1; i <=n; i++) {
        // spaces
        for (int s = 1; s <= n - i; s++) {
            printf("  ");
        }
        // stars
        for (int j = 1; j <=(2*i - 1); j++) {
            // hollow part,center line.
            if(j==1 || j==(2*i-1) || i==n/2+1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    }
    // Pattern for C
    else if(ch=='C'){
        int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // 1 ROW,1 COLUMN AND LAST ROW
            if(j==0 || i==0 || i==n-1){
                printf("*  ");
            }
            else{
                printf("   ");
            }
        }

        printf("\n");
    }
    }
    // Pattern for I
    else if(ch=='I'){
        int n;
    printf("Enter a odd number: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // 1 ROW, CENTER COLUMN,LAST ROW.
           if(i==0 || j==n/2 || i==n-1 ){
                printf("*  ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    }
    else if(ch=='X'){
        int n;
        printf("Enter the number of rows: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || i+j==n-1){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    else{
        printf("Invalid character.");
    }
       

    return 0;
}