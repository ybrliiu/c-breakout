
#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

/* ブロッククラス */

typedef struct {
  int score;
  int life;
  int time;
} Game_Block;

Game_Block* Game_Block_new();
void Game_Block_init_hit_map(Game_Block* this, int** hit_map);
void Game_Block_destroy(Game_Block* this);

void Game_Block_update(Game_Block* this, int key);
void Game_Block_draw(Game_Block* this);


#endif
