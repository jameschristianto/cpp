CC = g++
CFLAGS = -c -Wall
CVER = -std=c++11
EXEC = -o "Linked List"

MAIN = src\main.cpp
EXT1 = src\linkedlist.cpp
HDR1 = header\linkedlist.h
OBJ1 = main.o
OBJ2 = linkedlist.o
OBJS = main.o linkedlist.o

Target:$(OBJS)
	$(CC) $(OBJS) $(EXEC)
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(CVER)

$(OBJ2):$(EXT1) $(HDR1)
	$(CC) $(CFLAGS) $(EXT1) $(CVER)