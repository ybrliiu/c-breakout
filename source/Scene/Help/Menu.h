/* メニュークラス */

#ifndef HELP_MENU_H
#define HELP_MENU_H

typedef struct {
  int now_select;
} Help_Menu;

Help_Menu* Help_Menu_new();
void Help_Menu_destroy(Help_Menu* this);

void Help_Menu_update(Help_Menu* this, int key);
void Help_Menu_draw(Help_Menu* this);

#endif
