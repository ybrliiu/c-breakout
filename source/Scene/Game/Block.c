#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>
#include <string.h>

#include "Block.h"
#include "Hit.h"
#include "../../Config.h"
#include "../../Util.h"

static void Game_Block_init_hit_map(Game_Block* this) {

  array_2D hit_map = Game_Hit_get_map();
  int y, x;

  for (y = 0; y < this->height; y++) {
    for (x = this->x; x <= this->x + this->width; x++) {
      hit_map[this->y + y][x] = GAME_HIT_BLOCK;
    }
  }
}

static void Game_Block_init_region(Game_Block* this) {
  this->region->y1 = this->y;
  this->region->x1 = this->x;
  this->region->y2 = this->y + this->height - 1;
  this->region->x2 = this->x + this->width;
}

Game_Block* Game_Block_new(int y, int x) {

  Game_Block* this = malloc( sizeof(Game_Block) );
  this->region = malloc( sizeof(Game_Block_region) );

  if (this == NULL) {
    BreakOut_exit();
  }

  this->y = y;
  this->x = x;
  this->shape = "HHHHHHHH";
  this->width = strlen(this->shape);
  this->height = 2;
  this->broken = 0;
  this->need_update = 0;
  Game_Block_init_region(this);
  Game_Block_init_hit_map(this);

  return this;
}

void Game_Block_destroy(Game_Block* this) {
  free(this->region);
  free(this);
}

int Game_Block_get_width(Game_Block* this) {
  return this->width;
}

int Game_Block_is_broken(Game_Block* this) {
  return this->broken;
}

void Game_Block_break(Game_Block* this) {
  this->broken = 1;
  this->need_update = 1;
}

int Game_Block_is_collision(Game_Block* this, int y, int x) {
  int check_y = (y >= this->region->y1 && y <= this->region->y2);
  int check_x = (x >= this->region->x1 && x <= this->region->x2);
  return (check_y && check_x);
}

void Game_Block_update(Game_Block* this) {

  array_2D hit_map = Game_Hit_get_map();
  int y, x;
  
  if (this->need_update) {
    for (y = 0; y < this->height; y++) {
      for (x = this->x; x <= this->x + this->width; x++) {
        hit_map[this->y + y][x] = GAME_HIT_NO;
      }
    }
    this->need_update = 0;
  }
}

void Game_Block_draw(Game_Block* this) {

  int y;

  if (!this->broken) {
    for (y = 0; y < this->height; y++) {
      mvaddstr(this->y + y, this->x, this->shape);
    }
  }
}

