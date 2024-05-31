//Xavier Briggs
//Polar.c
//02/06/24


#include <stdio.h>
#include <math.h>

	//Function Prototypes
	int get_quadrant(double, double);
	double get_radius(double, double);
	double get_angle(double, double);
	void show_info(int, double, double);
	//Main Function
	int main(){
		//Initializes x and y
		double x;
		double y;
		//Intro Print
		printf("Enter  x and y coordinates for a point in a Cartesian plane coordinate system, to display the quadrant that the point is in (I through IV), its radius, and its angle in degrees\n");
		//User input prompt
		printf("Enter your x: ");
		scanf("%lf", &x);
		printf("Enter your y: ");
		scanf("%lf", &y);
		//Calls User Defined functions
		int quad = get_quadrant(x,y);
		double radius = get_radius(x,y);
		double angle = get_angle(x,y);
		show_info(quad, radius, angle);
		
		return 0;
	}

	//Quadrant calculation Function
	int get_quadrant(double x, double y){

	//Quadrant Int to store which quadrant values are in
		int quad;
			//Checks if x and y are both greater to zero corresponding to quadrant 1
			if((x>0)&&(y>0)){
				quad = 1;
			}
			//Checks if x is less than zero and y is greater then zero resluting in quadrant 2
			else if((x<0) && (y>0)){
				quad = 2;
		
			}
			//Checks if x is less than zero and y is less than zero resulting in quad 3
			else if((x<0)&&(y<0)){
				quad = 3;
			}
			//Checkis if x is greater than zero and y is less than zero resulting in quad 4
			else if((x>0)&&(y<0)){
				quad = 4;
			}
		return quad;
	}

	//Radius Calculation Function
		double get_radius(double x, double y){
			return sqrt(pow(x,2)+pow(y,2));
	
	}
	//Angle Calculation Function
	 double get_angle(double x, double y){
	 	int quad;
		double angle;
		//Calls quadrant function to determine which quadrant the coordinates are in to calculate the angle correctly
		quad = get_quadrant(x,y);
	
		if(quad == 1){
			angle = atan(y/x)*(180/M_PI);
			
		}
		else if(quad == 2){
			//Calculates Absolute Value of x so angle is not negative
			x = fabs(x);
			//Calculates Angle by using the conversion 180/pi and adding 90degrees because it is in the second Quad
			angle = (atan(y/x)*(180/M_PI))+90;
		
		}
		else if(quad == 3){
			//Calculates absolute value of x and y so angle is not negative
			x = fabs(x);
			y = fabs(y);
			//Calculates angle with conversion factor and adds 180 degrees because it is in the third quadrant
			angle = (atan(y/x)* (180/M_PI))+180;
		
		}
		else{
			//Calculates absolute value of y so angle is not negative
			y = fabs(y);
			//Calculates angle with conversion factor and adds 270 degrees becasue it is in the fourth quadrant
			angle = (atan(y/x) * (180/M_PI))+270;
		} 
		//returns calculation of angle
	 return angle;
	 
	 }
	//Display Function
	void show_info(int quad, double radius, double angle){
		printf("Your Coordinates are in quadrant: %d\n", quad);
		printf("Your radius = %.2lf\n", radius);
		printf("Your angle from the positive x axis, counterclockwise = %.2lf\n", angle);
	
	}
