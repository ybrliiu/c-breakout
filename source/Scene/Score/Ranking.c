#include <ncurses.h>
#include <locale.h>

#include "Ranking.h"
#include "../Game/Player.h"
#include "../../Record.h"

static Game_Player* Players;

void Score_Ranking_init() {
  Players = Record_read();
}

void Score_Ranking_draw() {
  
  int i;
  char name[50];

  for (i = 0; i < 1; i++) {
    mvprintw(i + 5, 40, "名前: %s スコア: %d", Players[0].name, Players[0].score);
  }
}
