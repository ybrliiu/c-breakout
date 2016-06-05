#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Block.h"
#include "../../Config.h"
#include "../../Util.h"

Game_Block* Game_Block_new() {
  Game_Block* this = malloc( sizeof(Game_Block) );
  if (this == NULL) {
    BreakOut_exit();
  }
  return this;
}

void Game_Block_init_hit_map(Game_Block* this, int** hit_map) {
}

void Game_Block_destroy(Game_Block* this) {
}

void Game_Block_update(Game_Block* this, int key) {
}

void Game_Block_draw(Game_Block* this) {
}

