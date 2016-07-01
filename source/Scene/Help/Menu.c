#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

#include "Menu.h"
#include "../../Util.h"
#include "../../Scene.h"

#define HELP_MENU_NUM 2

static const int MENU_Y[HELP_MENU_NUM] = {16, 27};

typedef enum {
  emenu_dummy,
  emenu_return_title,

  emenu_num,
} emenu;

Help_Menu* Help_Menu_new() {

  Help_Menu* this = malloc( sizeof(Help_Menu) );
  if (this == NULL) {
    BreakOut_exit();
  }

  this->now_select = emenu_return_title;

  return this;
}

void Help_Menu_destroy(Help_Menu* this) {
  free(this);
}

void Help_Menu_update(Help_Menu* this, int key) {

  if (key == KEY_DOWN) {
    this->now_select = (this->now_select + 1) % emenu_num;
  }
  if (key == KEY_UP) {
    this->now_select = (this->now_select + (emenu_num - 1)) % emenu_num;
  } 

  if (key == ' ') {
    switch (this->now_select) {
      case emenu_return_title: 
        Scene_change(eScene_start);
        break;
      default: 
        break;
    }
  }

}

int Help_Menu_y(int place) {

  int y;

  switch (place) {
    case emenu_dummy:
      y = MENU_Y[0];
      break;
    case emenu_return_title:
      y = MENU_Y[1];
      break;
  }

  return y;
}

void Help_Menu_draw(Help_Menu* this) {

  static char *menu[HELP_MENU_NUM] = {
    "              ",
    "タイトルへ戻る",
  };
  int menu_x = BreakOut_centered_unicode_str_x(menu[0]);
  int i;

  for (i = 0; i < HELP_MENU_NUM; i++) {
    mvaddstr(MENU_Y[i], menu_x, menu[i]);
  }
  mvaddstr(Help_Menu_y(this->now_select), menu_x - 2, "*");

}

