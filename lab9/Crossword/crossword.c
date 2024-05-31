//Xavier Briggs
//Crossword.c
//April 21, 2024


#include "crossfunc.h"

int main (int argc, char*argv[]){

    //Boards
    char solution_board [WRDSIZE] [WRDSIZE];
    char puzzle_board [WRDSIZE] [WRDSIZE];

    //FileNames
    char fileName [WRDSIZE];
    FILE* fp;

    char fileNameR [WRDSIZE];
    FILE* fpR;
    
    char fileNameW [WRDSIZE];
    FILE* fpW;

    //unsorted array of strings
    char words [MAXWRD][WRDSIZE];

    //Fully complete words that are sorted
    CompleteWRD  wordSrtd [MAXWRD];

    //Rejected words that can't be placed on first attempt
    CompleteWRD rejectWrds [MAXWRD];
    int reject_size = 0;
    int size;
     

    //Initialize Boards
    get_solutionBoard(solution_board);
    get_puzzleBoard(puzzle_board);

    //InteractiveMode Starts
    if(argc == 1){
         size = interactiveMode(words); //gets amount of words entered and starts interactive mode

        //checks if atleast one word has been entered
        if(size > 0){
        strSort(words,size, wordSrtd); //sorts the words inputed
        placeLoop(wordSrtd, size,rejectWrds, &reject_size, solution_board, puzzle_board); //places words on board and prints output 
        }
        else{
            printf("Zero Words Entered");
        }
        printf("\n");
    }

    //FileMode starts
    else if(argc == 2){
        strcpy(fileName, argv[1]);
        fp = fopen(fileName, "r");

        //invalid file name check
        if(fp == NULL){ 
            printf("Invalid file name at cmd line, try again\n"); 
        }
        else if(fp != NULL){
             size = readFile(fp, words);

            if(size == -1 || size < 0){
                 printf("Error in file\n");//error in file 
            }
            else{
            strSort(words,size, wordSrtd);
            placeLoop(wordSrtd, size, rejectWrds, &reject_size, solution_board, puzzle_board);
            }
            fclose(fp);
        }
        
    }
    else if(argc == 3){

            strcpy(fileNameR, argv[1]); //Gets file to read from arg1
            strcpy(fileNameW, argv[2]); //Gets file to write from arg2

            //Attempts to open both
            fpR = fopen(fileNameR, "r");
            fpW = fopen(fileNameW, "w");
            if(fpR == NULL){ 
                printf("Invalid file name at cmd line argument 2\n");
            }
            else if(fpR != NULL){

                int size = readFile(fpR, words); //gets total number of words and starts readFile mode

                //if error in file or no words prints error
                if(size == -1 || size < 0){
                 printf("Error in file\n");
                }
                else{
                strSort(words,size, wordSrtd); //then sorts words
                placeLoop(wordSrtd, size, rejectWrds, &reject_size, solution_board, puzzle_board); //then places all words possible and prints output
                writeTofile(fpW, solution_board,puzzle_board, wordSrtd, size, rejectWrds, reject_size);//writes this output to file
                }
               
                //Close both file pointers
                fclose(fpW); 
                fclose(fpR);
        }
    
    }
    else{
        printf("To many cmd line arguments, try again\n");
    }
    
}