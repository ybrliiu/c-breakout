#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "PauseMenu.h"
#include "State.h"
#include "../../Util.h"
#include "../../Scene.h"

#define MENU_ITEM 2

typedef enum {
  emenu_resume,
  emenu_return_title,

  emenu_sum,
} emenu;

static const int MENU_Y[MENU_ITEM] = {16, 17};

Game_PauseMenu* Game_PauseMenu_new() {
  Game_PauseMenu* this = malloc( sizeof(Game_PauseMenu) );
  if (this == NULL) {
    BreakOut_exit();
  }
  this->now_select = emenu_resume;
  return this;
}

void Game_PauseMenu_destroy(Game_PauseMenu* this) {
  free(this);
}

void Game_PauseMenu_update(Game_PauseMenu* this, int key) {
  if (key == KEY_DOWN) {
    this->now_select = (this->now_select + 1) % emenu_sum;
  }
  if (key == KEY_UP) {
    this->now_select = (this->now_select + (emenu_sum - 1)) % emenu_sum;
  } 
  if (key == ' ') {
    switch (this->now_select) {
      case emenu_resume: 
        Game_State_change(eGame_State_play);
        break;
      case emenu_return_title: 
        Scene_change(eScene_start);
        break;
    }
  }
}

int Game_PauseMenu_y(int place) {

  int y;

  switch (place) {
    case emenu_resume:
      y = MENU_Y[0];
      break;
    case emenu_return_title:
      y = MENU_Y[1];
      break;
  }

  return y;
}

void Game_PauseMenu_draw(Game_PauseMenu* this) {

  static char *menu[MENU_ITEM] = {
    "　ゲーム再開　",
    "タイトルへ戻る",
  };
  int menu_x = BreakOut_centered_unicode_str_x(menu[0]);
  static char explain[] = "一時停止中！！";
  int i;

  for (i = 0; i < MENU_ITEM; i++) {
    mvaddstr(MENU_Y[i], menu_x, menu[i]);
  }
  mvaddstr(Game_PauseMenu_y(this->now_select), menu_x - 2, "*");

  mvaddstr(12, BreakOut_centered_unicode_str_x(explain), explain);
}

