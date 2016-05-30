#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

int main() {
  int x, y, w, h;
  char str[] = "O";
  int key;

  setlocale(LC_ALL, "");
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);

  getmaxyx(stdscr, h, w);
  y = h/2;
  x = w/2;

  while (1) {
    mvprintw(y, x, str);  

    key = getch();
    if (key == 'q') break;

    switch (key) {
      case KEY_UP:
        if (y > 0 ) { y--; }
        mvaddch(y+1, x, '|');
        break;
      case KEY_DOWN:
        if (y < h-1) { y++; }
        mvaddch(y-1, x, '|');
        break;
      case KEY_LEFT:
        if (x > 0 ) { x--; }
        mvaddch(y, x+1, '-');
        break;
      case KEY_RIGHT:
        if (x < w-1) { x++; }
        mvaddch(y, x-1, '-');
        break;
    }
  }
  endwin();
  return (0);
}
