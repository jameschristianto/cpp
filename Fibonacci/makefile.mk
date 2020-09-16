CC = g++
CFLAGS = -c -Wall

MAIN = src\main.cpp
OBJ1 = main.o

Target:$(OBJ1)
	$(CC) $(OBJ1) -o "Fibonacci"
	
$(OBJ1):$(MAIN)
	$(CC) $(CFLAGS) $(MAIN)