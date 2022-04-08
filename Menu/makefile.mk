CC = g++
CFLAGS = -c -Wall
CVER = -std=c++11

MAIN = src\main.cpp
EXT1 = src\node.cpp
EXT2 = src\util.cpp
EXT3 = src\data.cpp
EXT4 = src\menu.cpp
HDR1 = include\node.h
HDR2 = include\util.h
HDR3 = include\data.h
HDR4 = include\menu.h
OBJ1 = main.o
OBJ2 = node.o
OBJ3 = util.o
OBJ4 = data.o
OBJ5 = menu.o
OBJS = main.o node.o util.o data.o menu.o

Target:$(OBJS)
	$(CC) $(OBJS) -o "Menu"
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(CVER)

$(OBJ2):$(EXT1) $(HDR1)
	$(CC) $(CFLAGS) $(EXT1) $(CVER)

$(OBJ3):$(EXT2) $(HDR2)
	$(CC) $(CFLAGS) $(EXT2) $(CVER)

$(OBJ4):$(EXT3) $(HDR3)
	$(CC) $(CFLAGS) $(EXT3) $(CVER)

$(OBJ5):$(EXT4) $(HDR4)
	$(CC) $(CFLAGS) $(EXT4) $(CVER)

clean: 
	rm obj/*/*.o