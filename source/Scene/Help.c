#include <ncurses.h>
#include <locale.h>

#include "Help.h"
#include "Help/Menu.h"
#include "Help/Explain.h"
#include "../Util.h"

Help_Menu* Menu;

void Help_init() {
  Menu = Help_Menu_new();
}

void Help_final() {
  Help_Menu_destroy(Menu);
}

void Help_update() {
  int key = getch();
  Help_Menu_update(Menu, key);
}

void Help_draw() {
  BreakOut_draw_border();
  Help_Menu_draw(Menu);
  Help_Explain_draw();
}
