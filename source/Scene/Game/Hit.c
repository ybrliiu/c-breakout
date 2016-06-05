#include "../../Config.h"
#include "Hit.h"

static int Hit_map[BREAKOUT_HEIGHT][BREAKOUT_WIDTH] = { {0} };

array_2D Game_Hit_get_map() {
  return Hit_map;
}

