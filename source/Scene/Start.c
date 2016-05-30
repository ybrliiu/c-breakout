#include "Start.h"

#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

//変数宣言
static int MENU_Y[3] = {10, 11, 12}; /* メニューのy座標 */
static int MENU_X = 20; /* メニューのx座標 */
typedef enum {
  emenu_game,
  emenu_config,
  emenu_start,
  emenu_num,
} emenu;
static int nowSelect = emenu_game;
static int beforeSelect = emenu_game;

//メニュー画面初期化
void Start_init() {
}

//メニュー画面終了処理
void Start_final(){
  nowSelect = emenu_game;
}


//メニュー画面更新
static int key = 0;
void Start_update() {

  key = getch();

  if (key == KEY_DOWN) {
    beforeSelect = nowSelect;
    nowSelect = (nowSelect + 1) % emenu_num;
  }
  if (key == KEY_UP) {
    beforeSelect = nowSelect;
    nowSelect = (nowSelect + (emenu_num - 1)) % emenu_num;
  }
  /*
  if(button_get(KEY_INPUT_4) == 1){ //Oボタン押されたら
    switch(nowSelect){
      case emenu_game:
        scene_changeScene(scene_game);
        game_gamestart(0);
        break;
      case emenu_config:
        scene_changeScene(scene_menu);
        break;
      case emenu_start:
        scene_changeScene(scene_start);
        break;
    }
  }
  */

}

static int y = 10;
static int x = 10;
//メニュー画面描画
void Start_draw() {

  mvaddstr(y, x, "       ");
  switch (key) {
    case KEY_RIGHT:
      x++;
      break;
    case KEY_LEFT:
      x--;
  }
  mvaddstr(y, x, "=======");

  int y = 0;
  
  mvaddstr(0, 0, "メニュー画面です。");
  mvaddstr(1, 0, "↑ ↓ キーで選択、スペースキーで決定。");
  
  //メニュー部
  mvaddstr(MENU_Y[0], MENU_X, "ゲームスタート");
  mvaddstr(MENU_Y[1], MENU_X, "スコア");
  mvaddstr(MENU_Y[2], MENU_X, "ヘルプ");

  switch (beforeSelect) { //選択箇所によって描画変更
    case emenu_game:
      y = MENU_Y[0];
      break;
    case emenu_config:
      y = MENU_Y[1];
      break;
    case emenu_start:
      y = MENU_Y[2];
      break;
  }
  mvaddstr(y, MENU_X-2, " "); //選択マーク

  switch (nowSelect) { //選択箇所によって描画変更
    case emenu_game:
      y = MENU_Y[0];
      break;
    case emenu_config:
      y = MENU_Y[1];
      break;
    case emenu_start:
      y = MENU_Y[2];
      break;
  }
  mvaddstr(y, MENU_X-2, "*"); //選択マーク
}
