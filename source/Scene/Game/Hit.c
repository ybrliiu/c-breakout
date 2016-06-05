#include <ncurses.h>

#include "../../Config.h"
#include "Hit.h"

static int Hit_map[BREAKOUT_HEIGHT][BREAKOUT_WIDTH] = { {0} };

array_2D Game_Hit_get_map() {
  return Hit_map;
}

void Game_Hit_draw() {
  int y, x;
  for (y = 0; y < BREAKOUT_HEIGHT; y++) {
    for (x = 0; x < BREAKOUT_WIDTH; x++) {
      mvprintw(y, x, "%d", Hit_map[y][x]);
    }
  }
}
