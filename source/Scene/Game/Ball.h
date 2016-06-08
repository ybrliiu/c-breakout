/* ボールクラス */

#ifndef GAME_BALL_H
#define GAME_BALL_H

#include "Bar.h"

typedef struct {
  double x;
  double y;
  double speed;
  double radian;
  int on_the_bar;
  char *shape;
} Game_Ball;

Game_Ball* Game_Ball_new(Game_Bar* bar);
void Game_Ball_destroy(Game_Ball* this);

void Game_Ball_update(Game_Ball* this, int key, Game_Bar* bar, Game_Player* player);
void Game_Ball_draw(Game_Ball* this);

#endif
