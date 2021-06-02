CC=g++
FLAGS=-std=c++17

all: BigInt.cpp unittests.cpp
	$(CC) $(FLAGS) BigInt.cpp unittests.cpp -o test
test:
	$(CC) $(FLAGS) BigInt.cpp unittests.cpp -o test
	./test
clear:
	rm -f test
