//Xavier Briggs
//project.c
//May 3, 2024

#include "projectfunc.h"

int main()
{
  char choice;
  Ball gBall = {300, 300, 15, 255, 255, 255}; //game ball
  Bar gBar_left = {0, height/2, 10, 70, false}; //left game bar
  Bar gBar_right = {width-10, height/2, 10, 70, false}; //right game bar
  gfx_open(width, height, "Pong ND");

  //start menu
  while(1){
    gfx_clear();
    drawPong();
    gfx_color(255, 255, 255);
    gfx_changefont((char *) "12x24");

    //Menu Options
    gfx_text(150, 300, "Press 1 for Single Player"); 
    gfx_text(150, 350, "Press 2 for Two Player"); 
    gfx_text(200, 400, "Press Q to quit"); 
    gfx_text(200, 450, "Press M for menu"); 

    gfx_changefont((char *)"6x10");
    gfx_text(400, 530, "Player One: W for up S for down");
    gfx_text(400, 550, "Player Two: I for up K for down");
    gfx_color(255,255,255);
    gfx_flush();


  choice = gfx_wait();
  if(choice == 'q'){
    break;
  }
  if(choice == '1'){
    get_SingleMode(gBall, gBar_left, gBar_right);//prompts user for e,m,h mode    
  }
  else if(choice == '2'){
    get_TwoMode(gBall, gBar_left, gBar_right);//prompts users for e,m,h mode
 }

  }


  return 0;
}
