#Make file for C++

CC = g++
CFLAGS = -g -Wall -std=c++11
INPUT = main.cpp
OUTPUT = compiler

all: compile

compile:
	$(CC) $(CFLAGS) $(INPUT) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)