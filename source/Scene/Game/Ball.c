#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>

#include "Bar.h"
#include "Ball.h"
#include "../../Config.h"

void Game_Ball_set_radian(Game_Ball* this, Game_Bar* bar) {
  double* bound_angles = Game_Bar_get_bound_angles(bar);
  double angle = bound_angles[(int) this->x - Game_Bar_get_x(bar)];
  this->radian = (angle / 180) * M_PI;
}

Game_Ball* Game_Ball_new(Game_Bar* bar) {

  Game_Ball* this = malloc( sizeof(Game_Ball) );
  if (this == NULL) {
    BreakOut_exit();
  }

  this->shape = "O";
  this->y = Game_Bar_get_y(bar) - 1;
  this->x = Game_Bar_default_ball_place(bar) + 1;
  this->on_the_bar = 1;
  this->speed = 0.15;
  Game_Ball_set_radian(this, bar);

  return this;
}

void Game_Ball_destroy(Game_Ball* this) {
  free(this);
}

void Game_Ball_move(Game_Ball* this) {
  this->y -= sin(this->radian) * this->speed;
  this->x += cos(this->radian) * this->speed;
}

void Game_Ball_update(Game_Ball* this, int key) {
  if (this->on_the_bar) {
    switch (key) {
      case ' ':
        this->on_the_bar = 0;
        break;
      case KEY_LEFT:
        this->x--;
        break;
      case KEY_RIGHT:
        this->x++;
        break;
    }
  } else {
    Game_Ball_move(this);
  }
}

void Game_Ball_draw(Game_Ball* this) {
  mvaddstr(this->y, this->x, this->shape);
}

