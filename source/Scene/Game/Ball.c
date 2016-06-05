#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>

#include "Ball.h"
#include "../../Config.h"
#include "Bar.h"
#include "Hit.h"

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

int Game_Ball_can_move(Game_Ball* this, double next_y, double next_x) {

  int next_y_int = (int) next_y;
  int next_x_int = (int) next_x;
  array_2D hit_map = Game_Hit_get_map();
  int can_move = 1;

  if (hit_map[next_y_int][next_x_int] == GAME_HIT_WALL) {
    can_move = 0;
  }

  return can_move;
}

void Game_Ball_move(Game_Ball* this) {
  double move_y = sin(this->radian) * this->speed;
  double move_x = cos(this->radian) * this->speed;
  if ( Game_Ball_can_move(this, this->y - move_y, this->x + move_x) ) {
    this->y -= move_y;
    this->x += move_x;
  }
}

void Game_Ball_update(Game_Ball* this, int key, Game_Bar* bar) {
  if (this->on_the_bar) {
    switch (key) {
      case ' ':
        this->on_the_bar = 0;
        break;
      case KEY_LEFT:
        if ( Game_Bar_can_move(bar, Game_Bar_get_x(bar) - 1) ) {
          this->x--;
        }
        break;
      case KEY_RIGHT:
        if ( Game_Bar_can_move(bar, Game_Bar_right_tip(bar) + 1) ) {
          this->x++;
        }
        break;
    }
  } else {
    Game_Ball_move(this);
  }
}

void Game_Ball_draw(Game_Ball* this) {
  mvaddstr(this->y, this->x, this->shape);
}

