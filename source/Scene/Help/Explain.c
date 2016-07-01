#include <ncurses.h>
#include <locale.h>

#include "../../Util.h"

#define ROW 16

void Help_Explain_draw() {

  static char *explain[ROW] = {
    "ルール",
    " ",
    "バーの上に乗っているボールを跳ね返しながら全てのブロックを壊して下さい。",
    "全てのブロックを破壊できればゲームクリアです。",
    "ボールを跳ね返すことが出来ずに、下に落ちてしまうとライフが1減少します。",
    "ライフが0になるとゲームオーバーです。",
    "スコアは、破壊できたブロック数、残っているライフ量、",
    "クリアにかかった時間によって計算されます。",
    " ",
    " ",
    " ",
    "操作方法",
    " ",
    "バーを動かす：左右矢印キー",
    "ボールを発射する：スペースキー",
    "一時停止:：pキー",
  };
  int i;

  for (i = 0; i < ROW; i++) {
    mvaddstr(3 + i, BreakOut_centered_unicode_str_x(explain[i]), explain[i]);
  }
}
