#include "BigInt.hpp"

/* BigInt from std::string and equality operator*/
bool unittest_1() {
    try {
        std::string from_1("1234567890");
        std::string from_2("-1234567890");
        BigInt num_1(from_1);
        BigInt num_2(from_2);
        return num_1 == 1234567890 and num_2 == -1234567890;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* BigInt from int64_t */
bool unittest_2() {
    try {
        int64_t from_1(1234567890);
        int64_t from_2(-1234567890);
        BigInt num_1(from_1);
        BigInt num_2(from_2);
        return num_1 == 1234567890 and num_2 == -1234567890;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Copying and moving constructors */
bool unittest_3() {
    try {
        BigInt from_1(1234567890);
        BigInt from_2(-1234567890);
        BigInt num_1(from_1);
        BigInt num_2(std::move(from_2));
        return num_1 == 1234567890 and num_2 == -1234567890;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Copying and moving operators = */
bool unittest_4() {
    try {
        BigInt from_1(1234567890);
        BigInt from_2(-1234567890);
        BigInt num_1 = from_1;
        BigInt num_2 = std::move(from_2);
        return num_1 == 1234567890 and num_2 == -1234567890;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Meaningless zeros */
bool unittest_5() {
    try {
        std::string from_1("+0000000000090");
        std::string from_2("-0000090000000");
        BigInt num_1(from_1);
        BigInt num_2(from_2);
        return num_1 == 90 and num_2 == -90000000;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Unary minus */
bool unittest_6() {
    try {
        BigInt num_1("1234567890");
        BigInt num_2("-1234567890");
        return -num_1 == num_2 and num_1 == -num_2;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Adding positive and positive */
bool unittest_7() {
    try {
        BigInt num_1("1234567890");
        BigInt num_2("1234567890");
        return (num_1 + num_2) == BigInt("2469135780");
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Substracting positive and positive */
bool unittest_8() {
    try{
        BigInt num_1("2345678901");
        BigInt num_2("1234567890");
        return (num_1 - num_2) == BigInt("1111111011");
    }
    /* any unknown exception is error */
    catch(...){
        return false;
    }
}

/* Adding negative and negative */
bool unittest_9() {
    try {
        BigInt num_1("-1234567890");
        BigInt num_2("-1234567890");
        return (num_1 + num_2) == -BigInt("2469135780");
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Substracting negative and negative */
bool unittest_10() {
    try {
        BigInt num_1("-1234567890");
        BigInt num_2("-2345678901");
        return (num_1 - num_2) == BigInt("1111111011");
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Multiplying positive and positive */
bool unittest_11() {
    try {
        BigInt num_1("1234567890");
        BigInt num_2("2345678901");
        BigInt result("2895899851425088890");
        return (num_1 * num_2) == result and (num_2 * num_1) == result;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Multiplying positive and negative */
bool unittest_12() {
    try {
        BigInt num_1("1234567890");
        BigInt num_2("-2345678901");
        BigInt result("-2895899851425088890");
        return (num_1 * num_2) == result and (num_2 * num_1) == result ;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Multiplying negative and negative */
bool unittest_13() {
    try {
        BigInt num_1("-1234567890");
        BigInt num_2("-2345678901");
        BigInt result("2895899851425088890");
        return (num_1 * num_2) == result;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Comparison operators */
bool unittest_14() {
    try {
        BigInt num_1("1234567890");
        BigInt num_2("1234577899");
        bool result = (num_1 < num_2) and (num_1 <= num_2);
        result = result and (num_2 > num_1) and (num_2 >= num_1);
        result = result and (num_1 == num_1) and (num_1 != num_2);
        return result;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

int main() {
    std::cout<<"Unittest_1 "<<(unittest_1() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_2 "<<(unittest_2() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_3 "<<(unittest_3() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_4 "<<(unittest_4() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_5 "<<(unittest_5() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_6 "<<(unittest_6() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_7 "<<(unittest_7() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_8 "<<(unittest_8() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_9 "<<(unittest_9() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_10 "<<(unittest_10() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_11 "<<(unittest_11() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_12 "<<(unittest_12() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_13 "<<(unittest_13() ? "OK" : "ERROR")<<std::endl;
    std::cout<<"Unittest_14 "<<(unittest_14() ? "OK" : "ERROR")<<std::endl;
}

