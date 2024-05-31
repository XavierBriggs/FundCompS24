//Xavier Briggs
//funanim.c
//04/03/24



#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 50

//Functions definitions to draw shapes
void drawSquare(float x, float y);
void drawTriangle(float x, float y);
void drawPoly(int x, int y);

int main()
{

  //Sets size of display
  int wid = 600, ht = 600;

  //sets radius of circle shapes rotate around
  int radius = 115;

  //radius of circle that rotates
  int r = 25;
  gfx_open(wid, ht, "Funanim.c");

  //user input
  char c;

  //Variables to calculate points on a circle and the roc of each shapes velocity
  float xc = 300, yc = 300;
  float theta = 2*M_PI;
  float dx1,dy1,dx2,dy2,dx3,dy3,dx4,dy4;
  float count = 0;

  //initial color of shapes
  gfx_color(255,255,255);

  //infinite loop to run animation
  while(1) {

    //clears screen at beginning of each loop and draws each shape 
    gfx_clear();
    gfx_circle(dx1,dy1,r);
    drawSquare(dx2,dy2);
    drawTriangle(dx3,dy3);
    drawPoly(dx4,dy4);

    //waits for user input
    if (gfx_event_waiting()) {
      c = gfx_wait();
    }

    //delay of animation
    usleep(100000);

    //if statements that deal with user input can either quit or change color, q =quit, b = blue, r=red, g=green, w=white, e=radom
    if (c == 'q') break;
    if(c == 'r'){
      gfx_color(255,0,0);
    }
    else if(c == 'b'){
      gfx_color(0,0,255);

    }
    else if (c == 'g'){
      gfx_color(0,255,0);
      
    }
    else if(c == 'w'){
      gfx_color(255,255,255);
    }
    else if(c=='e'){
      int r,g,b;
      r =0+rand()%255;
      g = 0+rand()%255;
      b = 0+rand()%255;
      gfx_color(r,g,b);
    }
    gfx_flush();

  //Count variable to increment location of point
  count++;

  //Calculates the location of the next point on a circle with radius and theta. Each shape starts at a different place on unit circle. 
  //2pi, pi/2, pi, 3pi/2
  dx1 = xc + radius*cos(theta+count);
  dy1 = yc + radius*sin(theta+count);

  dx2 = xc + radius*cos(theta*0.25+count);
  dy2 = yc + radius*sin(theta*0.25+count);

  dx3 = xc + radius*cos(theta*0.5+count);
  dy3 = yc + radius*sin(theta*0.5+count);

  dx4 = xc + radius*cos(theta*0.75+count);
  dy4 = yc + radius*sin(theta*0.75+count);

  }


  return 0;
}


//functions to draw shapes
void drawSquare(float x, float y){
    float leftX, rightX, upY, downY;

    //Point of leftside
    leftX = x-SIZE/2;

    //Point of rightside
    rightX = x + SIZE/2;

    //Point of upside
    upY = y - SIZE/2;

    //Point of downside
    downY = y + SIZE/2;

    //Draw Color
    //gfx_color(0, 0, 255);

    //Top Line
    gfx_line(leftX, upY, rightX, upY);

    //bottom line
    gfx_line(leftX, downY, rightX, downY);

    //left line
    gfx_line(leftX, upY, leftX, downY);

    //RightLine
    gfx_line(rightX, upY, rightX, downY);

}

void drawTriangle(float x, float y){

    //left start
    float leftshift = x-SIZE/2;

    //right start
    float rightshift = x+SIZE/2;

    //down start
    float downshift = y+SIZE/2;

    //Color's Green
   // gfx_color(0, 255, 0);

    //Bottom of Triangle
    gfx_line(leftshift, downshift, rightshift, downshift);

    //LeftSide of Triangle
    gfx_line(leftshift, downshift, x, y);

    //RightSide of Triangle
    gfx_line(rightshift, downshift, x, y);


}

void drawPoly(int x, int y) {

  //Gets the required starting angle based on n
  float theta = 2 * M_PI / 5;

  //Radius of inscribable circle
  float rad = SIZE / 2; 


  //Starting points
  float x1, y1, x2, y2;

  //first x starts at the right of x and y is same
  x1 = x + rad; 
  y1 = y;     
  for (int i = 1; i <= 5; i++)
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
