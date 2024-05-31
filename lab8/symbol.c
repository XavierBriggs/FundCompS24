//Xavier Briggs
//symbol.c
//March 28, 2024


#include "gfx.h"
#include <stdio.h>
#include <math.h>
#define SIZE 50

void drawSquare(int x, int y);
void drawCircle(int x, int y);
void drawTriangle(int x, int y);
void drawPoly(int n, int x, int y);

int main (){
    char choice;

    //x and y coordinates and number of sides
    int x,y,n;


    //Opens blank screen
    gfx_open(500, 500, "Symbol.c");
    while(1){

        //Waits for user input
        choice = gfx_wait();
        
        if(choice == 'q'){ 
            break;
        }

        //If choice is 1 or left mous click draw square
       else if(choice == 1){
            x = gfx_xpos();
            y = gfx_ypos();
            drawSquare(x,y);
        }

        //If choice is c draw circle
        else if(choice == 'c'){
            x = gfx_xpos();
            y = gfx_ypos();
            drawCircle(x,y);
        }

        //if choice is t draw triangle
        else if(choice == 't'){
            x = gfx_xpos();
            y = gfx_ypos();
            drawTriangle(x,y);
        }

        //if choice is esc clear screen
        else if(choice == 27){
            gfx_clear();
        }

        //else loop through and check if choice is equal to 3-9 if so draw polygon
        else 
        {
            int n = choice - '0';
            for(int i = 3; i<=9;i++){
                if(n == i){
                    x = gfx_xpos();
                    y = gfx_ypos();
                    drawPoly(n,x,y);
                }
            }
        }
        

    }

}

void drawSquare(int x, int y){
    int leftX, rightX, upY, downY;

    //Point of leftside
    leftX = x-SIZE/2;

    //Point of rightside
    rightX = x + SIZE/2;

    //Point of upside
    upY = y - SIZE/2;

    //Point of downside
    downY = y + SIZE/2;

    //Draw Color
    gfx_color(0, 0, 255);

    //Top Line
    gfx_line(leftX, upY, rightX, upY);

    //bottom line
    gfx_line(leftX, downY, rightX, downY);

    //left line
    gfx_line(leftX, upY, leftX, downY);

    //RightLine
    gfx_line(rightX, upY, rightX, downY);

}


void drawCircle(int x, int y){

    //Color white
    gfx_color(255, 255, 255);

    //Draws circle at x and y coordintae with radius of SIZE
    gfx_circle(x,y, SIZE/2);

}

void drawTriangle(int x, int y){

    //left start
    int leftshift = x-SIZE/2;

    //right start
    int rightshift = x+SIZE/2;

    //down start
    int downshift = y+SIZE/2;

    //Color's Green
    gfx_color(0, 255, 0);

    //Bottom of Triangle
    gfx_line(leftshift, downshift, rightshift, downshift);

    //LeftSide of Triangle
    gfx_line(leftshift, downshift, x, y);

    //RightSide of Triangle
    gfx_line(rightshift, downshift, x, y);


}

void drawPoly(int n, int x, int y) {
    gfx_color(255, 0, 255);

  //Gets the requried starting angle based on n
  float theta = 2 * M_PI / n;

  //Radius of inscrible circle
  float rad = SIZE / 2; 


  //Starting points
  float x1, y1, x2, y2;

  //first x starts at the right of x and y is same
  x1 = x + rad; 
  y1 = y;     
  for (int i = 1; i <= n; i++)
  {
    //Polar cords to find x and y 
    x2 = x + rad * cos(i * theta); 
    y2 = y + rad * sin(i * theta); 

    //draw line between them
    gfx_line(x1, y1, x2, y2);

    //Ending points become new starting points. 
    x1 = x2; 
    y1 = y2; 
  }
}
