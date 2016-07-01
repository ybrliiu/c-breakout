CC = gcc
CFLAGS = -Wall -O0
OBJS = source/main.o source/Frame.o source/Util.o source/Scene.o source/Record.o \
 	source/Scene/Start.o source/Scene/Start/Menu.o source/Scene/Start/Title.o \
  source/Scene/Game.o source/Scene/Game/State.o \
    source/Scene/Game/PauseMenu.o source/Scene/Game/Over.o source/Scene/Game/Clear.o \
    source/Scene/Game/Border.o source/Scene/Game/Player.o source/Scene/Game/Block.o source/Scene/Game/BlockManager.o \
    source/Scene/Game/Hit.o source/Scene/Game/Bar.o source/Scene/Game/Ball.o \
	source/Scene/Help.o source/Scene/Help/Menu.o source/Scene/Help/Explain.o \
	source/Scene/Score.o source/Scene/Score/Menu.o source/Scene/Score/Ranking.o \
# glibcのバージョンが2.14以前の場合、time.h を使う際に-lrtを指定
LIBS = -lncursesw -lm -lrt

all: Breakout

# スタートシーン
source/Scene/Start/Title.o: source/Scene/Start/Title.c source/Scene/Start/Title.h
	$(CC) $(CFLAGS) -c -o source/Scene/Start/Title.o source/Scene/Start/Title.c

source/Scene/Start/Menu.o: source/Scene/Start/Menu.c source/Scene/Start/Menu.h
	$(CC) $(CFLAGS) -c -o source/Scene/Start/Menu.o source/Scene/Start/Menu.c

source/Scene/Start.o: source/Scene/Start.c source/Scene/Start.h
	$(CC) $(CFLAGS) -c -o source/Scene/Start.o source/Scene/Start.c

# ゲームシーン
source/Scene/Game/Border.o: source/Scene/Game/Border.c source/Scene/Game/Border.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Border.o source/Scene/Game/Border.c

source/Scene/Game/Player.o: source/Scene/Game/Player.c source/Scene/Game/Player.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Player.o source/Scene/Game/Player.c

source/Scene/Game/BlockManager.o: source/Scene/Game/BlockManager.c source/Scene/Game/BlockManager.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/BlockManager.o source/Scene/Game/BlockManager.c

source/Scene/Game/Block.o: source/Scene/Game/Block.c source/Scene/Game/Block.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Block.o source/Scene/Game/Block.c

source/Scene/Game/Hit.o: source/Scene/Game/Hit.c source/Scene/Game/Hit.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Hit.o source/Scene/Game/Hit.c

source/Scene/Game/Bar.o: source/Scene/Game/Bar.c source/Scene/Game/Bar.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Bar.o source/Scene/Game/Bar.c

source/Scene/Game/Ball.o: source/Scene/Game/Ball.c source/Scene/Game/Ball.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Ball.o source/Scene/Game/Ball.c

source/Scene/Game/Clear.o: source/Scene/Game/Clear.c source/Scene/Game/Clear.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Clear.o source/Scene/Game/Clear.c

source/Scene/Game/Over.o: source/Scene/Game/Over.c source/Scene/Game/Over.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game/Over.o source/Scene/Game/Over.c

source/PauseMenu/Game/PauseMenu.o: source/PauseMenu/Game/PauseMenu.c source/PauseMenu/Game/PauseMenu.h
	$(CC) $(CFLAGS) -c -o source/PauseMenu/Game/PauseMenu.o source/PauseMenu/Game/PauseMenu.c

source/State/Game/State.o: source/State/Game/State.c source/State/Game/State.h
	$(CC) $(CFLAGS) -c -o source/State/Game/State.o source/State/Game/State.c

source/Scene/Game.o: source/Scene/Game.c source/Scene/Game.h
	$(CC) $(CFLAGS) -c -o source/Scene/Game.o source/Scene/Game.c

# ヘルプシーン
source/Scene/Help/Explain.o: source/Scene/Help/Explain.c source/Scene/Help/Explain.h
	$(CC) $(CFLAGS) -c -o source/Scene/Help/Explain.o source/Scene/Help/Explain.c

source/Scene/Help/Menu.o: source/Scene/Help/Menu.c source/Scene/Help/Menu.h
	$(CC) $(CFLAGS) -c -o source/Scene/Help/Menu.o source/Scene/Help/Menu.c

source/Scene/Help.o: source/Scene/Help.c source/Scene/Help.h
	$(CC) $(CFLAGS) -c -o source/Scene/Help.o source/Scene/Help.c

# スコアシーン
source/Scene/Score/Ranking.o: source/Scene/Score/Ranking.c source/Scene/Score/Ranking.h
	$(CC) $(CFLAGS) -c -o source/Scene/Score/Ranking.o source/Scene/Score/Ranking.c

source/Scene/Score/Menu.o: source/Scene/Score/Menu.c source/Scene/Score/Menu.h
	$(CC) $(CFLAGS) -c -o source/Scene/Score/Menu.o source/Scene/Score/Menu.c

source/Scene/Score.o: source/Scene/Score.c source/Scene/Score.h
	$(CC) $(CFLAGS) -c -o source/Scene/Score.o source/Scene/Score.c

# メイン
source/Record.o: source/Record.c source/Record.h
	$(CC) $(CFLAGS) -c -o source/Record.o source/Record.c

source/Scene.o: source/Scene.c source/Scene.h
	$(CC) $(CFLAGS) -c -o source/Scene.o source/Scene.c

source/Util.o: source/Util.c source/Util.h
	$(CC) $(CFLAGS) -c -o source/Util.o source/Util.c

source/Frame.o: source/Frame.c source/Frame.h
	$(CC) $(CFLAGS) -c -o source/Frame.o source/Frame.c

source/main.o: source/main.c
	$(CC) $(CFLAGS) -c -o source/main.o source/main.c

# 
Breakout: $(OBJS)
	$(CC) -o Breakout $(OBJS) $(LIBS)

clean:
	rm Breakout $(OBJS) 

