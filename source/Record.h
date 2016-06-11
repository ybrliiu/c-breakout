/* スコアデータ関連モジュール */

#ifndef RECORD_H
#define RECORD_H

#define RECORD_MAX 100

Game_Player* Record_read();
void Record_write(Game_Player* player);

#endif
