#include "BlockManager.h"
#include "../../Config.h"

#define BLOCK_NUM_WIDTH 5
#define BLOCK_NUM_HEIGHT 2
#define BLOCK_NUM BLOCK_NUM_WIDTH * BLOCK_NUM_HEIGHT

static Game_Block* Blocks[BLOCK_NUM];
static const int BLOCK_SPACE = BREAKOUT_WIDTH / BLOCK_NUM_WIDTH;

static int Game_BlockManager_space_around_block() {

  Game_Block* example = Game_Block_new(0, 0);
  int width = Game_Block_get_width(example);
  Game_Block_destroy(example);

  return (BLOCK_SPACE - width) / 2;
}

void Game_BlockManager_init() {

  int y, x;
  int block_num = 0;
  int block_x = Game_BlockManager_space_around_block();

  for (y = 1; y <= BLOCK_NUM_HEIGHT; y++) {
    for (x = 0; x < BREAKOUT_WIDTH; x += BLOCK_SPACE) {
      Blocks[block_num] = Game_Block_new(5 + (y * 4), x + block_x);
      block_num++;
    }
  }

}

void Game_BlockManager_final() {
  int i;
  for (i = 0; i < BLOCK_NUM; i++) {
    Game_Block_destroy(Blocks[i]);
  }
}

Game_Block* Game_BlockManager_get_block(int y, int x) {

  int i;
  Game_Block* block = {0};

  for (i = 0; i < BLOCK_NUM; i++) {
    if (Game_Block_is_collision(Blocks[i], y, x)) {
      return Blocks[i];
    }
  }

  return block;
}

int Game_BlockManager_remain_blocks() {

  int i;
  int count = 0;

  for (i = 0; i < BLOCK_NUM; i++) {
    if (!Game_Block_is_broken(Blocks[i])) {
      count++;
    }
  }
  return count;
}

void Game_BlockManager_update() {
  int i;
  for (i = 0; i < BLOCK_NUM; i++) {
    Game_Block_update(Blocks[i]);
  }
}

void Game_BlockManager_draw() {
  int i;
  for (i = 0; i < BLOCK_NUM; i++) {
    Game_Block_draw(Blocks[i]);
  }
}
