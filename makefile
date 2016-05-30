CC = gcc
CFLAGS = -c -Wall

Breakout: source/main.c
	$(CC) -o Breakout source/main.c	-lncursesw
	
clean:
	rm Breakout
