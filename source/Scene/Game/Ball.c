#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Bar.h"
#include "Ball.h"
#include "../../Config.h"

Game_Ball* Game_Ball_new(Game_Bar* bar) {
  Game_Ball* this = malloc( sizeof(Game_Ball) );
  if (this == NULL) {
    BreakOut_exit();
  }
  this->shape = "O";
  this->y = Game_Bar_get_y(bar) - 1;
  this->y_x10 = this->y * 10;
  this->x = Game_Bar_default_ball_place(bar);
  this->on_the_bar = 1;
  return this;
}

void Game_Ball_destroy(Game_Ball* this) {
  free(this);
}

void Game_Ball_move(Game_Ball* this) {
  this->y_x10--;
  this->y = this->y_x10 / 10;
}

void Game_Ball_update(Game_Ball* this, int key) {
  if (key == ' ') {
    this->on_the_bar = 0;
  }
  if (!this->on_the_bar) {
    Game_Ball_move(this);
  }
}

void Game_Ball_draw(Game_Ball* this) {
  mvaddstr(this->y, this->x, this->shape);
}

