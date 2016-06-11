#include <ncurses.h>
#include <locale.h>

#include "Score.h"
#include "Score/Menu.h"
#include "Score/Ranking.h"
#include "../Util.h"

Score_Menu* Menu;

void Score_init() {
  Menu = Score_Menu_new();
  Score_Ranking_init();
}

void Score_final() {
  Score_Menu_destroy(Menu);
}

void Score_update() {
  int key = getch();
  Score_Menu_update(Menu, key);
}

void Score_draw() {
  BreakOut_draw_border();
  Score_Menu_draw(Menu);
  Score_Ranking_draw();
}
