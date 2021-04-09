CC=g++
FLAGS=-std=c++17

all: Matrix.cpp unittests.cpp
	$(CC) $(FLAGS) Matrix.cpp unittests.cpp -o test
test:
	$(CC) $(FLAGS) Matrix.cpp unittests.cpp -o test
	./test
clear:
	rm -f test

