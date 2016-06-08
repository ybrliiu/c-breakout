#include "State.h"

static eGame_State_manager state = eGame_State_play;

eGame_State_manager Game_State_now() {
  return state;
}

void Game_State_change(eGame_State_manager next) {
  state = next;
}
