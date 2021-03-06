#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>

#include "Player.h"
#include "Ball.h"
#include "../../Config.h"
#include "../../Util.h"
#include "Block.h"
#include "BlockManager.h"
#include "Bar.h"
#include "Hit.h"
#include "State.h"

static void Game_Ball_update_radian(Game_Ball* this, Game_Bar* bar) {
  double* bound_angles = Game_Bar_get_bound_angles(bar);
  double angle = bound_angles[(int) this->x - Game_Bar_get_x(bar)];
  this->radian = (angle / 180) * M_PI;
}

static void Game_Ball_set_start_place(Game_Ball* this, Game_Bar* bar) {
  this->y = Game_Bar_get_y(bar) - 1;
  this->x = Game_Bar_default_ball_place(bar) + 1;
  this->on_the_bar = 1;
  this->speed = 0.3;
}

Game_Ball* Game_Ball_new(Game_Bar* bar) {

  Game_Ball* this = malloc( sizeof(Game_Ball) );
  if (this == NULL) {
    BreakOut_exit();
  }

  this->shape = "O";
  Game_Ball_set_start_place(this, bar);
  Game_Ball_update_radian(this, bar);

  return this;
}

void Game_Ball_destroy(Game_Ball* this) {
  free(this);
}

static int Game_Ball_wall_angle(Game_Ball* this) {

  int y_int = (int) this->y;
  int x_int = (int) this->x;
  array_2D hit_map = Game_Hit_get_map();

  if (hit_map[y_int][x_int + 1] == GAME_HIT_WALL || hit_map[y_int][x_int + 1] == GAME_HIT_BLOCK) {
    return 90;
  } else if (hit_map[y_int][x_int - 1] == GAME_HIT_WALL || hit_map[y_int][x_int - 1] == GAME_HIT_BLOCK) {
    return 90;
  } else if (hit_map[y_int + 1][x_int] == GAME_HIT_WALL || hit_map[y_int + 1][x_int] == GAME_HIT_BLOCK) {
    return 180;
  } else if (hit_map[y_int - 1][x_int] == GAME_HIT_WALL || hit_map[y_int - 1][x_int] == GAME_HIT_BLOCK) {
    return 180;
  } else {
    return 180;
  }
}

static double Game_Ball_rebound_radian(Game_Ball* this) {

  double this_angle = this->radian / M_PI * 180;
  double rebound_angle;
  int y_int = (int) this->y;
  int x_int = (int) this->x;

  /* 隅にあたった時の特殊処理 */
  if (y_int == 3 && x_int == 98) {
    rebound_angle = 225;
  } else if (y_int == 3 && x_int == 1) {
    rebound_angle = 315;
  } else {
    rebound_angle = Game_Ball_wall_angle(this) * 2 - this_angle;
  }

  return (rebound_angle / 180) * M_PI;
}

static void Game_Ball_collision_detection(Game_Ball* this, double next_y, double next_x, Game_Bar* bar, Game_Player* player) {

  int next_y_int = (int) next_y;
  int next_x_int = (int) next_x;
  array_2D hit_map = Game_Hit_get_map();
  Game_Block* block;

  switch (hit_map[next_y_int][next_x_int]) {
    case GAME_HIT_WALL:
      this->radian = Game_Ball_rebound_radian(this);
      break;
    case GAME_HIT_BLOCK:
      block = Game_BlockManager_get_block(next_y_int, next_x_int);
      Game_Block_break(block);
      Game_Player_score_up(player);
      this->radian = Game_Ball_rebound_radian(this);
      if (Game_BlockManager_remain_blocks() == 0) {
        Game_Player_calc_score(player);
        Game_State_change(eGame_State_game_clear);
      }
      break;
    case GAME_HIT_BAR:
      Game_Ball_update_radian(this, bar);
      break;
    case GAME_HIT_BOTTOM:
      Game_Player_ball_drop_down(player);
      Game_Bar_set_start_place(bar);
      Game_Ball_set_start_place(this, bar);
      Game_Ball_update_radian(this, bar);
      break;
  }
}

static void Game_Ball_move(Game_Ball* this, Game_Bar* bar, Game_Player* player) {

  double move_y = sin(this->radian) * this->speed;
  double move_x = cos(this->radian) * this->speed;

  Game_Ball_collision_detection(this, this->y - move_y, this->x + move_x, bar, player);
    
  this->y -= move_y;
  this->x += move_x;
}

static void Game_Ball_move_on_the_bar(Game_Ball* this, int key, Game_Bar* bar) {
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

void Game_Ball_update(Game_Ball* this, int key, Game_Bar* bar, Game_Player* player) {

  switch (key) {
    case KEY_UP:
      if (this->speed < 0.7) {
        this->speed += 0.1;
      }
      break;
    case KEY_DOWN:
      if (this->speed > 0.1) {
        this->speed -= 0.1;
      }
      break;
  }

  if (this->on_the_bar) {
    Game_Ball_move_on_the_bar(this, key, bar);
  } else {
    Game_Ball_move(this, bar, player);
  }
}

void Game_Ball_draw(Game_Ball* this) {
  attrset(COLOR_PAIR(COLOR_RED));
  mvaddstr(this->y, this->x, this->shape);
  attroff(COLOR_PAIR(COLOR_RED));
}

