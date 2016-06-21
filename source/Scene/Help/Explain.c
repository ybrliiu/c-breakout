#include <ncurses.h>
#include <locale.h>

void Help_Explain_draw() {

  static char *explain[10] = {
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  };

  int i;

  for (i = 0; i < 10; i++) {
    mvaddstr(8 + i, BreakOut_centered_unicode_str_x(explain[i]), explain[i]);
  }
}
