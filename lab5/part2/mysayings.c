//Xavier Briggs
//mysayings.c
//03/03/2024


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_MAXLEN 256
#define STR_MAXNUM 50

//Function Prototypes
int read_file(FILE*, char multi_saying[STR_MAXNUM] [STR_MAXLEN]);
void display_sayings(int count, char multi_saying[STR_MAXNUM][STR_MAXLEN]);
void get_newSaying(int count, char multi_saying[STR_MAXNUM][STR_MAXLEN]);
void get_strCompare(int count, char multi_syaing[STR_MAXNUM][STR_MAXLEN]);
void get_newFile(int count, char multi_saying [STR_MAXNUM] [STR_MAXLEN]);

int main () {
	//Variable declerations
	char fileInput [30];
	char multi_saying[STR_MAXNUM] [STR_MAXLEN];
	FILE* userFile;
	int size, choice;
	char tempChar;
	char hold;
	bool exit;
	bool isNull = true;
	
	//Prompts user for a file name to read users file into program's data structure
	while(isNull == true){
		printf("Enter your startup file name: ");
		scanf("%s", fileInput);
		userFile = fopen(fileInput, "r");
		if(!userFile){
			printf("Your input is invalid try again\n");
			isNull = true;
		}
		if(userFile){
			isNull = false;
		}
	}

	//Calls the read_files function to read the file as well as calculate count to determine the number of strings in the 2d array		
	int count = read_file(userFile, multi_saying);
	fclose(userFile);
	printf("Welcome to the sayings database!\n\nWhat would you like to do?\n");
		//while loop to reprompt the program's menu until user enters the exit case
		while(choice != 5){
			printf("1:Display all sayings currently in the database\n2:Enter a new saying into the database\n3:List sayings that contain a given substring entered by the user\n4:Save all sayings in a new text file\n");
			printf("5:Quit the program\n");
			scanf("%d", &choice);
			//Holds the new line character from newline character in memory
			hold = getchar();
		if(choice == 5){
			exit = true;
			break;
		}
		if(choice == 1){
			display_sayings(count,multi_saying);
			}	
		else if (choice == 2){
			get_newSaying(count,multi_saying);
			count++;
		}
		else if (choice == 3){
			get_strCompare(count,multi_saying);	
		}
		else if (choice == 4){
			get_newFile(count,multi_saying);

		}
	}
	if(exit == true){
		printf("Goodbye!\n");
	
	}

	return 0;
}

//Function to read in the file and store it in the multi_saying 2D-char
int read_file(FILE* userFile, char multi_saying [] [STR_MAXLEN]){
		char one_saying [STR_MAXLEN];
		int count = 0;
		while(1) {
   	 fgets(one_saying, STR_MAXLEN, userFile);
    	if (feof(userFile)) break;
    	one_saying[strlen(one_saying)-1] = '\0';
    	strcpy(multi_saying[count],one_saying);
    	count++;
  }
	return count;

}
//Function to display all of the sayings in the programs database
void display_sayings(int count, char multi_saying[][STR_MAXLEN]){
	//char sayings [STR_MAXNUM] [STR_MAXLEN];
	for(int i = 0; i < count; i++){
		printf("%s\n", multi_saying[i]);
	}


}
//Function to prompt the user to enter a new saying from the keyboard
void get_newSaying(int count, char multi_saying[][STR_MAXLEN]){
	char one_saying [STR_MAXLEN];
	printf("Enter your new line: ");
	fgets(one_saying, STR_MAXLEN, stdin);
	one_saying[strlen(one_saying)-1] = '\0';
	strcpy(multi_saying[count], one_saying);
		}
//Function to compare a string to the users inputed substring
void get_strCompare(int count, char multi_saying[STR_MAXNUM][STR_MAXLEN]){
	char str_compare [STR_MAXLEN];
	char one_saying [STR_MAXLEN];
	char *isEqual;
	printf("Enter your substring: ");
	fgets(str_compare, STR_MAXLEN, stdin);
	str_compare[strlen(str_compare)-1]='\0';
	printf("Matched Sayings: \n");
	for(int i = 0; i<count; i++){
		strcpy(one_saying, multi_saying[i]);
		isEqual = strstr(one_saying, str_compare);
		if(isEqual != NULL){
			printf("%s\n", one_saying);
		}
	
}

}
//Function to create a newFile
void get_newFile(int count, char multi_saying[][STR_MAXLEN]){
	char fileName [STR_MAXLEN];
	char newLine = '\n';
	FILE* newFile = NULL;
	printf("Enter a name for your new file: ");
	fgets(fileName, STR_MAXLEN, stdin);
	fileName[strlen(fileName)-1] = '\0';
	newFile = fopen(fileName, "w");
	for(int i = 0; i<count; i++){
		fputs(multi_saying[i], newFile);
		fputc(newLine, newFile);
	}

}


