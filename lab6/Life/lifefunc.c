//Xavier Briggs
//lifefunc.c
//03/08/24

#include "lifefunc.h"
//Interactive file mode function that reads data from a file
void interactive_modeFile(char old_board [][BSIZE], char new_board [][BSIZE], FILE* userFile){
    char choice;
    int x, y;
    //Gets a blank board
    get_initialboard(old_board);
    //While loop that runs while the end of the file hasn't been reached
    while(!feof(userFile)){
   	 //scans choice and (x,y) from file
   	 fscanf(userFile, "%c", &choice);
   	 fscanf(userFile, "%d%d", &x,&y);
   	 //if statments that determines choice from file, if a adds an x at the (x,y), if r is read removes X, if p is read runs game rules infinitly
   	 if(choice == 'a'){
    	 old_board [y][x] = 'X';
    	 get_newboard(old_board);
    }
   	 if(choice == 'r'){
    	 old_board [y][x] = ' ';
    	 get_newboard(old_board);
    }
    if(choice == 'p'){
        //endless loop that calls the life_iteration function to iterate the game board based on game rules
        while(1){
       	 life_iteration(old_board, new_board);
         for(int i = 0; i<BSIZE; i++){
             for(int j = 0; j<BSIZE; j++){
                 old_board [i][j] = new_board [i][j];
             }
         }
    //prints new board, pauses, then clears
    		get_newboard(new_board);
    		usleep(100000);
   		  system("clear");
    }
    }

    }       
}
//Interactive mode that takes in user input from the keyboard
void interactive_mode(char old_board [][BSIZE], char new_board [][BSIZE]){
    char choice;
    int x, y;
    //gets blank board
    get_initialboard(old_board);
    //while loop that runs while user input is not q
    while(choice != 'q'){
    	printf("Command: \n");
    	scanf(" %c", &choice);
    if(choice == 'q'){
        printf("Goodbye!\n");
        break; 
    }
    //if statment that calls life_iteration one time if user inputs n
    if(choice == 'n'){
			life_iteration(old_board, new_board);
			for(int i = 0; i<BSIZE; i++){
             for(int j = 0; j<BSIZE; j++){
                 old_board [i][j] = new_board [i][j];
             }
         }	
			get_newboard(new_board);
		}
    //if statment that prompts user for (x, y) and then adds an X at that index
    if(choice == 'a'){
    	scanf("%d%d", &x,&y);
      old_board [y][x] = 'X';
      get_newboard(old_board);
    }
    //if statment that prompts user for (x, y) and then adds an ' ' at that index
    if(choice == 'r'){
    	scanf("%d%d", &x,&y);
      old_board [y][x] = ' ';
      get_newboard(old_board);
    }
    //If user inputs p creates endless loop that calls life_iteration applying the rules of the game
    if(choice == 'p'){
       while(1){
        life_iteration(old_board, new_board);
         for(int i = 0; i<BSIZE; i++){
             for(int j = 0; j<BSIZE; j++){
                 old_board [i][j] = new_board [i][j];
             }
         }
    //same functions as interactive file mode
   		 get_newboard(new_board);
   		 usleep(100000);
   		 system("clear");
    }
    }
    

}
}
//Initial board function to initialize the starting array with all spaces
void get_initialboard(char old_board[][BSIZE]){
    //Top of border
    for(int i = 0; i<BSIZE; i++){
        printf("_");
    }
    for (int i = 0; i<BSIZE; i++){
        //fix border format!!
        //Right Border
       if(i!= 0){
        printf("|");
       }
        for(int j = 0; j<BSIZE; j++){
            old_board [i] [j] = ' ';
            //Prints new line and left border
            if(j % BSIZE == 0){ 
                printf("\n"); 
                printf("|");
                }
            printf("%c", old_board[i][j]);
        }
    }
    printf("|\n");
    //Bottom Border
    for(int i = 0; i<BSIZE; i++){
        printf("_");
    }
    printf("\n");

} 
//Function to print the called array when it is updated
void get_newboard(char old_board [][BSIZE]){
     for(int i = 0; i<BSIZE; i++){
        printf("_");
    }
    for (int i = 0; i<BSIZE; i++){
        //fix border format!!
        //Right Border
       if(i!= 0){
        printf("|");
       }
        for(int j = 0; j<BSIZE; j++){
            //Prints new line and left border
            if(j % BSIZE == 0){ 
                printf("\n"); 
                printf("|");
                }
            printf("%c", old_board[i][j]);
        }
    }
    printf("|\n");
    //Bottom Border
    for(int i = 0; i<BSIZE; i++){
        printf("_");
    }
    printf("\n");

}
//life_iteration function to apply the rules of the game and make changes to new array if the condition is met
void life_iteration(char old_board [][BSIZE], char new_board[][BSIZE]){
    int count;
    for(int i = 0; i<BSIZE; i++){
        for(int j = 0; j<BSIZE; j++){
            //calls game rules function to get value of count which applys to how many alive cells are around at the index [i][j]
            int count = game_rules(old_board,j,i);
            //if count = 3 then there are three alive cells next to a cell causing it to become alive
            if(count == 3){
                new_board[i][j] = 'X';
            }
            //if the cell is alive and there are 2 or 3 cells alive next to it the cell stays alive
            else if((old_board[i][j]=='X')&& (count == 2 || count == 3)){
                new_board [i][j] = 'X';
            }
            //everything else dies
            else{
                new_board[i][j] = ' ';
            }
        }
    }
}

//Game rules function that checks if there is an alive cell to the top, top right and left, right, left, and bottom, bottom left and right. returns count iow amount of cells alive next to it.
int game_rules(char old_board [][BSIZE], int j, int i){
        int count = 0; 
    //if statment to check if index is at the left edge of boundry of the board
     if(j == 0){
        //top
        if(old_board[i-1][j]=='X'){
            count++;
           }
           //top right
            if(old_board[i-1][j+1]=='X'){
           	 count++;
           }
        //right cell check
            if(old_board[i][j+1]=='X'){
           	 count++;
           }
           //Bottom check
           if(old_board[i+1][j] == 'X'){
            count++;
           }
           //bottom right
            if(old_board[i+1][j+1]=='X'){
           	 count++;
           }
           return count;
     }
     //else if statment to check if index is at the right edge of boundry of the board
     else if (j == BSIZE-1){
         //top check
           if(old_board[i-1][j]=='X'){
           	 count++;
           }
           //top left
            if(old_board[i-1][j-1]=='X'){
           	 count++;
           }
           //left cell check
            if(old_board[i][j-1]=='X'){
            	count++;
           }
           //Bottom check
           if(old_board[i+1][j] == 'X'){
            count++;
           }
           //bottom left
             if(old_board[i+1][j-1]=='X'){
           	 count++;
           }
           return count; 
     }
     //everything else is in the middle
     else{
    //upper bound check
            //top check
           if(old_board[i-1][j]=='X'){
            count++;
           }
           //top right
            if(old_board[i-1][j+1]=='X'){
            count++;
           }
           //top left
            if(old_board[i-1][j-1]=='X'){
            count++;
           }
           //right cell check
            if(old_board[i][j+1]=='X'){
            count++;
           }
           //left cell check
            if(old_board[i][j-1]=='X'){
            count++;
           }
           //Bottom check
           if(old_board[i+1][j] == 'X'){
            count++;
           }
           //bottom right
            if(old_board[i+1][j+1]=='X'){
            count++;
           }
           //bottom left
             if(old_board[i+1][j-1]=='X'){
            count++;
           }
           return count; 
     }
}
