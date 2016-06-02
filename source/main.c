#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

#include "Scene.h"

void BreakOut_setup() {
  setlocale(LC_ALL, "");
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  timeout(0);  /* キー入力も待ち時間 */
  keypad(stdscr, TRUE);
}

void BreakOut_quit() {
  endwin();
  curs_set(1);
}

int main() {

  BreakOut_setup();
  Scene_init();

  while (1) {
    Scene_update();
    Scene_draw();
  }

  Scene_final();
  BreakOut_quit();
  return 0;
}
