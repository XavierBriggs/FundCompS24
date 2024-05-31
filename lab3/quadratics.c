// Xavier Briggs
// Fundamentals of Computing: Quadratics.c
// 02/08/24
// computes the roots of a quadratic equation
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Defines Double Function To calculate Discriminant
double get_disc(double, double, double);

//Main Function
int main(){
	//a b c input
 	 double a, b, c, disc;
 	 double x1, x2;
	 bool exit = false;
	 a = 1.0;

	//While loop to prompt user for input and keeps repeating 
  	while(a != 0){
		 	 printf("Enter the coefficients (a,b,c) of a quadratic equation, enter 0 for a to exit program: ");
			 scanf("%lf %lf %lf", &a, &b, &c);
			 //Calls Discriminant function
				disc = get_disc(a,b,c);
			//Checks to see if disc is greater than 0 and a is not 0, there are two roots
 			if(disc >0 && (a != 0)){
	 			 printf("There are two Solutions:\n");
				 x1 = ((-b+sqrt(disc))/(2*a));
				 x2 = ((-b-sqrt(disc))/(2*a));
				 printf("First Root = %.2lf \nSecond Root = %.2lf \n", x1, x2);
			}
			//Checks to see if disc is equal to 0 and a is not 0, there is one root
			else if((disc==0)&&(a!= 0)){
				printf("There is only one solution:\n");
				x1 = ((-b)/(2*a));
				printf("X1 = %.2lf\n", x1);
	
			}
			//Final Check to see if theere are no roots and a is still not zero
	  	else if(a!=0){
				printf("There is no real roots\n");
		
			}	
			//Breaks loop if other if's fail meaning a was zero sets exit boolean to true for next if statment
			else{
				exit = true;
				break;
			}
	}
	//Final print statment if A was zero 
	if(exit == true){
		printf("Thank you good bye!\n");
	
	}

  return 0;
}

//Function to Calculate the Discrimenent
double get_disc(double a, double b, double c){

	return (b*b)-(4*a*c);
}
