//Xavier Briggs
//Fundamentals of Computing: Mortgage.c
//02/04/24



#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main(){

	//User Inputs Variables
	double intRate;
	double princ;
	double monPay;
	//Month and total Payment Variables
	int monthNum;
	//Sum of Monthly Payments Variable
	double paymentSum; 
	//Net interest Calculated as Principle * Interest Rate
	double intNet;
	//Years Variable
	int years;
	bool invalid;
	//user Inputs
	printf("Enter the principle or your loan ($):  ");
	scanf("%lf", &princ);
	printf("Enter the yearly interest ratet of your loan (%): ");
	scanf("%lf", &intRate);
	printf("Enter the monthly payment of your loan ($): ");
	scanf("%lf", &monPay);

	
	//While loop to check invalid user values
	while ((intRate<0)|| (princ<=0)|| (monPay<=0)){
		printf("One of your Inputs is invalid, please try again\n");
		printf("Enter the principle or your loan ($):  ");
		scanf("%lf", &princ);
		//Interest Rate Input
		printf("Enter the yearly interest rate of your loan (%): ");
		scanf("%lf", &intRate);
		//Month Pay Input
		printf("Enter the montly payment for your loan ($)");
		scanf("%lf", &monPay);
	}
	
	//Interest Rate Calculation
	intRate = (0.01 * intRate)/12; 

	printf("Month  Payment   Interest   Balance\n");
	//While loop to calculate 
	while(princ != 0) {
		//interest rate payment calculation
		intNet = princ * intRate;
		//If statment Checks if monthly payment is too small to pay off loan
		if(monPay < intNet){
			invalid = true;
			break;
	
		}		
		//If statment to calculate monthly payment after the principle is less then the monthly payment
		if(princ < monPay){ 
		
		monPay = princ + intNet;
      intRate = 0;
	}
		//Mortgage calculations
		princ = princ-(monPay-intNet);
		monthNum++;
		printf("%3d   $%6.2lf   $%7.2lf   $%9.2lf\n", monthNum, monPay, intNet, princ); 
		paymentSum = paymentSum + monPay;
	}
	//Calculates amount of years and month number
	years = monthNum/12;
	monthNum = monthNum % 12;
	//If statment to check if invalid input is true to return that the monthly payment is too small. else prints sum of variables
	if(invalid == true){
		
		printf("You need to increase your money, you'll never pay off this loan\n");
	}
	else{
		printf("You paid a total of $%.2lf  over %d years and %d  months\n", paymentSum, years, monthNum);
	
	}
return 0;
}
