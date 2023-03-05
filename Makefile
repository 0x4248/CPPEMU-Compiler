#Make file for C++

CC = g++
CFLAGS = -g -Wall -std=c++11

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main