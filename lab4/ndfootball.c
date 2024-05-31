//Xavier Briggs
//ndfootball.c
//02/14/24

#include <stdio.h>
#include <stdbool.h>
#include "nd_data.h"

//Function Prototypes
void get_givenYear(int years);
void get_numWins(int num);
void get_numLosses(int num);
void get_averageWins(int yearOne, int yearTwo);
void get_averageLosses(int yearOne, int yearTwo);
//Main Function
int main(){
	//Initialize user Input variables
	int choice = 0;
	int year;
	int num;
	int yearOne;
	int yearTwo;
	bool exit = false;
	//While loop that runs until choice == 6
	while(choice != 6){
		//Menu prompts to user
		printf("1:Display the record for a given year.\n2:Display years with num wins.\n");
		printf("3:Display years with num losses.\n4:Average num wins from starting year to ending year\n");
		printf("5:Average number of losses from starting year to ending year\n6:Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		//Exit case
		if(choice ==6){
			exit = true;
			break;
		}
		//If statments to determine which choice the user has made
		if(choice	== 1){
			printf("Enter the year: ");
			scanf("%d", &year);
			//Calls the Given year function
			get_givenYear(year);
		
		}
		//Choice 2
		else if (choice == 2){
			printf("Enter the number of wins: ");
			scanf("%d", &num);
			//Calls the num wins function
			get_numWins(num);
		
		}
		//Choice 3
		else if (choice == 3) {
			printf("Enter the number of losses: ");
			scanf("%d", &num);
			//Calls num losses function
			get_numLosses(num);
		
		}
		//Choice 4
		else if (choice == 4){
			printf("Enter the starting year followed by the ending year: ");
			scanf("%d %d", &yearOne, &yearTwo);	
			//Calls average wins function
			get_averageWins(yearOne, yearTwo);
		
		}
		//Choice 5
		else if(choice == 5){
			printf("Enter the starting year followed by the ending year: ");
			scanf("%d %d", &yearOne, &yearTwo);
			//Calls average losses function
			get_averageLosses(yearOne, yearTwo);
		}

	}
	//Exit statment that prints after choice = 6
	if(exit ==true){
		printf("Good bye, Thank You!\n");
	}

	return 0;
}
//Function to get the w/l record of Notre Dame in a given year
void get_givenYear(int year){
//Used to determine desired index of win and loss array
	int years = year-1900;
	printf("Wins: %d Loses: %d\n", wins[years], losses[years]);

}
//Function to get the years Notre Dame has had num wins
void get_numWins(int num){
	int length = sizeof(wins)/sizeof(int);
	//Iterates through each index and checks if the value at that index is equal to num and prints i + 1900
	for(int i = 0; i < length; i++){
		if(wins[i] == num){
			printf("%d ", i+1900);
			}
	}
	printf("\n");
	

}

//Function to get the years Notre dame has had num losses
void get_numLosses(int num){
	int length = sizeof(losses)/sizeof(int);
	//Iterates through each index and checks if the value at that index is equal to num and prints i + 1900
	for(int i = 0; i < length; i++){
		if(losses[i] == num){
			printf("%d ", i+1900);
		}
	}
	printf("\n");
}
//Function to get the average number of wins Notre Dame has had from startingyear to endingyear
void get_averageWins(int yearOne, int yearTwo){
	int yearOneInd = yearOne - 1900;
	int yearTwoInd= yearTwo - 1900;
	int yearRange = yearTwoInd-yearOneInd;
	int	sumWins = 0;
	//for loop that sums each win from a starting year to an ending year
	for(int i = 0; i < yearRange;i++){
		sumWins = sumWins + wins[yearOneInd];
		yearOne++;
	}
	//Calculates the average num of wins per year from a certain year range
	int avg = sumWins/yearRange;
	yearOne = yearOneInd + 1900;
	printf("Average Number of wins from %d to %d: %d\n", yearOne, yearTwo,avg);

}
//Function to get the average number of losses Notre Dame has had from startingyear to endingyear
void get_averageLosses(int yearOne, int yearTwo){
	int	yearOneInd = yearOne - 1900;
	int yearTwoInd= yearTwo - 1900;
	int yearRange = yearTwo-yearOne;
	int	sumLosses = 0;
	//for loop that sums each loss from a starting year to an ending year
	for(int i = 0; i < yearRange;i++){
		sumLosses = sumLosses + losses[yearOneInd];
		yearOne++;
	}
	//calculates the average num of losses per year from a certain year range
	int avg = sumLosses/yearRange;
	yearOne = yearOneInd + 1900;
	printf("Average Number of losses from %d to %d: %d\n", yearOne, yearTwo,avg);

}
