CC = g++
CFLAGS = -c -Wall
CVER = -std=c++11

MAIN = src\main.cpp
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) -o "Goto Statement"
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(CVER)