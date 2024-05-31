//Xavier Briggs
//usastates.c
//March 25, 2024


#include "statesfunc.h"

int main(){

    //Declare an arrary of structs to hold state info
    States states_arr [MAX_STATES];
    bool isNull = true;

    char userFile[20];
    FILE* fp;

    //Prompts user for name of file they would like to be read
    while(isNull == true){
        printf("Enter your file name: ");
        scanf(" %s", userFile);
        fp = fopen(userFile, "r");
        if(!fp){
            printf("Your input is invalid try again\n");
            isNull = true; 
        }
        if(fp){
            isNull = false;
             break;
     }
    }
   
   //counts the number of states
    int count = read_file(fp, states_arr);

    //Initialize the choice as 1 to start loop
    int choice = 1;
    display_menu(states_arr, choice, count);


}
