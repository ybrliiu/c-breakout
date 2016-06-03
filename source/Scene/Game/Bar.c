#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <locale.h>

#include "Bar.h"
#include "../../Config.h"
#include "../../Util.h"

Game_Bar* Game_Bar_new() {
  Game_Bar* this = malloc( sizeof(Game_Bar) );
  if (this == NULL) {
    BreakOut_exit();
  }
  this->shape = "%%%%%%%";
  this->width = strlen(this->shape);
  this->x = BreakOut_centered_str_x(this->shape);
  this->y = 28;
  return this;
}

int Game_Bar_get_y(Game_Bar* this) {
  return this->y;
}

void Game_Bar_destroy(Game_Bar* this) {
  free(this);
}

int Game_Bar_default_ball_place(Game_Bar* this) {
  return this->x + (this->width / 2) + 1;
}

void Game_Bar_update(Game_Bar* this, int key) {
  if (key == KEY_LEFT) {
    this->x--;
  }
  if (key == KEY_RIGHT) {
    this->x++;
  } 
}

void Game_Bar_draw(Game_Bar* this) {
  mvaddstr(this->y, this->x, this->shape);
}

