CC = g++
CFLAGS = -c -Wall
CVER = -std=c++11
EXEC = -o "Hash Table 2"

MAIN = src\main.cpp
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) $(EXEC)
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(CVER)