/* 一時停止中のメニュークラス */

#ifndef GAME_PAUSEMENU_H
#define GAME_PAUSEMENU_H

typedef struct {
  int now_select;
} Game_PauseMenu;

Game_PauseMenu* Game_PauseMenu_new();
void Game_PauseMenu_destroy(Game_PauseMenu* this);

void Game_PauseMenu_update(Game_PauseMenu* this, int key, Game_State* state);
void Game_PauseMenu_draw(Game_PauseMenu* this);

#endif
