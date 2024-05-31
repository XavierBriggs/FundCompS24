//Xavier Briggs
//fractals.c
//April 28, 2024

#include "gfx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define CENTER 350

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );//fractal No. 1
void shrinkSquares(float x, float y, float size);//fractal No. 2
void squareSpiral(int x, int y,float radius, float theta);//fractal No. 3
void circleLace(float xc, float yc, float r);//fractal No. 4
void snowflake(int x1, int y1, int radius);//fractal No. 5
void tree(int x1, int y1, int x2, int y2, int radius, float theta);//Fractal No. 6
void fern(int x, int y, float r, float theta);//Fractal No. 7
void spiralofSpiral(float x, float y, float angle, float r);//Fractal No. 8



//draw functions
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
void drawSquare(float x, float y, float size);
void drawSnowflake(int x1, int y1, float radius, float theta);
void drawFern(int x1, int y1, float radius, float theta);

int main()
{
  //board dimentions and mrgn for triangle and general x and ys
  int width = 700, height = 700, mrgn = 20;
  int x = CENTER, y = CENTER, size = CENTER, radius = 200;
  float xc = CENTER,yc = CENTER,r = 200, theta = 2*M_PI;
  char c;

  gfx_open(width, height, "Fractals");
  while(1) {

     c = gfx_wait();//waits for user input
     gfx_clear();
    
      //if statments for user choice
      if(c == '1'){
        sierpinski(mrgn, mrgn, width-mrgn, mrgn, width/2, height-mrgn);

      }
      else if(c == '2'){
        shrinkSquares(x, y, size);

      }
     else if(c == '3'){
      squareSpiral(350,350, 300, 0);
      }
      else if(c == '4'){
        circleLace(xc,yc,r);

      }
      else if(c == '5'){
        snowflake(CENTER,  CENTER, 250);

      }
      else if(c == '6'){
        int x1 = 350,y1 =650,x2=x1+ radius*cos(theta*0.25),y2=y1+radius*sin(theta*0.25);
        tree( x1,  y1,  x2,  y2, radius, M_PI/2);

      }
    else if(c == '7'){
      fern(width/2, (width/2)+300, radius+200, (M_PI/2));

    }
    else if(c == '8'){
         spiralofSpiral(width/2, height/2, 0,  width);
        }
    if (c == 'q' ) break;
      }

  }

//fractal Num. 1
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  // Base case. 
  if( abs(x2-x1) < 5 ) return;

  // Draw a triangle
  drawTriangle( x1, y1, x2, y2, x3, y3);

  // Recursive calls
  sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
}

//Fractal Num. 2
void shrinkSquares(float x, float y, float size){
  int n; 
  //Base Case
  if(abs((x-size/2)-(x+size/2)) < 2) return;

  //Draw a square
  drawSquare(x, y, size);

  //Recursion
      shrinkSquares(x-size/2, y - size/2, size*0.45);//top left square
      shrinkSquares(x+size/2, y - size/2, size*0.45);//top right square
      shrinkSquares(x-size/2, y + size/2, size*0.45);//bottom left square
      shrinkSquares(x+size/2, y + size/2, size*0.45);//bottom right square


}
void drawSquare(float x, float y, float size){
    float leftX, rightX, upY, downY;

    //Point of leftside
    leftX = x-size/2;

    //Point of rightside
    rightX = x + size/2;

    //Point of upside
    upY = y - size/2;

    //Point of downside
    downY = y + size/2;

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

//Fractal Num 3
void squareSpiral(int x, int y,float radius, float theta){

  //Base case
  if(radius < 1) return;

  x = 350 + radius*cos(theta);
  y = 350 + radius*sin(theta);
  int length = radius/4;
  drawSquare(x, y, length);

  //recursive call recursing on radius 
  squareSpiral(x,  y, radius*0.9,  theta+0.5);


}

//Fractal Num. 4
void circleLace(float xc, float yc, float r){
  float radius = r;
  double theta = 2*M_PI;
  //base case, if radius is less then one pixels
  if(r < 1) return;

  //draw circle
  gfx_circle(xc,yc,r);
  
  //Recursion
  circleLace( xc + radius*cos(theta*0.3333),  yc+radius*sin(theta*0.3333),  r/3);//top left circles
  circleLace( xc + radius*cos(theta*0.1667),  yc+radius*sin(theta*0.1667),  r/3);//top right circles
  circleLace( xc + radius*cos(theta*0.5),  yc+radius*sin(theta*0.5),  r/3);//middle left circles
  circleLace( xc + radius*cos(theta),  yc+radius*sin(theta),  r/3);//middle right circles
  circleLace( xc + radius*cos(theta*0.6667),  yc+radius*sin(theta*0.6667),  r/3);//bottom left circles
  circleLace( xc + radius*cos(theta*0.833),  yc+radius*sin(theta*0.833),  r/3);//bottom right circles



}

//Fractal No. 5 snowflake
void snowflake(int x1, int y1, int radius){
  float theta = 2*M_PI;

  //Base Case
  if(radius<0.5) return;
   
  drawSnowflake(x1, y1, radius, theta);

  //recursive calls recursing on radius
  snowflake(x1+ radius*cos(theta*0.333), y1+radius*sin(theta*0.625), radius/3);//top left
  snowflake(x1+ radius*cos(theta*0.1667), y1+radius*sin(theta*0.875), radius/3);//top right
  snowflake(x1+ radius*cos(theta*0.25), y1+radius*sin(theta*0.25), radius/3); //middle
  snowflake(x1+ radius*cos(theta*0.5833), y1+radius*sin(theta*0.4167), radius/3); //bottomleft
  snowflake(x1+ radius*cos(theta*0.9167), y1+radius*sin(theta*0.083), radius/3);//bottomright



 
}

void drawSnowflake(int x1, int y1, float radius, float theta){

  //Draw line
  gfx_line(x1,y1,x1+ radius*cos(theta*0.333),y1+radius*sin(theta*0.625));//topleft
  gfx_line(x1,y1,x1+ radius*cos(theta*0.1667),y1+radius*sin(theta*0.875));//topright
  gfx_line(x1,y1,x1+ radius*cos(theta*0.25),y1+radius*sin(theta*0.25));//middle
  gfx_line(x1,y1,x1+ radius*cos(theta*0.5833),y1+radius*sin(theta*0.4167));//bottomleft
  gfx_line(x1,y1,x1+ radius*cos(theta*0.9167),y1+radius*sin(theta*0.083));//bottomright
}

//Fractal No. 6 Tree
void tree(int x1, int y1, int x2, int y2, int radius, float theta) {

    //Theta starts at pi/2

    // Base Case
    if (radius < 2) return;

    //Next x and y coordinate are calculated
    x2 = x1 + radius * cos(theta);
    y2 = y1 - radius * sin(theta);

    // Draw lines
    gfx_line(x1, y1, x2, y2); // Draw branch

    // Recursively call tree with new coordinates, adjusting angle for the branches
    tree(x2, y2, x2 + (x2 - x1) / 2, y2 - (y1 - y2) / 2, radius / 1.4, theta + (M_PI/5)); //Left branches
    tree(x2, y2, x2 + (x2 - x1) / 2, y2 - (y1 - y2) / 2, radius / 1.4, theta - (M_PI/5)); //Right Branches
}






//Fractal No. 7 Fern 
void fern(int x, int y, float radius, float theta)
{
  //base case if radius is lower then 4
  if (radius < 4)
    return;

  //x and y calculation
  int x2 = x + radius * cos(theta);
  int y2 = y - radius * sin(theta);

  //draws line
  gfx_line(x, y, x2, y2);


  //For loop to loop through each lines positon on the line segment
  for (int i = 1; i <= 4; i++)
  {
    //recursive call each time radius is incremented
    fern(x + i * radius * cos(theta) / 4, y - i * radius * sin(theta) / 4, 0.35 * radius, theta + (M_PI / 4));//leftside
    fern(x + i * radius * cos(theta) / 4, y - i * radius * sin(theta) / 4, 0.35 * radius, theta - (M_PI / 4));//rightside
  }
}



//fractal No. 8
void spiralofSpiral(float x, float y, float theta, float radius){

  //while loop to keep track of outer loop
  while(radius > 1){

    //increments theta and the radius before each point calculation
    theta += M_PI/5;
    radius *= 0.9;

    int x1 = x + cos(theta) * radius;
    int y1 = y + sin(theta) * radius;

    if(radius < 4){

      //draws just points if radius is less then 4 pixels
      gfx_point(x1,y1);
    }
    else{
      
      //recursion for spiral at each point
      spiralofSpiral(x1, y1, theta, radius/2.4);
    }
  }
}
