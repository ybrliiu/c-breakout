#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

#include "Util.h"

void BreakOut_exit() {
  Scene_final();
  endwin();
  curs_set(1);
  exit(0);
}
