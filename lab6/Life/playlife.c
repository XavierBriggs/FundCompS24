//Xavier Briggs
//playlife.c
//03/08/24

#include "lifefunc.h"
int main(int argc, char *argv[]){
    //Initialize's two char arrays for the game board
      //old board that is getting checked
     char old_board [BSIZE][BSIZE];
     //new board that changes are being made to
     char new_board [BSIZE] [BSIZE];
     FILE* userFile;
     bool isNull = true; 

  //if command line input is equal to one then calls interactive mode function
    if((argc == 1))interactive_mode(old_board, new_board);
  //if cl input is equal to 2 calls interactive file mode
    if(argc == 2){
	    userFile = fopen(argv[1], "r");
	    if(!userFile){
			    printf("Your input is invalid\n");
		  }
      else{
      interactive_modeFile(old_board,new_board, userFile);
      }
	}
  
    
    //if greater then 2 calls error
    if(argc > 2){
        printf("Your input is invalid\n");
    }
    

   return 0;
}