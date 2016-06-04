CC = gcc
OBJS = source/main.o source/Frame.o source/Util.o source/Scene.o \
 	source/Scene/Start.o source/Scene/Start/Menu.o source/Scene/Start/Title.o \
	source/Scene/Game.o source/Scene/Game/Bar.o source/Scene/Game/Ball.o \
	source/Scene/Help.o \
	source/Scene/Score.o \
# glibcのバージョンが2.14以前の場合、time.h を使う際に-lrtを指定
LIBS = -lncursesw -lm -lrt

all: Breakout

# スタートシーン
source/Scene/Start/Title.o: source/Scene/Start/Title.c source/Scene/Start/Title.h
	$(CC) -c -o source/Scene/Start/Title.o source/Scene/Start/Title.c

source/Scene/Start/Menu.o: source/Scene/Start/Menu.c source/Scene/Start/Menu.h
	$(CC) -c -o source/Scene/Start/Menu.o source/Scene/Start/Menu.c

source/Scene/Start.o: source/Scene/Start.c source/Scene/Start.h
	$(CC) -c -o source/Scene/Start.o source/Scene/Start.c

# ゲームシーン
source/Scene/Game/Ball.o: source/Scene/Game/Ball.c source/Scene/Game/Ball.h
	$(CC) -c -o source/Scene/Game/Ball.o source/Scene/Game/Ball.c

source/Scene/Game/Bar.o: source/Scene/Game/Bar.c source/Scene/Game/Bar.h
	$(CC) -c -o source/Scene/Game/Bar.o source/Scene/Game/Bar.c

source/Scene/Game.o: source/Scene/Game.c source/Scene/Game.h
	$(CC) -c -o source/Scene/Game.o source/Scene/Game.c

# ヘルプシーン
source/Scene/Help.o: source/Scene/Help.c source/Scene/Help.h
	$(CC) -c -o source/Scene/Help.o source/Scene/Help.c

# スコアシーン
source/Scene/Score.o: source/Scene/Score.c source/Scene/Score.h
	$(CC) -c -o source/Scene/Score.o source/Scene/Score.c

# メイン
source/Scene.o: source/Scene.c source/Scene.h
	$(CC) -c -o source/Scene.o source/Scene.c

source/Util.o: source/Util.c source/Util.h
	$(CC) -c -o source/Util.o source/Util.c

source/Frame.o: source/Frame.c source/Frame.h
	$(CC) -c -o source/Frame.o source/Frame.c

source/main.o: source/main.c
	$(CC) -c -o source/main.o source/main.c

# 
Breakout: $(OBJS)
	$(CC) -o Breakout $(OBJS) $(LIBS)

clean:
	rm Breakout $(OBJS) 

