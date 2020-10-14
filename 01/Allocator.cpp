#include "Allocator.hpp"


Allocator::Allocator(): buffer_ptr(nullptr), buffer_size(0), offset(0) {}

void Allocator::make_allocator(size_t max_size) {
    if(buffer_size) {
        delete[] buffer_ptr;
        buffer_size = 0;
    }
    buffer_ptr = new char[buffer_size=max_size];
}

char * Allocator::alloc(size_t size) {
    if(buffer_size - offset < size) return nullptr;
    else {
        size_t old_offset = offset;
        offset += size;
        return buffer_ptr + old_offset;
    }
}

void Allocator::reset() {
    offset = 0;
}

Allocator::~Allocator() {
    if(buffer_size) delete[] buffer_ptr;
}

