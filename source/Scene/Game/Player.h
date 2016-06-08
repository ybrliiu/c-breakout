
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

/* プレイヤークラス */

typedef struct {
  int life;
  int frame_count;
  int time;
  int score;
} Game_Player;

Game_Player* Game_Player_new();
void Game_Player_destroy(Game_Player* this);

void Game_Player_update(Game_Player* this, int key);
void Game_Player_draw(Game_Player* this);


#endif
