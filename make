CC=g++

FLAGS=-Wall
LIB=-lstdc++fs

makeOut:
	$(CC) $(FLAGS) main.cpp copyFiles.cpp -o copyExe $(LIB)