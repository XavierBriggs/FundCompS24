//Xavier Briggs
//statesfunc.h
//March 25, 2024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
//Max Number of States
#define MAX_STATES 100

//States Structure
typedef struct{
    char abbreviation [3];
    char name [20];
    char capital [20];
    int year; 
} States; 

//Read and Display function
int read_file(FILE* fp, States arr[]);
void display_menu(States states_arr[], int choice, int size);
void display_header();

//Choice one functions
int get_abrInfo(States arr[], int size);
void display_state(States arr[], int index);

//Choice two functions
void display_capital(States arr[], int index);
int get_capInfo(States arr[], int size);

//Choice three functions
void display_allstates(States arr[], int size, char abc);

//Choice four functions
int get_yearIndex(States arr[], int year, int size);
void display_years(States arr[], int year, int size);