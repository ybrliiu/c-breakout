#include <ncurses.h>
#include <locale.h>

#include "Border.h"
#include "../../Config.h"
#include "../../Util.h"

void Game_Border_init_hit_map(int** hit_map) {
  int y, x;
  for (y = 0; y < BREAKOUT_HEIGHT; y++) {
    for (x = 0; x < BREAKOUT_WIDTH; x++) {
      if (y == 0 || y == BREAKOUT_WIDTH - 1 || x == 0 || x == BREAKOUT_HEIGHT - 1) {
        hit_map[y][x] = 1;
      }
    }
  }
}

void Game_Border_draw() {
  BreakOut_draw_border();
}
