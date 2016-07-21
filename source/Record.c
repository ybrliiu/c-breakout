#include <stdio.h>
#include <stdlib.h>

#include "./Scene/Game/Player.h"
#include "Record.h"
#include "Util.h"

#define SCORE_FILE "./etc/score.dat"

static Game_Player Players[RECORD_MAX];

void Record_error() {
  fprintf(stderr, "ファイルが開けません\n");
  BreakOut_exit();
}

static Game_Player* Record_init_data() {

  Game_Player* init_player = Game_Player_new();
  static Game_Player players[RECORD_MAX];
  int i;

  for (i = 0; i < RECORD_MAX; i++) {
    players[i] = (*init_player);
  }

  return players;
}

static void Record_enqueue(Game_Player record_player) {
  Players[RECORD_MAX - 1] = record_player;
}

static Game_Player Record_dequeue() {

  Game_Player tip = Players[0];
  Game_Player* empty = Game_Player_new();
  int i;

  for (i = 1; i < RECORD_MAX; i++) {
    Players[i - 1] = Players[i];
  }
  Players[RECORD_MAX - 1] = (*empty);

  return tip;
}

static int Record_compare_score(const void *p, const void *q) {
  return ((Game_Player*)q)->score - ((Game_Player*)p)->score;
}

Game_Player* Record_read() {

  /* perlなどGCある言語と違い、ローカル変数を参照渡しにしても関数から抜ければローカル変数が消えてしまうので、staticつけて静的変数にする */
  static Game_Player players[RECORD_MAX];
  FILE *fp = fopen(SCORE_FILE, "rb");
  
  if (fp == NULL) {
    Record_error();
  }
  
  fread(players, sizeof(Game_Player) * RECORD_MAX, 1, fp);
  fclose(fp); 

  qsort(players, RECORD_MAX, sizeof(Game_Player), Record_compare_score);

  return players; 
}

void Record_write(Game_Player* player) {
  
  FILE *fp = fopen(SCORE_FILE, "rb"); /* fopen関数では実行した場所からのパスになる */
  if (fp == NULL) {
    Record_error();
  }
  fread(Players, sizeof(Game_Player) * RECORD_MAX, 1, fp);
  fclose(fp);

  fp = fopen(SCORE_FILE, "wb");
  if (fp == NULL) {
    Record_error();
  }
  Record_enqueue( (*player) ); /* (*player) = デリファレンス(ポインタ->実際の値に変換) */
  Record_dequeue();
  fwrite(Players, sizeof(Game_Player) * RECORD_MAX, 1, fp);
  fclose(fp);  
}

