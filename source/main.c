#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

#include "Config.h"
#include "Frame.h"
#include "Scene.h"

void BreakOut_quit() {
  endwin();
  curs_set(1);
}

void BreakOut_check_screen_size() {
  int height, width;
  getmaxyx(stdscr, height, width);
  if (width < BREAKOUT_WIDTH || height < BREAKOUT_HEIGHT) {
    BreakOut_quit();
    fprintf(stderr, "画面サイズを30×100以上にして起動してください。\n");
    exit(1);
  }
}

void BreakOut_setup() {
  setlocale(LC_ALL, "");
  initscr();
  noecho();
  cbreak();
  BreakOut_check_screen_size();
  curs_set(0);
  timeout(0);  /* キー入力も待ち時間 */
  keypad(stdscr, TRUE); /* 特殊キーマクロセット */
  Frame_init(); /* フレーム初期化 */
}

int main() {

  BreakOut_setup();
  Scene_init();

  while (1) {
    Scene_update();
    erase();
    Scene_draw();
    Frame_adjust();
  }

  Scene_final();
  BreakOut_quit();
  return 0;
}
