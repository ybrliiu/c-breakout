#include <stdio.h>

#include "./Scene/Game/Player.h"
#include "Record.h"
#include "Util.h"

#define SCORE_FILE "./etc/score.dat"

array_Game_Player Record_read() {
  
  array_Game_Player players;
  FILE *fp = fopen(SCORE_FILE, "rb");
  
  if (fp == NULL) {
    printf("ファイルが開けません\n");
  }
  
	fread(players, sizeof(Game_Player*) * 100, 1, fp);
	printf("score:%d name:%s \n", players[0]->score, players[0]->name);
	
	fclose(fp); 

	return players; 
}

void Record_write(Game_Player* player) {
  
  Game_Player* players[RECORD_MAX];
  FILE *fp = fopen(SCORE_FILE, "wb"); /* fopen関数では実行した場所からのパスになる */
  
  if (fp == NULL) {
    fprintf(stderr, "ファイルが開けません\n");
    BreakOut_exit();
  }
  
	fwrite(players, sizeof(Game_Player*) * 100, 1, fp);
  players[0] = player;
	fclose(fp);  
}

