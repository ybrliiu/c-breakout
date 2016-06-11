/* スコアデータ関連モジュール */

#ifndef RECORD_H
#define RECORD_H

#define RECORD_MAX 100

typedef Game_Player (*array_Game_Player)[RECORD_MAX]; /* プレイヤー構造体のポインタ型の配列 */

array_Game_Player Record_read();
void Record_write(array_Game_Player players);

#endif
