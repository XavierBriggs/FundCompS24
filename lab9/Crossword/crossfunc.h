//Xavier Briggs
//Crossfunc.h
//April 21, 2024


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define _GNU_SOURCE
#define WRDSIZE 15
#define MAXWRD 20
#define MAXOVERLAP 100

//Struct to hold the x and y position as well as if it has been placed of each word.  
typedef struct {
    int x;
    int y;
    bool placed;
    bool skip;
    int strlen;
    bool isDown; 
    char wrd[WRDSIZE];
    char anagram[WRDSIZE];
} CompleteWRD; 

//Board Functions
void get_solutionBoard(char solution_board[][WRDSIZE]);
void get_puzzleBoard(char puzzle_board [][WRDSIZE]);
void get_newpuzzleboard(char solution_board [] [WRDSIZE], char puzzle_board [] [WRDSIZE]);
void get_newboard(char old_board [][WRDSIZE]);
//____________________


//Three Modes
int interactiveMode(char words[][WRDSIZE]);
int readFile(FILE *fp, char words[][WRDSIZE]);
void writeTofile(FILE *fpw, char solution_board [][WRDSIZE], char puzzle_board [][WRDSIZE], CompleteWRD wrdSrtd [], int size, CompleteWRD rejectwrds [], int reject_wrds);
//__________________

//Word Store Functions
void strSort(char words[][WRDSIZE], int size, CompleteWRD wordSrtd []);
int maxIndex(char words[][WRDSIZE], int size);
void strUpper(char str[WRDSIZE]);
int checkword(char temp[]);
//___________________________


//Placing words Functions
void placeLoop(CompleteWRD wrdSrt[], int size, CompleteWRD rejectWrds[], int*reject_size, char solution_board[][WRDSIZE], char puzzle_board[][WRDSIZE]);
void initialPlaced(CompleteWRD wrdSrt[], int size);
void place_word(char word[], char solution_board[WRDSIZE][WRDSIZE], bool down, int X, int Y);
void placeRejectWrds(CompleteWRD wrdSrt [], CompleteWRD rejectWrds [], int reject_size, int wrdSrt_size, char solution_board [][WRDSIZE]);
bool CheckPlacement(char word[], char board[WRDSIZE][WRDSIZE], int down, int cordX, int cordY, int len);
//_________________________________


//display Clues
void displayWrd(char wrdSrt [][WRDSIZE], int size);
char *get_anagram(char anagram[WRDSIZE]);
void get_anagramArr(CompleteWRD wrdSrtd [],  int size);
char *strfry(char *string);
void displayClues(CompleteWRD wrdSrtd[], int size, CompleteWRD rejectWrds [], int reject_size);
//______________________