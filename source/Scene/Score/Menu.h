/* メニュークラス */

#ifndef SCORE_MENU_H
#define SCORE_MENU_H

typedef struct {
  int now_select;
} Score_Menu;

Score_Menu* Score_Menu_new();
void Score_Menu_destroy(Score_Menu* this);

void Score_Menu_update(Score_Menu* this, int key);
void Score_Menu_draw(Score_Menu* this);

#endif
