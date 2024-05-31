//Xavier Briggs
//Program 1: Notre Dame Football Score Calculator
//1/28/24

//Xavier Briggs Program 1

#include <stdio.h>
int main(){
//Declare Touchdowns Variables
	int tdsNum;
	int tdsWorth=6;
// Declare Extra Point Variable
	int expNum;
	int expWorth=1;
//Declare  Field Goal Variables 
	int fgsNum;
	int fgsWorth=3;
//Declare Safties Variables
	int safNum;
	int safWorth=2;
//Prompts Touchdowns, Extra Points, Field Goals, Safties
	printf("What is the Number of Touchdowns, of Extra Points, of Field Goals, and of Safeties scored by Notre Dame:\n");
	printf("\nWhat is the number of touchdowns?\n");
	scanf("%d", &tdsNum);
	printf("What is the Number of extra points?\n");
	scanf("%d",&expNum);
	printf("What is the Number of fields goals?\n");
	scanf("%d", &fgsNum);
	printf("What is the number of safties?\n");
	scanf("%d", &safNum);

//Total Score Calculations
	int tdsTot= tdsNum*tdsWorth;
	int expTot= expNum*expWorth;
	int fgsTot= fgsNum*fgsWorth;
	int safTot= safNum*safWorth;
	int total= tdsTot+expTot+fgsTot+safTot;
//Output
	printf("Total Amount of Points Scored = %d \n", total);

	return 0; 
} 
