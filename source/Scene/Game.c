#include <ncurses.h>
#include <locale.h>

#include "Game.h"
#include "Game/State.h"
#include "Game/PauseMenu.h"
#include "Game/Over.h"
#include "Game/Clear.h"
#include "Game/Border.h"
#include "Game/Player.h"
#include "Game/BlockManager.h"
#include "Game/Bar.h"
#include "Game/Ball.h"

/* 当たり判定のデバッグに使用(Game_Hit_draw()) */
#include "Game/Hit.h"

Game_PauseMenu* Menu;
Game_Player* Player;
Game_Bar* Bar;
Game_Ball* Ball;

void Game_init() {
  Game_State_init();
  Menu = Game_PauseMenu_new();
  Game_Over_init();
  Game_Clear_init();
  Game_Border_init();
  Player = Game_Player_new();
  Game_BlockManager_init();
  Bar = Game_Bar_new();
  Ball = Game_Ball_new(Bar);
}

void Game_final() {
  Game_PauseMenu_destroy(Menu);
  Game_Player_destroy(Player);
  Game_BlockManager_final();
  Game_Bar_destroy(Bar);
  Game_Ball_destroy(Ball);
}

void Game_update() {

  int key = 0;
    
  if (Game_State_now() != eGame_State_game_clear) {
    key = getch(); /* getch()しないとシーンの表示がなされません */
  }
  
  Game_State_update(key);

  switch (Game_State_now()) {
    case eGame_State_play:
      Game_Player_update(Player, key);
      Game_BlockManager_update();
      Game_Ball_update(Ball, key, Bar, Player); /* ボールとバーの位置逆にしない */
      Game_Bar_update(Bar, key);
      break;
    case eGame_State_pause:
      Game_PauseMenu_update(Menu, key);
      break;
    case eGame_State_game_over:
      Game_Over_update();
      break;
    case eGame_State_game_clear:
      Game_Clear_update(Player);
      break;
  }
}

void Game_draw() {

  Game_Border_draw();
  Game_Player_draw(Player);
  Game_BlockManager_draw();
  Game_Bar_draw(Bar);
  Game_Ball_draw(Ball);

  switch (Game_State_now()) {
    case eGame_State_pause:
      Game_PauseMenu_draw(Menu);
      break;
    case eGame_State_game_over:
      Game_Over_draw();
      break;
    case eGame_State_game_clear:
      Game_Clear_draw();
      break;
  }

}
