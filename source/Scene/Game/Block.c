#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>

#include "Block.h"
#include "../../Config.h"
#include "../../Util.h"
#include "Hit.h"

Game_Block* Game_Block_new(int y, int x) {

  Game_Block* this = malloc( sizeof(Game_Block) );

  if (this == NULL) {
    BreakOut_exit();
  }

  this->y = y;
  this->x = x;
  this->shape = "HHHHHHH";
  this->width = strlen(this->shape);
  this->height = 2;
  this->broken = 0;
  this->need_update = 0;
  Game_Block_init_hit_map(this);

  return this;
}

static void Game_Block_init_hit_map(Game_Block* this) {

  array_2D hit_map = Game_Hit_get_map();
  int i;

  for (i = this->x; i <= this->x + this->width; i++) {
    hit_map[this->y][i] = GAME_HIT_BLOCK;
  }
}

void Game_Block_destroy(Game_Block* this) {
  free(this);
}

int Game_Block_get_width(Game_Block* this) {
  return this->width;
}

void Game_Block_break(Game_Block* this) {
  this->broken = 1;
  this->need_update = 1;
}

void Game_Block_update(Game_Block* this) {

  array_2D hit_map = Game_Hit_get_map();
  int i;
  
  if (this->need_update) {
    for (i = this->x; i <= this->x + this->width; i++) {
      hit_map[this->y][i] = GAME_HIT_NO;
    }
    this->need_update = 0;
  }
}

void Game_Block_draw(Game_Block* this) {

  int i;

  if (!this->broken) {
    for (i = 1; i <= this->height; i++) {
      mvaddstr(this->y, this->x, this->shape);
    }
  }
}

