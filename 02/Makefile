CC=g++
FLAGS=-std=c++17

all: Parser.cpp unittests.cpp
	$(CC) $(FLAGS) Parser.cpp unittests.cpp -o test
test:
	$(CC) $(FLAGS) Parser.cpp unittests.cpp -o test
	./test
clear:
	rm -f test
