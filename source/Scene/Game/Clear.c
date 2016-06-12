#include <ncurses.h>
#include <locale.h>

#include <string.h>

#include "Clear.h"
#include "../../Util.h"
#include "../../Config.h"
#include "../../Scene.h"
#include "../../Record.h"

#define CHAR_HEIGHT 7

typedef enum {
  eGame_Clear_setup,
  eGame_Clear_input,
  eGame_Clear_write,  
  
  eGame_Clear_none,
} eGame_Clear_state_manager;

static int Title_x = 0;
static char *Title[CHAR_HEIGHT] = {
  "  @@@@       @@       @    @    @@@@@@@         @@@@    @        @@@@@@@     @@     @@@@@@ ", 
  " @    @@    @  @     @ @  @ @   @              @    @   @        @          @  @    @     @", 
  "@           @  @     @ @  @ @   @             @         @        @          @  @    @     @", 
  "@   @@@@   @    @    @ @  @ @   @@@@@@@       @         @        @@@@@@@   @    @   @@@@@@ ", 
  "@      @   @@@@@@   @   @@   @  @             @         @        @         @@@@@@   @   @  ", 
  " @    @   @      @  @   @@   @  @              @    @   @        @        @      @  @    @ ", 
  "  @@@@    @      @  @        @  @@@@@@@         @@@@    @@@@@@@  @@@@@@@  @      @  @     @",  
};
static char Name[GAME_PLAYER_NAME_SIZE] = "";

void Game_Clear_init() {
  Title_x = BreakOut_centered_str_x(Title[0]);
  strcpy(Name, "");
}

static void Game_Clear_setup() {
  getch();
  timeout(-1);
  echo();
  curs_set(1);
}

static void Game_Clear_input() {
  getnstr(Name, GAME_PLAYER_NAME_SIZE - 1);
  timeout(0);
  noecho();
  curs_set(0);
}

static void Game_Clear_write(Game_Player* player) {
  getch();
  Game_Player_set_name(player, Name);
  Record_write(player);
  Scene_change(eScene_start);
}

void Game_Clear_update(Game_Player* player) {
  
  static eGame_Clear_state_manager state = eGame_Clear_setup;
  
  switch (state) {
    case eGame_Clear_setup:
      Game_Clear_setup();
      state = eGame_Clear_input;
      break;
    case eGame_Clear_input:
      Game_Clear_input();
      state = eGame_Clear_write;
      break;
    case eGame_Clear_write:
      Game_Clear_write(player);
      state = eGame_Clear_setup;
      break;
    default:
      getch();
      break;
  }

}

void Game_Clear_draw() {

  static char explain[] = "名前を入力してください（半角３０、全角１０文字以内）：";
  static int explain_x;
  int i;
  explain_x = BreakOut_centered_unicode_str_x(explain);

  for (i = 0; i < CHAR_HEIGHT; i++) {
    mvaddstr(i + 4, Title_x, Title[i]);
  }

  mvaddstr(20, explain_x, explain);
  move(22, BREAKOUT_WIDTH / 2 - 15);
}
