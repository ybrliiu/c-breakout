#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "Title.h"

void Start_Title_draw() {
  mvaddstr(0, 20, "@@@@@    @@@@@@   @@@@@@@     @@     @    @         @@@@    @      @  @@@@@@@@");
  mvaddstr(1, 20, "@    @   @     @  @          @  @    @   @         @    @   @      @     @@   ");
  mvaddstr(2, 20, "@     @  @     @  @          @  @    @  @         @      @  @      @     @@   ");
  mvaddstr(3, 20, "@@@@@@   @@@@@@   @@@@@@@   @    @   @@@          @      @  @      @     @@   ");
  mvaddstr(4, 20, "@     @  @   @    @         @@@@@@   @  @         @      @  @      @     @@   ");
  mvaddstr(5, 20, "@    @   @    @   @        @      @  @   @         @    @    @    @      @@   ");
  mvaddstr(6, 20, "@@@@@    @     @  @@@@@@@  @      @  @    @         @@@@      @@@@       @@   ");

  char tmp[] = "@@@@@    @     @  @@@@@@@  @      @  @    @         @@@@      @@@@       @@   ";
  int length = strlen(tmp);
  mvprintw(7, 20, "strlen: %d", length);
}
