CC = x86_64-w64-mingw32-g++
CFLAGS = -c -Wall
CVER = -std=c++11

MAIN = src\main.cpp
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) -o "Mutex"
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(CVER)