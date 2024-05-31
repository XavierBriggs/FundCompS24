//Xavier Briggs
//lifefunc.h
//03/08/24
//Includes c librarys
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
//defines size of game board
#define BSIZE 40 
//Interactive mode function that prompts user input
void interactive_mode(char old_board [][BSIZE], char new_board [][BSIZE]);
//Program's interactive file mode
void interactive_modeFile(char old_board [][BSIZE], char new_board [] [BSIZE], FILE* userFile);
//Initializes the old_board array with all spaces
void get_initialboard(char old_board[][BSIZE]);
//Prints new board
void get_newboard(char old_board [][BSIZE]);
//Applys the rules of the game
void life_iteration(char old_board [][BSIZE], char new_board [][BSIZE]);
//game rule function to calculate amount of adjacent cells alive
int game_rules(char old_board [][BSIZE], int j, int i);