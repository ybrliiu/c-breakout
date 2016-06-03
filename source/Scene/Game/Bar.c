#include <stdlib.h>
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
  this->x = BREAKOUT_WIDTH / 2;
  this->y = 28;
  return this;
}

void Game_Bar_destroy(Game_Bar* this) {
  free(this);
}

void Game_Bar_update(Game_Bar* this, int key) {
  if (key == KEY_LEFT) {
    this->x--;
  }
  if (key == KEY_RIGHT) {
    this->x++;
  } 
  if (key == ' ') {
  }
}

void Game_Bar_draw(Game_Bar* this) {
  mvaddstr(this->y, this->x, "%%%%%%%");
}

