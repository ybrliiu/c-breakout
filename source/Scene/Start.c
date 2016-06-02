#include "Start.h"
#include "Start/Menu.h"

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

Start_Menu* Menu;

//メニュー画面初期化
void Start_init() {
  Menu = Start_Menu_new();
}

//メニュー画面終了処理
void Start_final(){
  Start_Menu_destroy(Menu);
}


//メニュー画面更新
void Start_update() {

  int key = getch();
  Start_Menu_update(Menu, key);

}

void Start_draw() {
  
  Start_Menu_draw(Menu);

}

