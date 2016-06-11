#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Menu.h"
#include "../../Util.h"
#include "../../Scene.h"

static const int MENU_Y[4] = {16, 17, 18, 19};

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
      case emenu_game_start: 
        Scene_change(eScene_game);
        break;
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

  char *menu[4] = {
    "ゲームスタート",
    "　　スコア　　",
    "　　ヘルプ　　",
    "　ゲーム終了　",
  };
  int menu_x = BreakOut_centered_unicode_str_x(menu[0]);
  int i;
  char explain[] = "↑ ↓ キーで選択、スペースキーで決定。";

  for (i = 0; i < 4; i++) {
    mvaddstr(MENU_Y[i], menu_x, menu[i]);
  }
  mvaddstr(Start_Menu_y(this->now_select), menu_x - 2, "*");

  mvaddstr(26, BreakOut_centered_unicode_str_x(explain), explain);
}

