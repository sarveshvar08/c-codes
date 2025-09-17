#include<stdio.h>
int main(){
    char a[3][3]={'\0'},b[3][3]={'\0'};
    for (int i=1;i<=3;i++){
        for (int j=1;j<=3;j++){
            
            printf("Enter X or O for position %d,%d: ",i,j);
            scanf("%c",&a[i][j]);
            if(a[i][j]=="X" || a[i][j]=="O"){
                b[i][j]=a[i][j];
            }
            else{
                printf("Enter X or O only\n");
                
            }
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf(" %c |",b[i][j]);
        }
        printf("\n------------\n");
    }
    return 0;
}


//++a=1+a;
//a++=a+1