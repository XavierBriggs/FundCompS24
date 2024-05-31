//Xavier Briggs
//projectfunc.c
//May 3, 2024


#include "projectfunc.h"

//function that gets the mode the user wants to play
void get_SingleMode( Ball gBall, Bar gBar_left, Bar gBar_right){
  char c;
    gfx_clear();

    //menu
    drawPong();
    gfx_changefont((char *) "12x24");
    gfx_text(CENTER-100, CENTER-50, "1: EASY MODE");
    gfx_text(CENTER-100, CENTER, "2: MEDIUM MODE");
    gfx_text(CENTER-100, CENTER+50, "3: HARD MODE");
    gfx_text(CENTER-100, CENTER+100, "4: COLOR MODE");
    gfx_text(CENTER-100, CENTER+150, "b: GO BACK");
    gfx_flush();

  
    c = gfx_wait();

  //returns from main function
  if(c == 'b') return;

  //easy mode sets all values low
  if(c == '1'){
      gBall.dx = 2;
      gBall.dy = 2;
      gBar_left.dy = 2;
      gBar_right.dy = 2;
      gBar_left.ht = 100;
      gBar_right.ht = 100;
      singlePlayer_mode(gBall, gBar_left, gBar_right, 1);
    }
  //medium mode values set at medium pace
    else if (c == '2'){
      gBall.dy = 4;
      gBall.dx = 4;
      gBar_left.dy = 3;
      gBar_right.dy = 3;
      gBar_left.ht = 70;
      gBar_right.ht = 70;
      singlePlayer_mode(gBall, gBar_left, gBar_right, 2);
    }

    //hard mode values set at hard pace
    else if( c == '3'){
      gBall.dx = 6;
      gBall.dy = 6;
      gBar_left.dy = 7;
      gBar_right.dy = 7;
      gBar_left.ht = 50;
      gBar_right.ht = 50;
      singlePlayer_mode(gBall, gBar_left, gBar_right, 3);
    }
    //color mode
    else if(c == '4'){
      gBall.dx = 4;
      gBall.dy = 4;
      gBar_left.dy = 3;
      gBar_right.dy = 3;
      gBar_left.ht = 70;
      gBar_right.ht = 70;
      singlePlayer_mode(gBall, gBar_left, gBar_right, -2);
    }

    //recursive call for any key thats not an option
    else{
      get_SingleMode(gBall, gBar_left, gBar_right);
    }
  }


//same function as get single mode just for two players 
void get_TwoMode( Ball gBall, Bar gBar_left, Bar gBar_right){
  char c;
 
    gfx_clear();

    //menu
    drawPong();
    gfx_changefont((char *) "12x24");
    gfx_text(CENTER-100, CENTER-50, "1: EASY MODE");
    gfx_text(CENTER-100, CENTER, "2: MEDIUM MODE");
    gfx_text(CENTER-100, CENTER+50, "3: HARD MODE");
    gfx_text(CENTER-100, CENTER+100, "4: COLOR MODE");
    gfx_text(CENTER-100, CENTER+150, "b: GO BACK");
    gfx_flush();


    c = gfx_wait();

    //returns to main function
    if(c == 'b'){
      return;
    }

    //easy mode
    if(c == '1'){
      gBall.dx = 2;
      gBall.dy = 2;
      gBar_left.dy = 3;
      gBar_right.dy = 2;
      gBar_left.ht = 100;
      gBar_right.ht = 100;
      TwoPlayer_mode(gBall, gBar_left, gBar_right, 1);
    }

    //medium mode
    else if (c == '2'){
      gBall.dx = 4;
      gBall.dy = 4;
      gBar_left.dy = 3;
      gBar_right.dy = 3;
      gBar_left.ht = 70;
      gBar_right.ht = 70;
      TwoPlayer_mode(gBall, gBar_left, gBar_right, 2);
    }

    //hard mode
    else if( c == '3'){
      gBall.dx = 5;
      gBall.dy = 5;
      gBar_left.dy = 7;
      gBar_right.dy = 7;
      gBar_left.ht = 50;
      gBar_right.ht = 50;
      TwoPlayer_mode(gBall, gBar_left, gBar_right, 2);
    }
    //fun mode same as medium but color is different
    else if(c == '4'){
      gBall.dx = 4;
      gBall.dy = 4;
      gBar_left.dy = 3;
      gBar_right.dy = 3;
      gBar_left.ht = 70;
      gBar_right.ht = 70;
      TwoPlayer_mode(gBall, gBar_left, gBar_right, -2);
    }

    //recursive call to stay on menu when any key that is not an optioin is pressed
    else{
      get_TwoMode(gBall, gBar_left, gBar_right);
    }
  }


//single player mode function
void singlePlayer_mode(Ball gBall, Bar gBar_left, Bar gBar_right, int diff){

  srand(time(0));

  char c; 
  char pOne [] = "Player One Wins";
  char cmp [] = "Computer Wins";
  int pOne_score = 0; // player one score 
  int pTwo_score = 0; // player two score
  gfx_color(255,255,255);


  while(1) {

    //Clears the screen after each iteration
    gfx_clear();
     if(diff == -2){
    gfx_color(gBall.R, gBall.G, gBall.B);
  } 
    //draws middle line
    drawMiddleLine();

    //left bar
    gfx_fill_rectangle(gBar_left.x, gBar_left.y, gBar_left.wid, gBar_left.ht);

    //right bar
    gfx_fill_rectangle(gBar_right.x, gBar_right.y, gBar_right.wid, gBar_right.ht);
  
    //Draws circle at orginal point plus its velocity
    gfx_fill_circle(gBall.xc+gBall.dx, gBall.yc+gBall.dy, gBall.radius);

    //Waits for user input
    if (gfx_event_waiting()) {
      c = gfx_wait();
    }


    //Sets delay of animation
    usleep(30000);

    //Breaks if user inputs m for menu
    if (c == 'm'){
      gfx_clear();
      break;
    }

    //player movement
    if(c == 's' && gBar_left.y+gBar_left.ht < height){
      gBar_left.dy = 4+abs(diff);
    }else if(c == 'w' && gBar_left.y > 0){
      gBar_left.dy = -4-abs(diff);
    }
  
  
    gfx_flush();


    //dx and dy get added the center of the circle and dy gets added to the bars
    gBall.xc += gBall.dx;
    gBall.yc += gBall.dy;

    if((gBall.dy * -1) == abs(gBall.dy)){
    gBar_right.y += gBall.dy + (0.5/abs(diff));//alters speed of bar based on difficulty
    }
    else{
    gBar_right.y += gBall.dy-(0.5/abs(diff));//alters speed of bar based on difficulty
    }
    gBar_left.y += gBar_left.dy;
   

    //detect collision with the right bar
    if ( (gBall.xc + gBall.radius) >= (width-5) && ((gBall.yc >= gBar_right.y) && (gBall.yc <= gBar_right.y + (gBar_right.ht)))){
      
      //reverses velocity
       gBall.dx = -gBall.dx;
       gBall.dy += 2;

       //randomize color of game
     gBall.R = rand()%256;
     gBall.G = rand()%256;
     gBall.B = rand()%256;
    }
    //detect collision with left bar
     else if( ((gBall.xc - gBall.radius) <= 10) && ((gBall.yc >= gBar_left.y) && (gBall.yc <= (gBar_left.y + gBar_left.ht)))){
    
    //reverses velocity
       gBall.dx = -gBall.dx;
      gBall.dy   += 2;

      //randomize color of game
     gBall.R = rand()%256;
     gBall.G = rand()%256;
     gBall.B = rand()%256;
  }

  //detect collision with top wall
  else if( (gBall.yc - gBall.radius) <= 0){
    gBall.dy = -gBall.dy;//reverse velocity
  }

  //detect collision with bottom wall
  else if( (gBall.yc + gBall.radius) >= height){
    gBall.dy = -gBall.dy;//reverse velocity
  }

  //detect if ball was missed 
  else if((gBall.xc - gBall.radius) >= (width)) {
    pOne_score++;

    //sets the ball to center after score
    gBall.xc = CENTER;
    gBall.yc = CENTER;

    //sets the random velocity of ball with adding the difficulty level
    gBall.dx = -4+rand()%(-2) - abs(diff);
    gBall.dy = -2+rand()%(4) + abs(diff);

    //sets bars in middle after score
    gBar_right.y = CENTER;
    gBar_left.y = CENTER;

    //displays player one if they score
    display_Score(pOne_score, 200, 100);
  }
  else if ( (gBall.xc + gBall.radius) <= 0){
    pTwo_score++;

    //centers ball
    gBall.xc = CENTER;
    gBall.yc = CENTER;

    //randomize velocity
    gBall.dx = 2+rand()%(4) + diff;
    gBall.dy = -2+rand()%(4);

    //centers bars
    gBar_right.y = CENTER;
    gBar_left.y = CENTER;
   
    display_Score(pTwo_score, 400, 100);
  }
  else if((gBall.yc+gBall.radius) > height || (gBall.yc-gBall.radius) < 0){
    gBall.xc = CENTER;
    gBall.yc = CENTER;
  }

    //checks if player two or the computer won, displays win screen and beaks to menu
    if(pTwo_score == 5){
      gfx_clear();
       gfx_text(CENTER-100, CENTER/3, cmp);
       gfx_flush();
       usleep(1000000);
       break;
    }

    //check if player one won, displays win screen and breaks to menu
    if(pOne_score == 5){
      gfx_clear();
      gfx_text(CENTER-100, CENTER/3, pOne);
      gfx_flush();
      usleep(1000000);
      break;
    }

    //checks with top and bottom walls
    if((gBar_left.y+gBar_left.ht) >= height || gBar_left.y <= 0){
        gBar_left.dy = -gBar_left.dy;
      }
    if((gBar_right.y+gBar_right.ht) >= height || gBar_right.y <= 0){
      gBar_right.dy = -gBar_right.dy;
    }
  }


}

//two player mode
void TwoPlayer_mode(Ball gBall, Bar gBar_left, Bar gBar_right, int diff){

  srand(time(0));

  char c; 
  char pOne [] = "Player One Wins";
  char pTwo [] = "Player Two Wins";
  int pOne_score = 0; // player one score 
  int pTwo_score = 0; // player two score
  gfx_color(255,255,255);
  while(1) {
  
    //Clears the screen after each iteration

    gfx_clear();

    //if fun mode is selected randomizes color after each hit/ else color is white
     if(diff == -2){
      gfx_color(gBall.R, gBall.G, gBall.B);
  } 

    //draws middle line
    drawMiddleLine();
    //left bar
    gfx_fill_rectangle(gBar_left.x, gBar_left.y, gBar_left.wid, gBar_left.ht);

    //right bar
    gfx_fill_rectangle(gBar_right.x, gBar_right.y, gBar_right.wid, gBar_right.ht);
  
    //Draws circle at orginal point plus its velocity
    gfx_fill_circle(gBall.xc+gBall.dx, gBall.yc+gBall.dy, gBall.radius);

    //Waits for user input
    if (gfx_event_waiting()) {
      c = gfx_wait();
    }


    //Sets delay of animation
    usleep(30000);

    //Breaks if user inputs c
    if (c == 'm'){
      gfx_clear();
      break;
    }


  
    //first player movement
    if(c == 's' && (gBar_left.y+gBar_left.ht) < height){
      gBar_left.dy = 4+abs(diff);
    }else if(c == 'w' && (gBar_left.y) > 0){
      gBar_left.dy = -4-abs(diff);
    }

    //second player movement
    else if(c == 'i' && gBar_right.y > 0 ){
      gBar_right.dy = -4-abs(diff);
    }
    else if(c == 'k' && (gBar_right.y + gBar_right.ht) < height){
      gBar_right.dy = 4+abs(diff);
    }
    
  
    gfx_flush();


    //dx and dy get added the center of the circle
    gBall.xc += gBall.dx;
    gBall.yc += gBall.dy;
    gBar_right.y += gBar_right.dy;
    gBar_left.y += gBar_left.dy;
   

    //detect collision with the right bar
    if ( (gBall.xc + gBall.radius) >= (width-5) && ((gBall.yc >= gBar_right.y) && (gBall.yc <= gBar_right.y + (gBar_right.ht)))){
      
      //reverses velocity
      gBall.dx = -gBall.dx;
      gBall.dy += 2;

      //randomize color of game
      gBall.R = rand()%256;
      gBall.G = rand()%256;
      gBall.B = rand()%256;
    }
    //detect collision with left bar
     else if( ((gBall.xc - gBall.radius) <= 10) && ((gBall.yc >= gBar_left.y) && (gBall.yc <= (gBar_left.y + gBar_left.ht)))){
       
       //reverses velocity and increases speed
        gBall.dx = -gBall.dx;
        gBall.dy += 2;

         //randomize color of game
        gBall.R = rand()%256;
        gBall.G = rand()%256;
        gBall.B = rand()%256;
  }

  //detect collision with top wall
  else if( (gBall.yc - gBall.radius) <= 0){
    gBall.dy = -gBall.dy;
  }

  //detect collision with bottom wall
  else if( (gBall.yc + gBall.radius) >= height){
    gBall.dy = -gBall.dy;
  }

  //detect if ball was missed 
  else if((gBall.xc - gBall.radius) >= (width)) {
    pOne_score++;

    //ball set to center
    gBall.xc = CENTER;
    gBall.yc = CENTER;

    //randomize veolicty towards player one
    gBall.dx = -4+rand()%(-2)-abs(diff);
    gBall.dy = -4+rand()%(4);

    //bars set to center
    gBar_left.y = CENTER;
    gBar_right.y = CENTER;

    display_Score(pOne_score, 200, 100);
  }
  else if ( (gBall.xc + gBall.radius) <= 0){
    pTwo_score++;

    //sets ball center
    gBall.xc = CENTER;
    gBall.yc = CENTER;

    //random velocity towards player two
    gBall.dx = 2+rand()%(4)+abs(diff);
    gBall.dy = -4+rand()%(4);

    //bars set to center
    gBar_left.y = CENTER;
    gBar_right.y = CENTER;

    display_Score(pTwo_score, 400, 100);
  }
  
  //player two wins
  if(pTwo_score == 5){
       gfx_clear();
       gfx_text(CENTER-100, CENTER/3, pTwo);
       gfx_flush();
       usleep(1000000);
       break;
    }
  //player one wins
  if(pOne_score == 5){
      gfx_clear();
      gfx_text(CENTER-100, CENTER/3, pOne);
      gfx_flush();
      usleep(1000000);
      break;
    }

    //checks bar collisions with top and bottom walls. 
    if((gBar_left.y +gBar_right.ht) >= height || gBar_left.y <= 0){
      gBar_left.dy = -gBar_left.dy;
    }
    if((gBar_right.y+gBar_right.ht) >= height || gBar_right.y <= 0){
      gBar_right.dy = -gBar_right.dy;
    }
  }


}

//function to display players score
void display_Score(int score, int score_x, int score_y){
  
  if(score == 0){
    drawZero(score_x, score_y);
    gfx_flush();
  }
  else if(score == 1){
    drawOne(score_x, score_y);
    gfx_flush();
  }
  else if(score == 2){
    drawTwo(score_x, score_y);
    gfx_flush();
  }
  else if(score == 3){
    drawThree(score_x, score_y);
    gfx_flush();
  }
  else if(score == 4){
    drawFour(score_x, score_y);
    gfx_flush();
  }
  else if(score == 5){
    drawFive(score_x, score_y);
    gfx_flush();
  }
  usleep(1000000);
}

//draws num zero at a x and y
void drawZero(int num_x, int num_y){

   int  num_wid = 50, num_ht = 90;
  gfx_fill_rectangle(num_x, num_y, num_wid, num_ht);
  gfx_color(0,0,0);
  gfx_fill_rectangle(num_x+(num_wid/5), num_y+(num_ht/6), num_ht/3, num_ht/1.5);

}

//draws num one at a x and y
void drawOne(int num_x, int num_y){

    int num_wid = 10, num_ht = 90;
    gfx_fill_rectangle(num_x, num_y, num_wid, num_ht);
}
//draws num two at a x and y
void drawTwo(int num_x, int num_y){

  int  num_wid = 40, num_ht = 10;
  gfx_fill_rectangle(num_x, num_y, num_wid, num_ht);//top bar
  gfx_fill_rectangle(num_x+num_wid, num_y, num_ht, num_wid+10);//sidebar
  gfx_fill_rectangle(num_x, num_y+num_wid, num_wid, num_ht);//middlebar
  gfx_fill_rectangle(num_x, num_y+num_wid, num_ht, num_wid);
  gfx_fill_rectangle(num_x, num_y+num_wid*2, num_wid+10, num_ht);//bottombar



}

//draws num three at a x and y
void drawThree(int num_x, int num_y){
  
  int  num_wid = 40, num_ht = 10;
  gfx_fill_rectangle(num_x, num_y, num_wid, num_ht);//top bar
  gfx_fill_rectangle(num_x+num_wid, num_y, num_ht, num_wid);//sidebar
  gfx_fill_rectangle(num_x, num_y+num_wid, num_wid, num_ht);//middlebar
  gfx_fill_rectangle(num_x, num_y+num_wid*2, num_wid, num_ht);//bottombar
  gfx_fill_rectangle(num_x+num_wid, num_y+num_wid, num_ht, num_wid+10);//bottombar

}

//draws num four at a x and y
void drawFour(int num_x, int num_y){

  int  num_wid = 35, num_ht = 10;
  gfx_fill_rectangle(num_x, num_y, num_wid, num_ht);//top bar
  gfx_fill_rectangle(num_x+num_wid, num_y, num_ht, num_wid+num_wid-20);//bottombar
  gfx_fill_rectangle(num_x+num_wid, num_y-num_wid, num_ht, num_wid+num_wid);//bottombar
  gfx_fill_rectangle(num_x, num_y-num_wid, num_ht, num_wid);//bottombar

}

//draws num five at a x and y
void drawFive(int num_x, int num_y){
  
  int num_wid = 40, num_ht = 10;
  gfx_fill_rectangle(num_x, num_y, num_wid+10, num_ht);//top bar
  gfx_fill_rectangle(num_x, num_y, num_ht, num_wid+10);//sidebar
  gfx_fill_rectangle(num_x, num_y+num_wid, num_wid, num_ht);//middlebar
  gfx_fill_rectangle(num_x+num_wid, num_y+num_wid, num_ht, num_wid);
  gfx_fill_rectangle(num_x, num_y+num_wid*2, num_wid+10, num_ht);//bottombar
}

void drawPong(){
    
    //The Letter P
    int px = 100, py = 40, pwid = 50, pht = 50;
    gfx_color(255, 215, 0);
    gfx_fill_rectangle(px, py, pwid, pht); // starting square
    gfx_color(0,0,128);
    gfx_fill_rectangle(px+(pwid/4),  py+(pwid/4), pwid/2, pht/2); //inner square
    gfx_color(255, 215, 0);
    gfx_fill_rectangle(px, (py+pht), (pwid/4), (pht)); // long rectangle
    
    //The Letter O
    int ox = 160, oy = 70, owid = 70, oht = 70;
    gfx_color(255, 215, 0);
    gfx_fill_rectangle(ox, oy, owid, oht);
    gfx_color(0, 0, 128);
    gfx_fill_rectangle(ox+(owid/4), oy+(owid/4), owid/2,oht/2);

    //The letter N
    int nx = 250, ny = 60, nwid = 30, nht = 80;

    //Order is top left point 
    XPoint letterN [] = {
    {nx, ny},
    {nx, (ny+nht)},
    {(nx+nwid), (ny+nht)},
    {(nx+nwid),(ny+nht/2)},
    {(nx+nwid*2), (ny+nht)},
    {(nx+nwid+nwid*2), (ny+nht)},
    {(nx+nwid+nwid*2), (ny)},
    {(nx+nwid*2), (ny)},
    {(nx+nwid*2), (ny+nht/2)},
    {(nx+nwid), (ny)}
     };


    //size of points
    int size = sizeof(letterN)/sizeof(XPoint);
    gfx_fill_polygon(letterN, size);
    
    //The letter G
    int gx = 360, gy = 50, gwid = 15, ght = 80;
    gfx_color(255, 215, 0);
    gfx_fill_rectangle(gx, gy, gwid+5, ght);//leftmost line
    gfx_fill_rectangle(gx, gy, gwid*6, ght/9);//topaccross line
    gfx_fill_rectangle((gx+gwid*6), gy, gwid, ght/4);//
    gfx_fill_rectangle(gx, gy+ght, gwid*7, ght/9);//bottomacross line
    gfx_fill_rectangle(gx+gwid*6, gy+ght-(ght/3), gwid, ght/3);
    gfx_fill_rectangle(gx+gwid*5, gy+ght-(ght/3), gwid*2, ght/8);
}

//draws line in middle
void drawMiddleLine(){
  int x = 285, y = 0, dy= 50, wid = 15, ht = 40;
    for(int i = 0; i<height/dy; i++){
      gfx_fill_rectangle(x, y+dy*i, wid, ht);
      }
}
