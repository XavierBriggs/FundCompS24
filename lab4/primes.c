//Xavier Briggs
//Primes.c
//02/14/24
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Primes function prototypes
void get_primes(int n);
//Main Function
int main()
{
		//Initialize n variable as max index
    int n = 1000;
    printf("Following are the prime numbers from 2-1000: \n");
		//Calls prime function
    get_primes(n);
    return 0;
}

//Prime function to calculate if number is prime
void get_primes(int n)
{
   //Initialize boolean function
    bool prime[n];
		//sets each value of the array to true
    for(int i = 0; i < n; i++){
			prime[i] = true;
		}
 		//For loop to check if number is prime
    for (int j = 2; j * j <= n; j++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[j] == true) {
           //Nested for loop that iterates through each value of p squared and sets each corresponding value to false
					 for (int i = j * j; i <= n; i += j){
                prime[i] = false;
								}
        }
    }
		//Count variable to set where to start new line
 		int count;
    // Print all prime numbers
    for (int j = 2; j <= n; j++){
        if (prime[j]){
            printf("%3.2d ",j);
						count++;
						//prints new line after count is 10
						if((count % 10) == 0){
							printf("\n");
							}
						}
			}
	printf("\n");

}

