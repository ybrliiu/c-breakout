/* メニュークラス */
typedef struct {
  int x;
  int y;
} Game_Bar;

Game_Bar* Game_Bar_new();
void Game_Bar_destroy(Game_Bar* this);

void Game_Bar_update(Game_Bar* this, int key);
void Game_Bar_draw(Game_Bar* this);
