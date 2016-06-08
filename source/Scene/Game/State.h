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

typedef struct {
  eGame_State_manager now;
} Game_State;

Game_State* Game_State_new();
void Game_State_destroy(Game_State* this);

eGame_State_manager Game_State_now(Game_State* this);
void Game_State_change(Game_State* this, eGame_State_manager next);

#endif
