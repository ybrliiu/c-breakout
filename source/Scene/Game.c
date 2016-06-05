#include <ncurses.h>
#include <locale.h>

#include "Game.h"
#include "Game/Border.h"
#include "Game/Player.h"
#include "Game/Block.h"
#include "Game/Bar.h"
#include "Game/Ball.h"

/* 当たり判定のデバッグに使用(Game_Hit_draw())
#include "Game/Hit.h"
*/

Game_Bar* Bar;
Game_Ball* Ball;

void Game_init() {
  Game_Border_init();
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
  Game_Ball_update(Ball, key, Bar);
}

void Game_draw() {
  Game_Border_draw();
  Game_Bar_draw(Bar);
  Game_Ball_draw(Ball);
}
