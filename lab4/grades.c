//Xavier Briggs
//Grades.c
//02/14/24

#include <stdio.h>
#include <math.h>

// function prototypes
float get_average(int length, int grades[]);
float get_std(int length, int grades[]);
//Main Function
int main()
{
	//Grades array
  int grades[] =
    { 96,73,62,87,80,63,93,79,71,99,
      82,83,80,97,89,82,93,92,95,89,
      71,97,91,95,63,81,76,98,64,86,
      74,79,98,82,77,68,87,70,75,97,
      71,94,68,87,79 };
	//Computes size of array by using the sizeof function
	int length = sizeof(grades)/sizeof(int);
	//Calls the get average function with length and grades as two arguments
	printf("There are %d grades\n", length);
	printf("The average grade is %.2f\n", get_average(length, grades));
	printf("The standard devation of grades is %.2f\n", get_std(length, grades));

  
  return 0;
}

//Average Grade Calculation Function
float get_average(int length, int grades[]){
	//Sum variable to add up all values in array
	float sum = 0;
	//For loop to iterate through each array value and adds them up using a sum variable
  for(int i = 0; i < length; i++){
		sum = grades[i] + sum;
	}
	//Calculates the average by divinding the sum of numbers in array by the size of the array
	float avg = sum/length;
	return avg;
}
float get_std(int length, int  grades[]){
	//Float for the sum of the squared differences from mean
	float sumSQ = 0;	
	//Calls the get average function for standard devation calculation
	float avg = get_average(length, grades);
	//For loop that Calculates the sum of the squared differences from mean
	for(int i = 0; i < length; i++){
	sumSQ = pow(fabs(avg-grades[i]), 2) + sumSQ;
	}
	//Final STD calculation square rooting the the sum of the squared differences divided by the number of data points
	float	STD = sqrt((sumSQ/length));
	return STD;

}

