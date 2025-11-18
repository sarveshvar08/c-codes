#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    start:
    srand(time(NULL));
    int a,guess=0,tries=0;
    int min=10,max=100;
    int ans=(rand()%(max-min+1))+min;
    printf("Number Guessing Game\n");
    do{
        printf("Enter your guess between %d and %d: ",min+1,max+1);
        scanf("%d",&guess);
        tries++;
        if(guess>ans){
            printf("Too High!\n");
            max=guess-1;
        }
        else if(guess<ans){
            printf("Too Low!\n");
            min=guess+1;
        }
        else{
            printf("\nCongratulations! You guessed the number %d in %d tries.\n",ans,tries);
        }
    }while(guess!=ans);
    printf("Do you want to play again? (1 for Yes / 0 for No): ");
    scanf("%d",&a);
    if(a==1){
        goto start;
    }
    else{
        printf("Thank you for playing!\n");
    }
    return 0;
}

