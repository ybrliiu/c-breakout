#include <ncurses.h>
#include <locale.h>

#include "Game.h"
#include "Game/Bar.h"
#include "../Util.h"

Game_Bar* Bar;

void Game_init() {
  Bar = Game_Bar_new();
}

void Game_final() {
  Game_Bar_destroy(Bar);
}

void Game_update() {
  int key = getch(); /* getch()しないとシーンの表示がなされません */
  Game_Bar_update(Bar, key);
}

void Game_draw() {
  mvaddstr(10, 10, "表示されていますか");
  BreakOut_draw_border();
  Game_Bar_draw(Bar);
}
