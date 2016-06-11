#include <stdio.h>

#include "./Scene/Game/Player.h"
#include "Record.h"

array_Game_Player Record_read() {
  
  array_Game_Player players;
  FILE *fp = fopen("../etc/score.dat", "rb");
  
  if (fp == NULL) {
    printf("ファイルが開けません\n");
  }
  
	fwrite(players, sizeof(Game_Player*) * 100, 1, fp);
	printf("score:%d name:%s \n", players[0]->score, players[0]->name);
	
	fclose(fp); 
	
	return players; 
}

void Record_write(array_Game_Player players) {
  
  FILE *fp = fopen("../etc/score.dat", "wb");
  
  if (fp == NULL) {
    printf("ファイルが開けません\n");
  }
  
	fwrite(players, sizeof(Game_Player*) * 100, 1, fp);
	fclose(fp);  
}

