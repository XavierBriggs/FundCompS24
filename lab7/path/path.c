//Xavier Briggs
//path.c
//03/22/24
#include "pathfunc.h"

int main(){

    //Array of structure and file pointer
    Point points_arr[30];
    FILE *fp = NULL;
    char userFile [20];
    bool isNull = true;

  //While loop that loops until the file pointer points to the adress of a file and is not null
    while(isNull == true){

	//Ask user for name of point file
    printf("Enter your file name: ");
    scanf(" %s", &userFile);

    //Opens userinputted file 
    fp = fopen(userFile, "r");

    //if statement for if the fp is null
		if(!fp){
			printf("Your input is invalid try again\n");
			isNull = true;
		}
    
    //if statement for if the fp is found
		if(fp){
			isNull = false;
		}
	}

  //calculates the number of points as well as the total distance between them and displays them
    int count = readFile(fp, points_arr);
    float totaldis = get_distance(points_arr, count);
    display(points_arr, count);
		fclose(fp);


}
