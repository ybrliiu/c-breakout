#include <ncurses.h>
#include <locale.h>

#include "Start.h"
#include "Start/Menu.h"
#include "Start/Title.h"
#include "../Util.h"

Start_Menu* Menu;

void Start_init() {
  Start_Title_init();
  Menu = Start_Menu_new();
}

void Start_final(){
  Start_Menu_destroy(Menu);
}

void Start_update() {
  int key = getch(); /* getch()関数をシーンのどこかで使わなければ画面表示されないようだ。。 */
  Start_Menu_update(Menu, key);
}

void Start_draw() {
  BreakOut_draw_border();
  Start_Title_draw();
  Start_Menu_draw(Menu);
}

