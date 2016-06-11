#include <stdio.h>

#include "./Scene/Game/Player.h"
#include "Record.h"
#include "Util.h"

#define SCORE_FILE "./etc/score.dat"

void Record_error() {
  fprintf(stderr, "ファイルが開けません\n");
  BreakOut_exit();
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

	return players; 
}

void Record_write(Game_Player* player) {
  
  Game_Player players[RECORD_MAX];
  FILE *fp = fopen(SCORE_FILE, "wb"); /* fopen関数では実行した場所からのパスになる */
  
  if (fp == NULL) {
    Record_error();
  }
  
  players[0] = (*player); /* デリファレンス(ポインタ->実際の値に変換) */

	fwrite(players, sizeof(Game_Player) * RECORD_MAX, 1, fp);
	fclose(fp);  
}

