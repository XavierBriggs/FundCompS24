//Xavier Briggs
//Program 2: Volume of Right Cylinder
//1/28/24

#include <stdio.h>
#include <math.h>

int main(){
	//Declare Height Variable
	double height;
	//Declare Height Variable
	double radius;
	//Program Description
	printf("This program calculates the volume of a Right Cylinder:\n");
	//height input
	printf("What is the height of the Cylinder?\n");
		scanf("%lf", &height);
	//radius input
	printf("\nWhat is the radius of the Cylinder?\n");
		scanf("%lf", &radius);
	//volume calculations
	double volume = M_PI*pow(radius,2)*height;

	//Answer
	printf("\nThe volume of the Cylinder = \n");
	printf("\n%lf\n", volume);

}
