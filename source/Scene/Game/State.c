#include <stdlib.h>

#include "State.h"

eGame_State_manager State;

void Game_State_init() {
  State = eGame_State_play;
}

void Game_State_update(int key) {
  switch (key) {
    case 'p':
      if (Game_State_now() == eGame_State_play) {
        Game_State_change(eGame_State_pause);
      }
      break;
  }
}

eGame_State_manager Game_State_now() {
  return State;
}

void Game_State_change(eGame_State_manager next) {
  State = next;
}
