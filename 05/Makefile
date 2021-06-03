CC=g++
FLAGS=-std=c++17

all: Serializer.hpp unittests.cpp
	$(CC) $(FLAGS) unittests.cpp -o test
test:
	$(CC) $(FLAGS) unittests.cpp -o test
	./test
clear:
	rm -f test
