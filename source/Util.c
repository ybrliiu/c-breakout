#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <locale.h>

#include "Util.h"
#include "Config.h"

void BreakOut_exit() {
  Scene_final();
  endwin();
  curs_set(1);
  exit(0);
}

int BreakOut_centered_str_x(char *str) {
  int length = strlen(str);
  return (BREAKOUT_WIDTH / 2) - (length / 2);
}

int BreakOut_centered_unicode_str_x(char *str) {
  int length = strlen(str) / 2;
  return (BREAKOUT_WIDTH / 2) - (length / 2);
}

void BreakOut_draw_border() {
  move(0, 0);
  hline('-', BREAKOUT_WIDTH);
  move(0, 0);
  vline('|', BREAKOUT_HEIGHT + 1);
  move(0, BREAKOUT_WIDTH);
  vline('|', BREAKOUT_HEIGHT + 1);
  move(BREAKOUT_HEIGHT, 0);
  hline('-', BREAKOUT_WIDTH);
}

