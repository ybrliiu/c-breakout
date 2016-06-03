/* バークラス */
typedef struct {
  int x;
  int y;
  char *shape;
  int width;
} Game_Bar;

Game_Bar* Game_Bar_new();
int Game_Bar_get_y(Game_Bar* this);
void Game_Bar_destroy(Game_Bar* this);

int Game_Bar_default_ball_place(Game_Bar* this);

void Game_Bar_update(Game_Bar* this, int key);
void Game_Bar_draw(Game_Bar* this);

