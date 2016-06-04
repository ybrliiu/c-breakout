#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>

#include "Bar.h"
#include "../../Config.h"
#include "../../Util.h"

double* Game_Bar_set_bound_angles(Game_Bar* this) {

  int width = this->width + 1;
  double interval = (double) 180 / width;
  double *bound_angles;
  double angle = 180;
  int index = 0;

  bound_angles = (double *) malloc( sizeof(double) * this->width );
  
  for (angle -= interval; angle > 0; angle -= interval) {
    bound_angles[index] = angle;
    index++;
  }

  return bound_angles;
}

Game_Bar* Game_Bar_new() {

  Game_Bar* this = malloc( sizeof(Game_Bar) );
  if (this == NULL) {
    BreakOut_exit();
  }

  this->shape = "%%%%%%%";
  this->width = strlen(this->shape);
  this->x = BreakOut_centered_str_x(this->shape);
  this->y = 28;
  this->bound_angles = Game_Bar_set_bound_angles(this);

  return this;
}

void Game_Bar_destroy(Game_Bar* this) {
  free(this->bound_angles);
  free(this);
}

int Game_Bar_get_y(Game_Bar* this) {
  return this->y;
}

int Game_Bar_get_x(Game_Bar* this) {
  return this->x;
}

double* Game_Bar_get_bound_angles(Game_Bar* this) {
  return this->bound_angles;
}

int Game_Bar_default_ball_place(Game_Bar* this) {
  return this->x + (this->width / 2) + 1;
}

void Game_Bar_update(Game_Bar* this, int key) {
  switch (key) {
    case KEY_LEFT:
      this->x--;
      break;
    case KEY_RIGHT:
      this->x++;
      break;
  } 
}

void Game_Bar_draw(Game_Bar* this) {
  mvaddstr(this->y, this->x, this->shape);
}

