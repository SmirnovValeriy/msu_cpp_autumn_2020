#include "Allocator.hpp"
#include <cassert>


//default allocation
void unittest_1() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr = allocator.alloc(512);
    assert(ptr != nullptr);
}

//full allocation
void unittest_2() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr = allocator.alloc(1024);
    assert(ptr != nullptr);
}

//overfull allocation
void unittest_3() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr = allocator.alloc(1025);
    assert(ptr == nullptr);
}

//sequential allocation
void unittest_4() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr_1 = allocator.alloc(128);
    char * ptr_2 = allocator.alloc(128);
    char * ptr_3 = allocator.alloc(128);
    char * ptr_4 = allocator.alloc(128);
    assert(ptr_1 != nullptr);
    assert(ptr_2 != nullptr);
    assert(ptr_3 != nullptr);
    assert(ptr_4 != nullptr);
    assert(ptr_1 < ptr_2);
    assert(ptr_2 < ptr_3);
    assert(ptr_3 < ptr_4);
}

//sequential full allocation
void unittest_5() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr_1 = allocator.alloc(256);
    char * ptr_2 = allocator.alloc(256);
    char * ptr_3 = allocator.alloc(256);
    char * ptr_4 = allocator.alloc(256);
    assert(ptr_1 != nullptr);
    assert(ptr_2 != nullptr);
    assert(ptr_3 != nullptr);
    assert(ptr_4 != nullptr);
    assert(ptr_1 < ptr_2);
    assert(ptr_2 < ptr_3);
    assert(ptr_3 < ptr_4);
}

//sequential overfull allocation
void unittest_6() {
    Allocator allocator;
    allocator.make_allocator(1024);
    char * ptr_1 = allocator.alloc(128);
    char * ptr_2 = allocator.alloc(256);
    char * ptr_3 = allocator.alloc(512);
    char * ptr_4 = allocator.alloc(1024);
    assert(ptr_1 != nullptr);
    assert(ptr_2 != nullptr);
    assert(ptr_3 != nullptr);
    assert(ptr_1 < ptr_2);
    assert(ptr_2 < ptr_3);
    assert(ptr_4 == nullptr);
}

//full allocation after reset
void unittest_7() {
    Allocator allocator;
    allocator.make_allocator(2048);
    char * ptr_1 = allocator.alloc(2048);
    allocator.reset();
    char * ptr_2 = allocator.alloc(2048);
    assert(ptr_1 != nullptr);
    assert(ptr_2 != nullptr);
    assert(ptr_1 == ptr_2);
}

//allocation with no make_allocator() call
void unittest_8() {
    Allocator allocator;
    char * ptr_1 = allocator.alloc(2048);
    assert(ptr_1 == nullptr);
}

int main() {
    std::cout<<"Unittest_1 ";
    unittest_1();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_2 ";
    unittest_2();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_3 ";
    unittest_3();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_4 ";
    unittest_4();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_5 ";
    unittest_5();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_6 ";
    unittest_6();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_7 ";
    unittest_7();
    std::cout<<"OK"<<std::endl;
    std::cout<<"Unittest_8 ";
    unittest_8();
    std::cout<<"OK"<<std::endl;
    std::cout<<"SUCCESS!"<<std::endl;
    return 0;
}
