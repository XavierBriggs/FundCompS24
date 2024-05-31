//Xavier Briggs
//menucalc.c
//02/07/24

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Function Prototypes
double get_add(double a, double b);
double get_sub(double a, double b);
double get_mult(double a, double b);
double get_divd(double a, double b);
//Main Function
int main(){
	//Intialize choice, user input, and exit variables
	int choice;
	double a;
	double b;
	bool exit = false;
	//While loop to continue prompting the user to choose an option until 5 is entered which exits the program
	while(choice != 5){
		printf("\nPlease select a choice:\n 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division\n 5 to exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		//First if statment to check if user input == 5 if yes sets boolean exit to true and breaks loop
		if (choice ==5){
			exit = true;
			break;
		}
		//Prompts user input when 5 is not chosen
		printf("Enter two numbers: ");
		scanf("%lf %lf", &a, &b);
		//first if statment to check if user input is 1
		if(choice == 1){
			printf("(%.2lf) + (%.2lf) = %.2lf", a, b,get_add(a,b));
		
			}
		//else if for choice 2
		else if(choice == 2){
			printf("(%.2lf) - (%.2lf) = %.2lf", a,b,get_sub(a,b));
		
			}
		//else if for choice 3
		else if (choice == 3){
			printf("(%.2lf) * (%.2lf) = %.2lf", a,b,get_mult(a,b));
		
			}
		//else if for choice 4
		else if(choice == 4){
			//If statment to check to see if denonmenator is zero by calling division function and making sure it does not return 1
			if(get_divd(a,b) != 1){
				printf("(%.2lf) / (%.2lf) = %.2lf", a,b,get_divd(a,b));
				}
			//Else statment for deneonmentor equal to zero causing the loop to restart
			else{
				printf("Your input is invalid can not divide by zero, please try again\n");
			}	
		}
		//else statment for invalid user choice input
		else{
			printf("Your choice intput is invalid try again!");
		}
		

	}
	//If statment for exit statment after 5 is inputed by the user, checks if exit boolean is equal to true and prints accordingly
	if(exit == true){
		printf("Good bye\n");
	
	}
return 0;
}
//Addition function
double get_add(double a, double b){
	return a+b;
}	
//Subtraction Function
double get_sub(double a, double b){
	return a-b;
}
//Multiplication Function
double get_mult(double a, double b){
	return a*b;
}

//Division Function
double get_divd(double a, double b){
	//If statment to check if denonomnator is equal to zero
	if(b!=0){
		return a/b;
	}
	//Else statment to return 1 if the denonmenator is equal to zero meaning it is undefined
	else{
		return 1;
	}
}


