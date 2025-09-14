

#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            printf("*  ");
        }
        printf("\n");
    }
    return 0;
}

//right angle triangle(upper)

/*
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            printf("*  ");
        }
        printf("\n");
    }
    return 0;
}
*/