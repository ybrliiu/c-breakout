CC = gcc
OBJS = source/main.o source/Frame.o source/Util.o source/Scene.o source/Scene/Start.o source/Scene/Start/Menu.o source/Scene/Start/Title.o

all: Breakout

source/Scene/Start/Title.o: source/Scene/Start/Title.c source/Scene/Start/Title.h
	$(CC) -c -o source/Scene/Start/Title.o source/Scene/Start/Title.c

source/Scene/Start/Menu.o: source/Scene/Start/Menu.c source/Scene/Start/Menu.h
	$(CC) -c -o source/Scene/Start/Menu.o source/Scene/Start/Menu.c

source/Scene/Start.o: source/Scene/Start.c source/Scene/Start.h
	$(CC) -c -o source/Scene/Start.o source/Scene/Start.c

source/Scene.o: source/Scene.c source/Scene.h
	$(CC) -c -o source/Scene.o source/Scene.c

source/Util.o: source/Util.c source/Util.h
	$(CC) -c -o source/Util.o source/Util.c

source/Frame.o: source/Frame.c source/Frame.h
	$(CC) -c -o source/Frame.o source/Frame.c

source/main.o: source/main.c
	$(CC) -c -o source/main.o source/main.c

Breakout: $(OBJS)
	$(CC) -o Breakout $(OBJS) -lncursesw
	
clean:
	rm Breakout $(OBJS) 
