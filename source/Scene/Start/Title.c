#include <ncurses.h>
#include <locale.h>

#include "Title.h"
#include "../../Config.h"

static int Title_x = 0;
static const char *Title[7] = {
  "@@@@@    @@@@@@   @@@@@@@     @@     @    @         @@@@    @      @  @@@@@@@@",
  "@    @   @     @  @          @  @    @   @         @    @   @      @     @@   ",
  "@     @  @     @  @          @  @    @  @         @      @  @      @     @@   ",
  "@@@@@@   @@@@@@   @@@@@@@   @    @   @@@          @      @  @      @     @@   ",
  "@     @  @   @    @         @@@@@@   @  @         @      @  @      @     @@   ",
  "@    @   @    @   @        @      @  @   @         @    @    @    @      @@   ",
  "@@@@@    @     @  @@@@@@@  @      @  @    @         @@@@      @@@@       @@   ",
};

void Start_Title_init() {
  Title_x = BreakOut_centered_str_x(Title[0]);
}

void Start_Title_draw() {
  int i;
  for (i = 0; i <= 7; i++) {
    mvaddstr(i + 4, Title_x, Title[i]);
  }
}
