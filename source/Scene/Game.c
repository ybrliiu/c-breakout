#include <ncurses.h>
#include <locale.h>

#include "Game.h"
#include "Game/Bar.h"
#include "Game/Ball.h"
#include "Game/Hit.h"
#include "Game/Border.h"
#include "../Util.h"

Game_Bar* Bar;
Game_Ball* Ball;

void Game_init() {
  Bar = Game_Bar_new();
  Ball = Game_Ball_new(Bar);
}

void Game_final() {
  Game_Bar_destroy(Bar);
  Game_Ball_destroy(Ball);
}

void Game_update() {
  int key = getch(); /* getch()しないとシーンの表示がなされません */
  Game_Bar_update(Bar, key);
  Game_Ball_update(Ball, key);
}

void Game_draw() {
  Game_Border_draw();
  Game_Bar_draw(Bar);
  Game_Ball_draw(Ball);
}
