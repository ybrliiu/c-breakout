#include <ncurses.h>
#include <locale.h>

#include "Over.h"
#include "../../Util.h"
#include "../../Config.h"
#include "../../Scene.h"

#define CHAR_HEIGHT 9

static int Title_x = 0;
static char *Title[CHAR_HEIGHT] = {
  "                                                                                    ",
  "   @@@@       @@       @    @    @@@@@@@         @@@@    @      @  @@@@@@@  @@@@@@  ", 
  "  @    @@    @  @     @ @  @ @   @              @    @   @      @  @        @     @ ", 
  " @           @  @     @ @  @ @   @             @      @   @    @   @        @     @ ", 
  " @   @@@@   @    @    @ @  @ @   @@@@@@@       @      @   @    @   @@@@@@@  @@@@@@  ", 
  " @      @   @@@@@@   @   @@   @  @             @      @    @  @    @        @   @   ", 
  "  @    @   @      @  @   @@   @  @              @    @     @  @    @        @    @  ", 
  "   @@@@    @      @  @        @  @@@@@@@         @@@@       @@     @@@@@@@  @     @ ",  
  "                                                                                    ",
};

void Game_Over_init() {
  Title_x = BreakOut_centered_str_x(Title[0]);
}

void Game_Over_update(int key) {
  switch (key) {
    case 'y':
      Scene_init();
      break;
    case 'n':
      Scene_change(eScene_start);
      break;
  }
}

void Game_Over_draw() {

  char explain[] = "もう一度挑戦しますか？[y/n]";
  int i;

  mvaddstr(20, BreakOut_centered_unicode_str_x(explain), explain);

  for (i = 0; i < CHAR_HEIGHT; i++) {
    mvaddstr(i + 8, Title_x, Title[i]);
  }
}
