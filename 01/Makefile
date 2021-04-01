CC=g++

all: Allocator.cpp unittests.cpp
	$(CC) Allocator.cpp unittests.cpp -o test
test: Allocator.cpp unittests.cpp
	$(CC) Allocator.cpp unittests.cpp -o test
	./test
clean:
	rm -rf test
