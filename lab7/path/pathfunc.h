//Xavier Briggs
//pathfunc.h
//03/22/24

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Structure to hold both the x and y coordinate of the inputted points
typedef struct {
  float x;
  float y;
} Point;

//Function Prototypes
int readFile(FILE*fp, Point arr[]);
float get_distance(Point arr[], int size);
void display(Point arr[], int size);
