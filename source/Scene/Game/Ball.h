/* ボールクラス */
typedef struct {
  int x;
  int y;
  int y_x10;
  int on_the_bar;
  char *shape;
} Game_Ball;

Game_Ball* Game_Ball_new(Game_Bar* bar);
void Game_Ball_destroy(Game_Ball* this);

void Game_Ball_update(Game_Ball* this, int key);
void Game_Ball_draw(Game_Ball* this);
