//Xavier Briggs
//bounce.c
//April 03, 2024



#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>



int main()
{

  //Sets size of display and radius of ball
  int wid = 600, ht = 500;
  int radius = 20;

  //Opens display
  gfx_open(wid, ht, "bounce.c");
  char c;

  //Center of circle
  float xc = 100, yc = 100;

  //Orginal Velocity of Ball
  int dx = 2;
  int dy = 1; 

  while(1) {

    //Clears the screen after each iteration
    gfx_clear();

    //Draws circle at orginal point plus its velocity
    gfx_circle(xc + dx, yc + dy, radius);


    //Waits for user input
    if (gfx_event_waiting()) {
      c = gfx_wait();
    }


    //Sets delay of animation
    usleep(30000);

    //Breaks if user inputs c
    if (c == 'q') break;


    //If user left clicks the center of the circle is at the x,y of user click
    if(c == 1){
      
        xc = gfx_xpos();
        yc = gfx_ypos();

        //radomizes the velocity of user circle
        dx = 1+rand()%(2);
        dy = 1+rand()%(2);

        //draws new circle with new velocity
        gfx_circle(xc + dx, yc + dy, radius);

        //clears screen and flushes
        gfx_clear();
        gfx_flush();

        //Sets c equal n to let circle continue
        c = 'n';
    }
    gfx_flush();


    //dx and dy get added the center of the circle
    xc += dx;
    yc += dy;

    //detect collision with the right wall
    if ( (xc + radius) >= wid ){
      dx = -dx;
    }

    //detect collision with left wall
    else if( (xc - radius) <= 0){
    dx = -dx;
  }

  //detect collision with top wall
  else if( (yc - radius) <= 0){
    dy = -dx;
  }

  //detect collision with bottom wall
  else if( (yc + radius) >= ht){
    dy = -dy;
  	}
  }

  

  return 0;
}

