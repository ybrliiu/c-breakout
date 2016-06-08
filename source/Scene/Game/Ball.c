#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>

#include "Ball.h"
#include "../../Config.h"
#include "../../Util.h"
#include "State.h"
#include "Bar.h"
#include "Hit.h"

void Game_Ball_update_radian(Game_Ball* this, Game_Bar* bar) {
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
  this->speed = 0.3;
  Game_Ball_update_radian(this, bar);

  return this;
}

void Game_Ball_destroy(Game_Ball* this) {
  free(this);
}

void Game_Ball_collision_detection(Game_Ball* this, double next_y, double next_x, Game_Bar* bar) {

  int next_y_int = (int) next_y;
  int next_x_int = (int) next_x;
  array_2D hit_map = Game_Hit_get_map();

  switch (hit_map[next_y_int][next_x_int]) {
    case GAME_HIT_WALL:
      this->radian = (M_PI / 2) + this->radian;
      break;
    case GAME_HIT_BAR:
      Game_Ball_update_radian(this, bar);
      break;
    case GAME_HIT_BOTTOM:
      Game_State_change(eGame_State_game_over);
      break;
  }
}

void Game_Ball_move_on_the_bar(Game_Ball* this, int key, Game_Bar* bar) {
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
}

void Game_Ball_move(Game_Ball* this, Game_Bar* bar) {

  double move_y = sin(this->radian) * this->speed;
  double move_x = cos(this->radian) * this->speed;

  Game_Ball_collision_detection(this, this->y - move_y, this->x + move_x, bar);
    
  this->y -= move_y;
  this->x += move_x;
}

void Game_Ball_update(Game_Ball* this, int key, Game_Bar* bar) {
  if (this->on_the_bar) {
    Game_Ball_move_on_the_bar(this, key, bar);
  } else {
    Game_Ball_move(this, bar);
  }
}

void Game_Ball_draw(Game_Ball* this) {
  mvaddstr(this->y, this->x, this->shape);
}

