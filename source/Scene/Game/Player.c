#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Player.h"
#include "../../Config.h"
#include "../../Util.h"

Game_Player* Game_Player_new() {
  Game_Player* this = malloc( sizeof(Game_Player) );
  if (this == NULL) {
    BreakOut_exit();
  }
  return this;
}

void Game_Player_init_hit_map(Game_Player* this, int** hit_map) {
}

void Game_Player_destroy(Game_Player* this) {
}

void Game_Player_update(Game_Player* this, int key) {
}

void Game_Player_draw(Game_Player* this) {
}

