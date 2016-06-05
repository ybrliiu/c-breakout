/* プレイヤークラス */

typedef struct {
  int score;
  int life;
  int time;
} Game_Player;

Game_Player* Game_Player_new();
void Game_Player_init_hit_map(Game_Player* this, int** hit_map);
void Game_Player_destroy(Game_Player* this);

void Game_Player_update(Game_Player* this, int key);
void Game_Player_draw(Game_Player* this);
