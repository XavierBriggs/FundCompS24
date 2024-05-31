//Xavier Briggs
//statesfunc.c
//March 25, 2024

#include "statesfunc.h"

//Menu Function
void display_menu(States states_arr [], int choice, int count){
   int index, index2,index3, year;
    char abc;
    printf("Hello, Welcome to the US States informational tool!\n");
    printf("Enter your choice\n");

    //While loop that displays the menu until the exit choice is selected
    while(choice != 5){
        printf("1) List a state's info based on its abbreviation\n");
        printf("2) list a state's capital based on its name\n");
        printf("3) List the states' info starting from a desired place in the alaphabet\n");
        printf("4) List the first state that joined the union in a desired year\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        if(choice == 5) break;
        if(choice == 1){

            //Gets index of the desired state the user wants and then display
            int index = get_abrInfo(states_arr, count);
            display_state(states_arr, index);
        }
        else if(choice == 2){

            //Gets index of the desired capital user wants and then displays
            int index2 = get_capInfo(states_arr, count);
            display_capital(states_arr, index2);
    }
         else if (choice == 3){

            //Prompts user to enter the letter they would like to start at and displays the states after that letter
             printf("Enter your letter: ");
             scanf(" %c", &abc);
            display_allstates(states_arr, count, abc);

    }
        else if(choice == 4){

            //Ask user for desired year and outputs the first state that joined during that year
            printf("Enter your year: ");
            scanf(" %d", &year);
            display_years(states_arr, year, count);
            
        
        }
        else{
            printf("your input is invalid try again\n");
        }

    }
    
    //Exit statement
    printf("GoodBye!\n");
}

//Read File function
int read_file(FILE *fp, States arr[]){
    int count = 0;
    char theline[60];

    //Infinite loop to run until the end of the file is reached
    while (1)
    {
        //Gets a string from the file and then parses it using strtok with ',' as the delimitter
        fgets(theline, 60, fp);
        if (feof(fp)) break;
        strcpy(arr[count].abbreviation, strtok(theline, ","));
        strcpy(arr[count].name, strtok(NULL, ","));
        strcpy(arr[count].capital, strtok(NULL, ","));
        arr[count].year = atoi(strtok(NULL, "\n"));
        count++;
    }

    //Returns count
    return count;
}

//Choice One Functions
void display_state(States arr[], int index){
    if(index != -1){
    printf("Here is your state info\n");
    printf("State Name: %s\n", arr[index].name); 
    printf("State Abbreviation: %s\n", arr[index].abbreviation);
    printf("State Capital: %s\n", arr[index].capital);
    printf("Year State Joined Union: %d\n", arr[index].year);
    }
    else{
        printf("Your state can not be found\n");
    }

}
int get_abrInfo(States arr[], int size){
    char userIn [3];
    printf("Enter your state abbreviation: ");
    scanf(" %s", &userIn);
    //Makes user inputed case insentive 
    userIn[0] = toupper(userIn[0]);
    userIn[1] = toupper(userIn[1]);
    for(int i = 0; i<size; i++){

        //Checks to see if the user input matches the state abbrevition if it does returns I wich is the index of that state
        if(strstr(arr[i].abbreviation, userIn) != NULL){
            return i;
        }

    }
        //Returns -1 if nothing is found
            return -1;
        

    

}

//Choice Two Functions 
void display_capital(States arr[], int index){
    if(index != -1){
    printf("\nHere is your state capital\n");
    printf("State Capital: %s\n\n", arr[index].capital);
    }
    else{
        printf("Your input is invalid\n");
    }
   
}


int get_capInfo(States arr[], int size){
    char userIn [14];
    printf("Enter your state name: ");
    scanf(" %s", &userIn);

    //Makes userinput caseinsentive
    userIn[0] = toupper(userIn[0]);
    for(int i = 1; i<strlen(userIn)-2; i++){
        userIn[i] = tolower(userIn[i]);
    }

    for(int i = 0; i<size; i++){

        //same logic as if statement in get abrv
        if(strstr(arr[i].name, userIn) != NULL){
            return i;
        }
    }

    //Returns -1 if nothing is found
    return -1;
    
}

//Choice Three Functions
void display_allstates(States arr[], int size, char abc){
    printf("\nHere are the states starting from '%c'\n", abc);
    abc = toupper(abc);
    display_header();
    for(int i = 0; i<size; i++){

        //Prints the state info of states after the desired user character
        if(arr[i].abbreviation[0] >= abc){
          printf("%2s     %15s     %15s     %4d\n", arr[i].abbreviation, arr[i].name, arr[i].capital, arr[i].year);
        }
    }
}

//Choice 4 Functions 
int get_yearIndex(States arr[], int year, int size){
    for(int i = 0; i<size; i++){

        //Checks to see if the states year matches the user state if true returns i
        if(arr[i].year == year){
            return i;
        }
    }
    
    //returns negative 1 if no state joined during the user year
    return -1;
}

void display_years(States arr[], int year, int size){
    int yearIndex;
    int prevIndex;
    for(int i = 0; i<size; i++){
        yearIndex = get_yearIndex(arr, year, size);

        //If statment to check input is correct
        if(yearIndex == -1){
            printf("No state Joined during this year, try again\n");
            break;
        }

        //Checks to stop printing after the first state is found
        if(yearIndex != prevIndex){
        printf("Abr: %s\nName: %s\nCapital: %s\nYear: %d\n", arr[yearIndex].abbreviation, arr[yearIndex].name, arr[yearIndex].capital, arr[yearIndex].year);
        prevIndex = yearIndex;
        }
        else {
            break;
        }
    }

}


//function to display the header of states info
void display_header(){
    printf("Abbreviation    Name             Capital       Year\n");
    printf("_____________________________________________________\n");
}