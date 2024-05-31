//Xavier Briggs
//Fundamentals of Computing: Graph.c
//02/04/2024



#include <stdio.h>
#include <math.h>


int main(){
	
	//X and Y variables
	double x=0;
	double y;
	//Y max and minimum and X max and Minimum
	double yMax=0;
	double yMin=100;
	double xMax=0;
	double xMin=100;
	//Range and Change in X variable
	double range=20;
	double dX = 0.2;

	//Prints begninning statments of program
	printf("This Program Calculates a plot for the function (cos(x)+1)*20\n");
	printf("Plot for formula (cos(x)+1)*20;for x from (0.0-%.2lf)\n", range);
	printf("  X\t  Y\n");
	//While loop to iterate x until it reaches desired range value
	while(x<=range){
		y=(cos(x)+1)*20;
		printf("%3.2lf\t%3.2lf\t", x,y);
		//if statment to compare y to yMax and saves value and corresponding x value
		if(y>yMax){
			yMax = y;
			xMax = x;
		}
		//if statment to compare y to yMin and saves value and corresponding x value
		if(y<yMin){
			yMin = y;
			xMin = x;
		}
		printf("#");
		//Nested for loop to print # for every y value
		for(int i = 1; i<y; i++){
			printf("#");	
		}
		//prints new line and increments x
		printf("\n");
		x += dX;
	}
	//Prints final maximum y and x and final minimum y and y value
	printf("The maximum of %.2lf was at %.2lf\n", yMax,xMax);
	printf("The minimum of %.2lf was at  %.2lf\n", yMin,xMin);
return 0;
}
