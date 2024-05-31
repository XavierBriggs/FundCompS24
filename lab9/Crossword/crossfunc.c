//Xavier Briggs
//Crossfunc.c
//April 21, 2024


#include "crossfunc.h"


//Boards
//GET Initial Boards
void get_solutionBoard(char solution_board[][WRDSIZE]){
    for (int i = 0; i<WRDSIZE; i++){
        for(int j = 0; j<WRDSIZE; j++){
            solution_board [i] [j] = '.';
        }
    }

} 
void get_puzzleBoard(char puzzle_board[][WRDSIZE]){
    for (int i = 0; i<WRDSIZE; i++){
        for(int j = 0; j<WRDSIZE; j++){
            puzzle_board [i] [j] = '#';
        }
    }
} 

//Prints populated board
void get_newboard(char old_board [][WRDSIZE]){

		printf(" ");
     for(int i = 0; i<WRDSIZE; i++){
        printf("_");
    }
    for (int i = 0; i<WRDSIZE; i++){
        //fix border format!!
        //Right Border
       if(i!= 0){
        printf("|");
       }
        for(int j = 0; j<WRDSIZE; j++){
            //Prints new line and left border
            if(j % WRDSIZE == 0){ 
                printf("\n"); 
                printf("|");
                }
            printf("%c", old_board[i][j]);
        }
    }
    printf("|\n ");
    //Bottom Border
    for(int i = 0; i<WRDSIZE; i++){
        printf("_");
    }
    printf("\n\n");

}

//Gets the puzzle board after solution board is filled
void get_newpuzzleboard(char solution_board [] [WRDSIZE], char puzzle_board [] [WRDSIZE]){
        for(int i = 0; i<WRDSIZE; i++){
                for(int j = 0; j<WRDSIZE; j++){
                    if(solution_board[i][j] != '.'){
                        puzzle_board [i][j] = ' ';
                    }
                }


        }





}
//__________________________________

//MODES

//Interactive Mode
int interactiveMode(char words[][WRDSIZE]){
    //accounts for longer then verifed length words
    char tempStr [WRDSIZE*2];
    int count = 0, wrdcheck;
    while(count < 20){
        printf("Enter a word: ");
        scanf("%s", tempStr);

        //converts string to uppercase
        strUpper(tempStr);

        //checks if word is a valid word before it is stored into the array
        wrdcheck = checkword(tempStr);
        if(wrdcheck == -1){
            printf("Try again\n");

            //subtracts one from count for every incorrect word
            count--;
        }
        else if (wrdcheck == 1){
            strcpy(words[count], tempStr); //if check passes store to array
           
        }

        //Breaks when a period is entered
        else if (wrdcheck == -2){
            break;
        }
        count++;
    }
    return count;

}
//Reads words from a file
int readFile(FILE *fp, char words[][WRDSIZE]){
    int count = 0, wrdcheck;
    char temp [WRDSIZE];
    while(count<20){
        if(count > 20) break;
        fscanf(fp, "%s", temp);
        if(feof(fp)) break;
        strUpper(temp);//converts to upper
        wrdcheck = checkword(temp);

        //Wrd Check failed in file 
        if(wrdcheck == -1){
            return-1;
        }
        //period breaks
        else if (wrdcheck == -2)break;

        //passes all checks copy temp to words array
        else{
            strcpy(words[count], temp);
        }
    count++;
    }
    return count;
}

//Writes solved board and puzzle to file
void writeTofile(FILE *fpw, char solution_board [][WRDSIZE], char puzzle_board [][WRDSIZE], CompleteWRD wrdSrtd [], int size, CompleteWRD rejectWrds[], int reject_size){

// Writing boards to file

    //Solution Board
    for(int i = 0; i<WRDSIZE; i++){
            fprintf(fpw, "%c", '_');
        }
        for (int i = 0; i<WRDSIZE; i++){
     
            //Right Border
        if(i!= 0){
            fprintf(fpw, "%s", "|");
        }
            for(int j = 0; j<WRDSIZE; j++){
                //Prints new line and left border
                if(j % WRDSIZE == 0){ 
                    fprintf(fpw, "%s", "\n"); 
                    fprintf(fpw, "%s", "|");
                    }
                fprintf(fpw, "%c", solution_board[i][j]);
            }
        }
        fprintf(fpw, "%s", "|\n");
        //Bottom Border
        for(int i = 0; i<WRDSIZE; i++){
            fprintf(fpw, "%s", "_");
        }

    fprintf(fpw, "%s","\n");


    //Puzzle Board
    for(int i = 0; i<WRDSIZE; i++){
            fprintf(fpw, "%c", '_');
        }
        for (int i = 0; i<WRDSIZE; i++){
            //fix border format!!
            //Right Border
        if(i!= 0){
            fprintf(fpw, "%s", "|");
        }
            for(int j = 0; j<WRDSIZE; j++){
                //Prints new line and left border
                if(j % WRDSIZE == 0){ 
                    fprintf(fpw, "%s", "\n"); 
                    fprintf(fpw, "%s", "|");
                    }
                fprintf(fpw, "%c", puzzle_board[i][j]);
            }
        }
        fprintf(fpw, "%s", "|\n");
        //Bottom Border
        for(int i = 0; i<WRDSIZE; i++){
            fprintf(fpw, "%s", "_");
        }

// Writing Clues to File
    fprintf(fpw, "\nClues: \n\n");
    fprintf(fpw, "Location|Direction|Anagram \n");
    fprintf(fpw, "________|_________|_______________\n");
    for (int i = 0; i < size; i++) {
        if (wrdSrtd[i].placed == true) {
            fprintf(fpw, "%3d, %3d| %s|  %4s\n", wrdSrtd[i].x, wrdSrtd[i].y, (wrdSrtd[i].isDown ? "DOWN    " : "ACROSS  "), wrdSrtd[i].anagram);
        }
    }
    for (int i = 0; i < reject_size; i++) {
        if (rejectWrds[i].placed == true) {
            fprintf(fpw, "%3d, %3d| %s|  %4s\n", rejectWrds[i].x, rejectWrds[i].y, (rejectWrds[i].isDown ? "DOWN    " : "ACROSS  "), rejectWrds[i].anagram);
        }
    }
    for(int i = 0; i<reject_size; i++){
        if((rejectWrds[i].placed == false)){
            fprintf(fpw, "Couldn't Place: %s\n",  rejectWrds[i].wrd);
        }
    }

printf("Your file has been written :)\n");
}


//Sorting Functions
//____________________________

//Converts string to uppercase
void strUpper(char str[WRDSIZE]){
    for(int i = 0; i<strlen(str); i++){
       str[i]=toupper(str[i]);
    }
}

//Checks if word is an acceptable word
int checkword(char temp[]){

    //loops until end of string
    for(int i = 0; i<strlen(temp); i++){


        //difference of a chracter to A to check if they were in the 0-26 range
        int difference = temp[i] -'A';

        //checks that each chracter of the string is one of the 26 letters in the abc
        if((difference <0 || difference >26) && difference != -19){
            return -1;
        }

        //if string is 1 or above 15 return error code returns -1 if true
        if(strlen(temp)>15) return -1;
        else if(strlen(temp) == 1 && difference == -19){
            return -2;
        }else if(strlen(temp) == 1) return -1;
        //checks if character is a . to end the input returns -2 if true
        else if (difference == -19){
            return -2;
        }
    }
    return 1;
}

int maxIndex(char words[][WRDSIZE], int size){
    int max = 0, index;
    for(int i = 0; i<size; i++){

        //checks if the length of a wrd is longer then the max value
        if(strlen(words[i]) > max){
        //stores the index of the largest word and then sets the max = to the length of the word at that index 
            index = i;
            max = strlen(words[i]);
        }

    }
    return index;
}

void strSort(char words[][WRDSIZE], int size, CompleteWRD wordSrtd []){
    int index, i2 = 0;
    //sorts unsorted words into a sorted array 
    for(int i = 0; i<size; i++){

        //gets index of the largest string in words array
        index = maxIndex(words, size);

        //copies the largest string in words arr to the first index of the wordSrt array 
        strcpy(wordSrtd[i].wrd, words[index]);
        wordSrtd[i].strlen = strlen(words[index]);
        //after the largest string is copied to sorted array makes it value zero
        strcpy(words[index], "0");
    }
}



//INDEXING FUNCTIONS
//______________________

void get_MultiIndex(char wrd1[], char wrd2[], int p1[], int p2[], int max)
{
    // max is the number of overlap positions to find
    int num_of_overlaps = 0;
    int n = 0;

    //Nested loop that checks the first char of a string to every letter in the second and saves that location
    while (1)
    {
        char c1 = wrd1[n];
        if (c1 == '\0')
            break;
        int m = 0;
        while (1)
        {
            char c2 = wrd2[m];
            if (c2 == '\0')
                break;

            if (c2 == c1)
            {
                p1[num_of_overlaps] = n;
                p2[num_of_overlaps] = m;
                num_of_overlaps++;
                if (num_of_overlaps == max)
                {
                    return;
                }
            }
            m++;
        }
        n++;
    }
    // If less than l overlap positions are found, fill remaining positions with -1
    for (int i = num_of_overlaps; i < max; i++)
    {
        p1[i] = -1;
        p2[i] = -1;
    }
}

//_______________________


//Placing Words on Board
//_________________________

//Place One Word Function
void place_word(char word[], char solution_board[WRDSIZE][WRDSIZE], bool down, int X, int Y)
{
    int count = 0;

    //loops and places a letter at each y or x
    for(int i = 0; i<strlen(word); i++)
    {
        char c = word[count];

        if (down == true){
            solution_board[Y + count][X] = c;
        }
        else{
            solution_board[Y][X+count] = c;
        }
        count++;
    }
}


//Main Loop that attempts to place words on the board
void placeLoop(CompleteWRD wrdSrt[], int size, CompleteWRD rejectWrds [], int *reject_size, char solution_board[][WRDSIZE], char puzzle_board[][WRDSIZE]) {

    initialPlaced(wrdSrt, size);
    int count = 0;

    //stores the location of overlaps for two words
    int p1[MAXOVERLAP], p2[MAXOVERLAP];

    //Priming board with first word
    int xstart = abs(strlen(wrdSrt[0].wrd)-WRDSIZE)/2;
    place_word(wrdSrt[0].wrd, solution_board, false,xstart, WRDSIZE/2);
    wrdSrt[0].x = xstart;
    wrdSrt[0].y = WRDSIZE/2;
    wrdSrt[0].isDown = false;
    wrdSrt[0].placed = true;
    //__________________________

     for (int i = 1; i < size; i++)
    {
        if (wrdSrt[i].placed)
            continue; // Skip already placed words
        //checks words directly above the target word
        for (int j = i - 1; j > -1; j--)
        {
            //gets location of overlaps between two words
            get_MultiIndex(wrdSrt[j].wrd, wrdSrt[i].wrd, p1, p2, MAXOVERLAP);


            for (int overlap = 0; overlap < MAXOVERLAP; overlap++)
            {
                // No more overlap positions, break
                if (p1[overlap] == -1) {
                    break;
                }
                int x_n, y_n;
                if (wrdSrt[j].isDown){
                    y_n = wrdSrt[j].y + p1[overlap];
                    x_n = wrdSrt[j].x - p2[overlap];
                }
                else{
                    y_n = wrdSrt[j].y - p2[overlap];
                    x_n = wrdSrt[j].x + p1[overlap];
                }

                //assigns the length of the string to strlen
                wrdSrt[i].strlen = strlen(wrdSrt[i].wrd);


                // Check if the placement is valid
                if(CheckPlacement(wrdSrt[i].wrd, solution_board, !wrdSrt[j].isDown, x_n, y_n, wrdSrt[i].strlen) && (wrdSrt[j].placed == true))
                {
                    // Place the word and mark it as placed
                    wrdSrt[i].x = x_n;
                    wrdSrt[i].y = y_n;
                    wrdSrt[i].placed = true;
                    wrdSrt[i].isDown = !wrdSrt[j].isDown;
                    place_word(wrdSrt[i].wrd, solution_board, wrdSrt[i].isDown, wrdSrt[i].x, wrdSrt[i].y);
                    break; // Exit the loop if a valid placement is found
                }  else{
                    wrdSrt[i].placed = false;
                }
            }

            if (wrdSrt[i].placed)
                break;
        }
    }

    //Loads the reject words array with the rejected wrdSrt array
    for(int i =0; i<size; i++){
        
        if(wrdSrt[i].placed == false){
            strcpy(rejectWrds[count].wrd, wrdSrt[i].wrd);
            rejectWrds[count].placed = false;
            rejectWrds[count].isDown = false;
            rejectWrds[count].strlen = strlen(rejectWrds[count].wrd); 
            count++;
        }
    }


    *reject_size = count; //saves the number of rejected words 
    
    //loops through solved board and places as many words that got passed the first time on board
    placeRejectWrds(wrdSrt, rejectWrds, count, size, solution_board);

    //Gets Boards
    get_newboard(solution_board);
    get_newpuzzleboard(solution_board, puzzle_board);
    get_newboard(puzzle_board);

    //Gets Clues
    get_anagramArr(wrdSrt, size);
    get_anagramArr(rejectWrds, count);
    displayClues(wrdSrt, size, rejectWrds, count);

 }


//Attempts to place words that were rejected at first
void placeRejectWrds(CompleteWRD wrdSrt [], CompleteWRD rejectWrds [], int reject_size, int wrdSrt_size, char solution_board [][WRDSIZE]){
    int p3[MAXOVERLAP], p4[MAXOVERLAP];
    for (int i = 0; i < reject_size; i++)
    {
        if (rejectWrds[i].placed)
            continue; // Skip already placed words
        for (int j = 0; j < wrdSrt_size; j++)
        {
            
            //gets overlap positions of the two words
            get_MultiIndex(wrdSrt[j].wrd, rejectWrds[i].wrd, p3, p4, MAXOVERLAP);


            for (int overlap = 0; overlap < MAXOVERLAP; overlap++)
            {   
                // No more overlap positions
                if (p3[overlap] == -1){
                    break;
                }
                int x_n, y_n;
                if (wrdSrt[j].isDown){
                    y_n = wrdSrt[j].y + p3[overlap];
                    x_n = wrdSrt[j].x - p4[overlap];
                }
                else{
                    y_n = wrdSrt[j].y - p4[overlap];
                    x_n = wrdSrt[j].x + p3[overlap];
                }

                // Check if the placement is valid
                if(CheckPlacement(rejectWrds[i].wrd, solution_board, !wrdSrt[j].isDown, x_n, y_n, rejectWrds[i].strlen) && (wrdSrt[j].placed == true)){
                    // Place the word and mark it as placed
                    rejectWrds[i].x = x_n;
                    rejectWrds[i].y = y_n;
                    rejectWrds[i].placed = true;
                    rejectWrds[i].isDown = !wrdSrt[j].isDown;
                    place_word(rejectWrds[i].wrd, solution_board, rejectWrds[i].isDown, rejectWrds[i].x, rejectWrds[i].y);
                    break; // Exit the loop if a valid placement is found
                }  else{
                    rejectWrds[i].placed = false;
                }

            }
            if (rejectWrds[i].placed)
                break;
        }
    }

    


}



 



//Sets the inital state of all words to not placed
void initialPlaced(CompleteWRD wrdSrt[], int size){
    for(int i = 0; i<size; i++){
        wrdSrt[i].placed = false;
    }
}

// Function to check if a word can be placed at the intended x, y coordinate
bool CheckPlacement(char word[], char solution_board[WRDSIZE][WRDSIZE], int down, int cordX, int cordY, int len)
{   
    //checks to seef if cell has a letter below, above, right, or left; difference = solution_board[cell_y][cell_x] - 'A';
    int difference = 0;

    //checks if they are same word
    bool isSame = true;

    int numIntersect;


    int n = 0, cell_x, cell_y;;
    for(int i = 0; i<strlen(word); i++)
    {
        //if word is down the starting x component is the x of the previous word and the y is incremented
        if (down)
        {
            cell_x = cordX;
            cell_y = cordY + n;
        }
        
        //opposite if word is accross
        else
        {
            cell_x = cordX + n;
            cell_y = cordY;
        }

        // Check if the cell is within the board boundaries
        if (cell_x < 0 || cell_x > WRDSIZE-1 || cell_y < 0 || cell_y > WRDSIZE-1){
            return false;
        }

        // Check for letter overriding a cell that already is written to
        if (solution_board[cell_y][cell_x] != '.' && word[n] != solution_board[cell_y][cell_x]){

            return false;
        }

        // Check for superwords or iow words connected to already existing words

        //Checks for a letter above the first letter in a word to see if there is already a word placed above
        difference = solution_board[cell_y-1][cell_x] - 'A';
        if ((solution_board[cell_y - 1][cell_x] != '.') && (down) && (n == 0) && (difference > 0 && difference < 26)) // up
        {
            return false;
        }

        //Checks for a letter below the last letter in a word to see if there is a letter below meaning invalid
        difference = solution_board[cell_y+1][cell_x] - 'A';
        if ((solution_board[cell_y + 1][cell_x]) != '.' && (down) && (n == len - 1) && (difference > 0 && difference < 26)) // down
        {
            return false;
        }

        //Checks the cell directly right for a letter
        difference = solution_board[cell_y][cell_x+1] - 'A';
        if ((solution_board[cell_y][cell_x + 1] != '.') && (!down) && (n == len - 1) && (difference > 0 && difference < 26)) // right
        {
            return false;
        }

        //Checks the cell directly left for a letter
        difference = solution_board[cell_y][cell_x-1] - 'A';
        if ((solution_board[cell_y][cell_x - 1] != '.') && (!down) && (n == 0) && (difference > 0 && difference < 26)) // left
        {
            return false;
        }

        // check for gen adj

        //Checks the cell directly up for a letter
        difference = solution_board[cell_y-1][cell_x] - 'A';
        if ((solution_board[cell_y - 1][cell_x] != '.') && (!down) && (word[n] != solution_board[cell_y][cell_x]) && (difference > 0 && difference < 26)) // up
        {
            return false;
        }
       
        //Checks the cell directly down for a letter
        difference = solution_board[cell_y+1][cell_x] - 'A';
        if ((solution_board[cell_y + 1][cell_x] != '.') && (!down) && (word[n] != solution_board[cell_y][cell_x]) && (difference > 0 && difference < 26)) // down
        {
            return false;
        }

        difference = solution_board[cell_y][cell_x+1] - 'A';

        //Checks the cell directly right for a letter
        if ((solution_board[cell_y][cell_x + 1] != '.') && (down) && (word[n] != solution_board[cell_y][cell_x]) && (difference > 0 && difference < 26)) // right
        {
            return false;
        }

        //Checks the cell directly left for a letter
        difference = solution_board[cell_y][cell_x-1] - 'A';
        if ((solution_board[cell_y][cell_x - 1] != '.') && (down) && (word[n] != solution_board[cell_y][cell_x]) && (difference > 0 && difference < 26)) // left
        {
            return false;
        }

        //checks if the word that is trying to print is the same as one that is already printed
        if(word[n] != solution_board[cell_y][cell_x]){
            isSame = false;
        }


        n++;
    }
    if(isSame) return false;
    return true;
}
//______________________________________


//Anagram Sort
void get_anagramArr(CompleteWRD wrdSrtd [],  int size){
    for(int i = 0; i<size; i++){

        //temp string
        char temp [WRDSIZE];
        //copies first wrd from sorted array to temp
        strcpy(temp, wrdSrtd[i].wrd);

        //gets anagram
        get_anagram(temp);
        strcpy(wrdSrtd[i].anagram, temp);
    }


}
//Prints the first letter of a word then last
char *get_anagram(char anagram [WRDSIZE])
{
    //randomize string using strfry function
    strfry(anagram);
    return anagram;
}
//_____________________________


//Gets x and y 
void displayClues(CompleteWRD wrdSrtd[], int size, CompleteWRD rejectWrds[], int reject_size){

    
    printf("\nClues: \n\n");
    printf("Location|Direction|Anagram \n");
    printf("________|_________|_______________\n");
    for(int i = 0; i<size; i++){
        if( (wrdSrtd[i].placed == true)){
        printf("%3d, %3d| %s|  %4s\n", wrdSrtd[i].x, wrdSrtd[i].y, (wrdSrtd[i].isDown ? "DOWN    " : "ACROSS  "), wrdSrtd[i].anagram);
        }
    }

    //for every rejected word that can be placed print a message
    for(int i = 0; i<reject_size; i++){
        if((rejectWrds[i].placed == true)){
        printf("%3d, %3d| %s|  %4s\n", rejectWrds[i].x, rejectWrds[i].y, (wrdSrtd[i].isDown ? "DOWN    " : "ACROSS  "), rejectWrds[i].anagram);
        }
    }

    //For rejected word that remains unplaced print with a message
    for(int i = 0; i<reject_size; i++){
        if((rejectWrds[i].placed == false)){
        printf("Couldn't Place: %s\n",  rejectWrds[i].wrd);
        }
    }

}
