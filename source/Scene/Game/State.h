/* ゲーム状態管理クラス */

#ifndef GAME_STATE_H
#define GAME_STATE_H

typedef enum {
  eGame_State_play,
  eGame_State_pause,
  eGame_State_game_over,
  eGame_State_game_clear,   
  
  eGame_State_none,
} eGame_State_manager;

void Game_State_init();

void Game_State_update(int key);

eGame_State_manager Game_State_now();
void Game_State_change(eGame_State_manager next);

#endif
