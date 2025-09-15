#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int a;
    while(1){
        printf("Rock, Paper, Scissors Game\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        printf("\n");
        if(a<1 || a>3){
            break;
        }
        else{
            //Create a random number.
            srand(time(NULL));
            int min=1,max=3;
            //Reduce the range of random number between min to max.
            int ans=(rand()%(max-min+1))+min;
            //ans==1-->rock
            //ans==2-->paper
            //ans==3-->scissors

            //If both user and computer choose the same option.
            if(a==ans){
                printf("It is a Tie!\n");
            }
            //Winning conditions for user.
            else if(a==1 && ans!=2){
                printf("You Win! Rock crushes Scissors.\n");
            }
            else if(a==2 && ans!=3){
                printf("You Win! Paper covers Rock.\n");
            }
            else if(a==3 && ans!=1){
                printf("You Win! Scissors cut Paper.\n");
            }
            //Losing conditions for user.
            else{
                if(a==3 && ans==1){
                    printf("You Lose! Rock crushes Scissors.\n");
                }
                else if(a==1 && ans==2){
                    printf("You Lose! Paper covers Rock.\n");
                }
                else{
                    printf("You Lose! Scissors cut Paper.\n");
                }
            }
        }
    }   
    return 0;
}
