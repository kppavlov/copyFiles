CC=g++

FLAGS=-Wall
DEBUG=-g
LIB=-lstdc++fs

all: main.o copy.o remove.o rename.o operations.o
	$(CC) $(FLAGS) main.cpp Copy.cpp Remove.cpp Rename.cpp Operations.cpp -o runOperations $(LIB)

debug: main.o copy.o remove.o rename.o operations.o
	$(CC) $(FLAGS) $(DEBUG) main.cpp Copy.cpp Remove.cpp Rename.cpp Operations.cpp -o runOperations $(LIB)

main.o:
	$(CC) -c main.cpp

copy.o:
	$(CC) -c Copy.cpp

remove.o:
	$(CC) -c Remove.cpp

rename.o:
	$(CC) -c Rename.cpp

operations.o:
	$(CC) -c Operations.cpp