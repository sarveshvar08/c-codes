#include<stdio.h>
void patternA(){
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
void patternC(){
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
void patternI(){
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
void patternX(){
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
void hollow_square(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                printf("*  ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}
void pyramid(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i =1; i <=n; i++) {
        // spaces
        for (int s = 1; s <= n - i; s++) {
            printf("  ");
        }
        // stars
        for (int j = 1; j <=(2*i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
}
void rightTriangle(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            printf("*  ");
        }
        printf("\n");
    }
}
void invertedPyramid(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i =n; i >=1; i--) {
        // spaces
        for (int s = 1; s <= n - i; s++) {
            printf("  ");
        }
        // stars
        for (int j = 1; j <=(2*i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
}
int main(){
    start:
    int choice;
    printf("Choose the pattern you want to print:\n");
    printf("1. Pattern A\n");
    printf("2. Pattern C\n");
    printf("3. Pattern I\n");
    printf("4. Pattern X\n");
    printf("5. Hollow Square\n");
    printf("6. Pyramid\n");
    printf("7. Right Triangle\n");
    printf("8. Inverted Pyramid\n");
    printf("0. Exit\n");
    printf("Enter your choice (1-8): ");
    scanf("%d",&choice);
    switch(choice){
        case 0:
            break;
        case 1:
            patternA();
            break;
        case 2:
            patternC();
            break;
        case 3:
            patternI();
            break;
        case 4:
            patternX();
            break;
        case 5:
            hollow_square();
            break;
        case 6:
            pyramid();
            break;
        case 7:
            rightTriangle();
            break;
        case 8:
            invertedPyramid();
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 8.\n");
    }
    goto start;
    return 0;
}

