//Xavier Briggs
//Fundamentals of Computing
//02/04/24


#include <stdio.h>
#include <math.h>

int main(){
	
	//Declare user X input and user Y input
	int userX;
	int userY;
	int multi;
	//Prompt user for X and Y input
	printf("Enter the size of the multiplication table X and Y: ");
	scanf("%d %d", &userX, &userY);
	//Checks to see if user Y input is larger then X input 
	for(int i = 1; i<=userX; i++){
		printf("\t %d", i);
	
	}
	printf("\n");
	//for loop to print underscore across row
	for(int i = 1; i<=userX; i++){
		printf("__________");
		
	
	
	}
		//Nested For loop that computes the multiplication of each int x and y  until k is greater than users Y input
		for(int i = 1; i<=userY; i++){	
			printf("\n%d| ", i);
			for(int j = 1; j<=userX; j++){
				multi = j*i;
				printf("\t%2d", multi);
			
			}
		}
	printf("\n");


	





return 0;
}
