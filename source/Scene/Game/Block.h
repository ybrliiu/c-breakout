/* ブロッククラス */

#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

typedef struct {
  int x;
  int y;
  char* shape;
  int width;
  int height;
  int broken;
  int need_update;
} Game_Block;

Game_Block* Game_Block_new(int y, int x);
void Game_Block_destroy(Game_Block* this);

int Game_Block_get_width(Game_Block* this);
void Game_Block_break(Game_Block* this);

void Game_Block_update(Game_Block* this);
void Game_Block_draw(Game_Block* this);

#endif
