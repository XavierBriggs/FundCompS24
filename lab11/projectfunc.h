//Xavier Briggs
//projectfunc.h
//May 3, 2024



#include "gfx2.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define width 600
#define height 600
#define CENTER 300

//game ball struct
typedef struct {
  float xc;
  float yc;
  float radius;
  float dx;
  float dy;
  int R;
  int G;
  int B;
}Ball;

//game bar struct
typedef struct {
  float x;
  float y;
  float wid;
  float ht;
  float dy;
}Bar;

//mode functions
void singlePlayer_mode(Ball gBall, Bar gBar_left, Bar gBar_right, int);
void TwoPlayer_mode(Ball gBall, Bar gBar_left, Bar gBar_right, int);
void get_SingleMode(Ball gBall, Bar gBar_left, Bar gBar_right);
void get_TwoMode(Ball gBall, Bar gBar_left, Bar gBar_right);
void display_Score(int score, int score_x, int score_y);

//draw functions
void drawZero(int, int);
void drawOne(int, int);
void drawTwo(int, int);
void drawThree(int, int);
void drawFour(int, int);
void drawFive(int, int);
void drawPong();
void drawMiddleLine();
