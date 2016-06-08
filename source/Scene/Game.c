#include <ncurses.h>
#include <locale.h>

#include "Game.h"
#include "Game/State.h"
#include "Game/PauseMenu.h"
#include "Game/Border.h"
#include "Game/Player.h"
#include "Game/Block.h"
#include "Game/Bar.h"
#include "Game/Ball.h"

/* 当たり判定のデバッグに使用(Game_Hit_draw()) */
#include "Game/Hit.h"

Game_State* State;
Game_PauseMenu* Menu;
Game_Bar* Bar;
Game_Ball* Ball;

void Game_init() {
  State = Game_State_new();
  Game_Border_init();
  Menu = Game_PauseMenu_new();
  Bar = Game_Bar_new();
  Ball = Game_Ball_new(Bar);
}

void Game_final() {
  Game_State_destroy(State);
  Game_PauseMenu_destroy(Menu);
  Game_Bar_destroy(Bar);
  Game_Ball_destroy(Ball);
}

void Game_update_game_state(int key) {
  switch (key) {
    case 'p':
      Game_State_change(State, eGame_State_pause);
      break;
  }
}

void Game_update() {

  int key = getch(); /* getch()しないとシーンの表示がなされません */
  
  Game_update_game_state(key);

  switch (Game_State_now(State)) {
    case eGame_State_play:
      /* ボールとバーの順番逆だと上手く行かない */
      Game_Ball_update(Ball, key, Bar);
      Game_Bar_update(Bar, key);
      break;
    case eGame_State_pause:
      Game_PauseMenu_update(Menu, key, State);
      break;
  }
}

void Game_draw() {

  Game_Border_draw();
  Game_Bar_draw(Bar);
  Game_Ball_draw(Ball);

  if (Game_State_now(State) == eGame_State_pause) {
    Game_PauseMenu_draw(Menu);
  }

}
