//Xavier Briggs
//Letterfreq.c
//02/22/24



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#define ABCNUM  26 


int main() {
	//string array for user file input
	char fileInput[30];
	//Declareing readFile
	FILE* readF = NULL;
	//Char whos value gets updated each time a new character is read
	char tempChar;
	//Int whos value corresponds to the index of the alphabet array where the frequency of letters are being stored
	int abcIndex;
	//Int array to store the frequency of letters that the program reads
	int alphabet[ABCNUM] = {};
	//Count variable to count the number of letters
	int countABC = 0;
	//Count variable to count the number of characters
	int countChar = 0;
	//Frequency variable to calculate the number of times a specfic letter shows up
	int freq;
	//Denomentor used to divide the array value by the letter that corresponds to it to get the frequency
	int abcdivide;
	//Variable used in the calculation of the percentage of letters
	double abcPercent = 0;
	int newLine;
	//adds countAbc and countChar
	float totalChar;
	//Prompts user to enter the name of their file
	//bool to check if file is null
	bool isNull = true;

	//While loop to prompt the user to re-enter file name until a correct file name is entered
	while(isNull == true){
		printf("Enter your file name: ");
		scanf("%s", fileInput);
		//sets ReadF equal to the file inputed by user, opens fileinputed by user in read mode
		readF = fopen(fileInput, "r");
		//Checks to see if users fileInput can be located, if not readF is null and the file name is invalid
		if(!readF){
			printf("Your file name is invalid and can not be found try again: \n");
			isNull = true;
		}
			//If readF is not null sets isNull to false to stop loop
		if(readF){
			isNull = false;
		}
	}
	//While loop that runs to read each character in a file until the end of the file is reached
	while(1){
		//scans the character and stores it as tempChar for calculations in the int array
		fscanf(readF, "%c", &tempChar);
		//if statment to check if character is upper case if it is it makes it a lowercase
		if(isupper(tempChar)){
			tempChar = tolower(tempChar);
			}
	//if statment that checks if tempChar is a letter if it is calculates the location in the alaphabet and stores it at the index that corresponds to that location
		if(isalpha(tempChar)){
			abcIndex = tempChar - 'a';
			alphabet[abcIndex] = tempChar+ alphabet[abcIndex];
			countABC++;
	}
	//else if to add the number of characters up that aren't letters
		else if ((!isalpha(tempChar))){
			countChar++;
	}
	
	//Checks if end of file is reached
		if(feof(readF)) break;
	}
	//Adds total characters letters plus characters. -1 for null terminator
	totalChar = countChar-1 + countABC;
	
	printf("General summary for %s: \n", fileInput);
	printf("There were %.0f total characters\nthere were %d letters \n", totalChar, countABC);

	printf("Letter counts: \n");
	//For loop that calculates the frequency of each letter in a given file
	for(int i = 0; i<ABCNUM;i++){
		abcdivide = i + 97;
		freq = alphabet[i]/abcdivide;
		printf("  %c:  %6d ", abcdivide,freq);
		newLine++;
		if (newLine % 6 == 0) printf("\n");
	}
	printf("\n");
	printf("Letter percentages (%): \n");
	newLine = 0;
	//For loop that clculates the percentage each letter makes up in the whole file
	for(int i = 0; i<ABCNUM; i++){
		abcdivide = i + 97;
		freq = alphabet[i]/abcdivide;
		//fix variable name
		double percent = (double)freq;
		double fcountABC = (double)countABC;
		abcPercent = 100*(percent/fcountABC);
		printf("  %c:  %2.1lf", abcdivide,abcPercent);
		newLine++;
		if (newLine % 6 == 0) printf("\n");

	}
	printf("\n");

	return 0;
}

