#include <stdlib.h>

#include "State.h"

Game_State* Game_State_new() {
  Game_State* this = malloc( sizeof(Game_State) );
  if (this == NULL) {
    BreakOut_exit();
  }
  this->now = eGame_State_play;
  return this;
}

void Game_State_destroy(Game_State* this) {
  free(this);
}

eGame_State_manager Game_State_now(Game_State* this) {
  return this->now;
}

void Game_State_change(Game_State* this, eGame_State_manager next) {
  this->now = next;
}
