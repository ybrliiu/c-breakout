/* 当たり判定のマップ情報を格納しているクラス */

#include "../../Config.h"

#define GAME_HIT_NO 0
#define GAME_HIT_WALL 1
#define GAME_HIT_BAR 2
#define GAME_HIT_BLOCK 3

typedef int (*array_2D)[BREAKOUT_WIDTH]; /* 二次元配列のポインタを返却するARRAY_2D型 */

array_2D Game_Hit_get_map();
