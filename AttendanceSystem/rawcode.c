// ATTENDANCE MANAGEMENT SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// structure definitions
// Student structure
struct student{
    int studentID;
    char name[50];
    int totaldays;
    int presentdays;
};
// Class structure
struct class{
    int classID;
    char classname[50];
    int totalstudents;
    struct student* students;
};
// School structure
struct school{
    int schoolID;
    char schoolname[50];
    int totalclasses;
    struct class *classes;
};
// District structure
struct district{
    int districtID;
    char districtname[50];
    int totalschools;
    struct school *schools;
};
// State structure
struct state{
    int stateID;
    char statename[50];
    int totaldistricts;
    struct district *districts;
};
// Function prototypes
void adddata(struct state *state);
void viewdata(struct state *state);
void markattendance(struct state *state);
void viewreport(struct state *state);
void searchstudent(struct state *state);
void freeMemory(struct state *state);
// Main function
int main(){
    struct state mystate;
    mystate.stateID = 1;
    printf("Enter State Name: ");
    fgets(mystate.statename, sizeof(mystate.statename), stdin);
    mystate.statename[strcspn(mystate.statename, "\n")] = 0; // remove newline
    mystate.totaldistricts = 0;
    mystate.districts = NULL;
    int ch;
    while(1){
        printf("\nATTENDANCE MANAGEMENT SYSTEM\n");
        printf("1. Add Data\n");
        printf("2. View Data\n");
        printf("3. Mark Attendance\n");
        printf("4. View Report\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // to consume newline character
        switch(ch){
            case 1:
                adddata(&mystate);
                break;
            case 2:
                viewdata(&mystate);
                break;
            case 3:
                markattendance(&mystate);
                break;
            case 4:
                viewreport(&mystate);
                break;
            case 5:
                searchstudent(&mystate);
                break;
            case 6:
                freeMemory(&mystate);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
// Function to add data
void adddata(struct state *state){
    int numDistricts;
    printf("Enter number of districts to add: ");
    scanf("%d", &numDistricts);
    getchar(); // consume newline
}