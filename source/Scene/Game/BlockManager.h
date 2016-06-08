/* ブロックオブジェクト管理クラス */

#ifndef GAME_BLOCKMANAGER_H
#define GAME_BLOCKMANAGER_H

#include "Block.h"

void Game_BlockManager_init();
void Game_BlockManager_final();

Game_Block* Game_BlockManager_get_block(int y, int x);
int Game_BlockManager_remain_blocks();

void Game_BlockManager_update();
void Game_BlockManager_draw();

#endif
