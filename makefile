CC = gcc
CFLAGS = -c -Wall

all: Breakout

source/Scene/Start/Menu.o: source/Scene/Start/Menu.c source/Scene/Start/Menu.h
	$(CC) -c -o source/Scene/Start/Menu.o source/Scene/Start/Menu.c -lncursesw

source/Scene/Start.o: source/Scene/Start.c source/Scene/Start.h
	$(CC) -c -o source/Scene/Start.o source/Scene/Start.c -lncursesw

source/Scene.o: source/Scene.c source/Scene.h
	$(CC) -c -o source/Scene.o source/Scene.c

source/Util.o: source/Util.c source/Util.h
	$(CC) -c -o source/Util.o source/Util.c

source/main.o: source/main.c
	$(CC) -c -o source/main.o source/main.c

Breakout: source/main.o source/Scene.o source/Util.o source/Scene/Start.o source/Scene/Start/Menu.o
	$(CC) -o Breakout source/main.o source/Scene.o source/Util.o source/Scene/Start.o source/Scene/Start/Menu.o -lncursesw
	
clean:
	rm Breakout source/main.o source/Scene.o source/Util.o source/Scene/Start.o source/Scene/Start/Menu.o

