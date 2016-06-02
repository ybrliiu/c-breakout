#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

#include "Menu.h"
#include "../../Util.h"

static const int MENU_Y[4] = {10, 11, 12, 13};
static const int MENU_X = 50;

typedef enum {
  emenu_game_start,
  emenu_score,
  emenu_help,
  emenu_game_quit,
  emenu_num,
} emenu;

Start_Menu* Start_Menu_new() {
  Start_Menu* this = malloc( sizeof(Start_Menu) );
  if (this == NULL) {
    BreakOut_exit();
  }
  this->now_select = emenu_game_start;
  return this;
}

void Start_Menu_destroy(Start_Menu* this) {
  free(this);
}

void Start_Menu_update(Start_Menu* this, int key) {
  if (key == KEY_DOWN) {
    this->now_select = (this->now_select + 1) % emenu_num;
  }
  if (key == KEY_UP) {
    this->now_select = (this->now_select + (emenu_num - 1)) % emenu_num;
  } 
  if (key == ' ') {
    switch (this->now_select) {
      case emenu_game_quit: 
        BreakOut_exit();
        break;
    }
  }
}

int Start_Menu_y(int place) {

  int y;

  switch (place) {
    case emenu_game_start:
      y = MENU_Y[0];
      break;
    case emenu_score:
      y = MENU_Y[1];
      break;
    case emenu_help:
      y = MENU_Y[2];
      break;
    case emenu_game_quit:
      y = MENU_Y[3];
      break;
  }

  return y;
}

void Start_Menu_draw(Start_Menu* this) {

  mvaddstr(30, MENU_X, "↑ ↓ キーで選択、スペースキーで決定。");
  
  mvaddstr(MENU_Y[0], MENU_X, "ゲームスタート");
  mvaddstr(MENU_Y[1], MENU_X, "　　スコア　　");
  mvaddstr(MENU_Y[2], MENU_X, "　　ヘルプ　　");
  mvaddstr(MENU_Y[3], MENU_X, "　ゲーム終了　");

  mvaddstr(Start_Menu_y(this->now_select), MENU_X-2, "*");
}

