CC = gcc
CFLAGS = -c -Wall

all: Breakout


source/Scene/Start.o: source/Scene/Start.c source/Scene/Start.h
	$(CC) -c -o source/Scene/Start.o source/Scene/Start.c -lncursesw

source/Scene.o: source/Scene.c source/Scene.h source/Scene/Start.h
	$(CC) -c -o source/Scene.o source/Scene.c

source/main.o: source/main.c source/Scene.h
	$(CC) -c -o source/main.o source/main.c

Breakout: source/main.o source/Scene.o source/Scene/Start.o
	$(CC) -o Breakout source/main.o source/Scene.o source/Scene/Start.o -lncursesw
	
clean:
	rm Breakout source/Scene.o
