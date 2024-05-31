//Xavier Briggs
//pathfunc.c
//03/22/24
#include "pathfunc.h"

//Function that reads the points in a user inputted file and saves to the points_arr structure of arrays
int readFile(FILE* fp, Point arr[]){

    //Counter variable for index of array and size
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%f %f", &arr[i].x, &arr[i].y);
				if(feof(fp)) break;
        i++;
    }
    

    return i; 
}

//Function that uses the distance formula to calculate the distance between a range of points
float get_distance(Point arr[], int size){
    float totalDis;
    float distance;
    for(int i = 0; i<size-1; i++){
        float DiffX = 0;
        float DiffY = 0;

        //The difference of X2-X1
        DiffX = arr[i+1].x - arr[i].x;

        //Difference of Y2-Y1
         DiffY = arr[i+1].y - arr[i].y;

         //Calculates the distance between a set of points
         distance = sqrt((pow(DiffX,2) + pow(DiffY, 2)));

         //Adds the current distance to past distances
         totalDis += distance;
     }
    return totalDis;

}
void display (Point arr[], int size){
    
    //Prints number of points
    printf("There are %d points:\n", size);
    printf("      X | Y \n");
    printf("________+________\n");

    //For Loops through array points until it reaches the end of the points
    for(int i = 0; i<size; i++){
        printf("%7.2f | %7.2f\n", arr[i].x, arr[i].y);
    }
    printf("The length of the path through them is: %.2f\n", get_distance(arr, size));
}
