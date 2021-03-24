#include <iostream>

#ifndef allocator_hpp
#define allocator_hpp

class Allocator {
private:
    char * buffer_ptr;
    size_t buffer_size;
    size_t offset;
    
public:
    Allocator();
    void make_allocator(size_t max_size);
    char * alloc(size_t size);
    void reset();
    ~Allocator();
};

#endif

