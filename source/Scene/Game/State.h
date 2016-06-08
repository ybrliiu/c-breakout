/* ゲーム状態管理部 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

typedef enum {
  eGame_State_play,
  eGame_State_pause,
  eGame_State_over,
  eGame_State_complete,   
  
  eGame_State_none,
} eGame_State_manager;

eGame_State_manager Game_State_now();
void Game_State_change(eGame_State_manager next);

#endif
