#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Player.h"
#include "../../Config.h"
#include "../../Util.h"
#include "Hit.h"

#define GAME_PLAYER_WALL_Y 2

static void Game_Player_init_hit_map() {

  int i;
  array_2D hit_map = Game_Hit_get_map();

  for (i = 0; i < BREAKOUT_WIDTH; i++) {
    hit_map[GAME_PLAYER_WALL_Y][i] = GAME_HIT_WALL;
  }
}

Game_Player* Game_Player_new() {

  Game_Player* this = malloc( sizeof(Game_Player) );

  if (this == NULL) {
    BreakOut_exit();
  }

  this->life = 3;
  this->frame_count = 0;
  this->time = 0;
  this->score = 0;

  Game_Player_init_hit_map();

  return this;
}

void Game_Player_destroy(Game_Player* this) {
  free(this);
}

void Game_Player_update(Game_Player* this, int key) {

  this->frame_count++;
  if (this->frame_count == 60) {
    this->time++;
    this->frame_count = 0;
  }

}

void Game_Player_draw(Game_Player* this) {

  static int status_y = GAME_PLAYER_WALL_Y / 2;
  int i;

  mvaddstr(status_y, 53, "ライフ:");
  for (i = 1; i <= this->life; i++) {
    mvaddstr(status_y, 60 + (i * 2), "❤");
  }
  mvprintw(status_y, 70, "経過時間:%d秒　スコア:%d", this->time, this->score);

  move(GAME_PLAYER_WALL_Y, 0);
  hline(ACS_HLINE, BREAKOUT_WIDTH - 1);
}

