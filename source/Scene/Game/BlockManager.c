#include "Block.h"
#include "../../Config.h"

#define BLOCK_NUM_WIDTH 5
#define BLOCK_NUM_HEIGHT 2

static Game_Block* Blocks[BLOCK_SUM];

static int BlockManager_first_x() {

  Game_Block* example = Game_Block_new(0, 0);
  int width = Game_Block_get_width(example);
  int block_space = BREAKOUT_WIDTH / BLOCK_NUM_WIDTH;
  return BREAKOUT_WIDTH / BLOCK_NUM_WIDTH;
}

void BlockManager_init() {

  int i, y, x;
  int first_x = BREAKOUT_WIDTH / BLOCK_NUM_WIDTH;

  for (i = 0; i < BLOCK_SUM; i++) {
    Game_Block_new();
  }
}

void BlockManager_final() {
}

void BlockManager_update() {
}

void BlockManager_draw() {
}
