#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

#include "Ranking.h"
#include "../Game/Player.h"
#include "../../Util.h"
#include "../../Record.h"

static Game_Player* Players;

void Score_Ranking_init() {
  Players = Record_read();
}

void Score_Ranking_draw() {
  
  int i;
  char buffer[50];

  for (i = 0; i < 20; i++) {
    sprintf(buffer, "%d  NAME:%s  SCORE:%d  TIME:%d秒", i + 1, Players[i].name, Players[i].score, Players[i].time);
    mvprintw(i + 5, BreakOut_centered_str_x(buffer) + 2, buffer);
  }
}
