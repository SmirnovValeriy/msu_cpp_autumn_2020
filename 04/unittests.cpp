#include "BigInt.hpp"

/* BigInt from std::string and equality operator*/
bool BigInt_from_string() {
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
bool BigInt_from_int64() {
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
bool copying_moving_constructors() {
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
bool assignment_operators() {
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
bool meaningless_zeros() {
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
bool unary_minus() {
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
bool positive_positive_sum() {
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
bool positive_positive_diff() {
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
bool negative_negative_sum() {
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
bool negative_negative_diff() {
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
bool positive_positive_mul() {
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
bool positive_negative_mul() {
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
bool negative_negative_mul() {
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
bool comparison_operators() {
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
    std::cout.width(44);
    std::cout<<std::left<<"Unittest BigInt_from_string "<<(BigInt_from_string() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest BigInt_from_int64 "<<(BigInt_from_int64() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest copying_moving_constructors "<<(copying_moving_constructors() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest assignment_operators "<<(assignment_operators() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest meaningless_zeros "<<(meaningless_zeros() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest unary_minus "<<(unary_minus() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest positive_positive_sum "<<(positive_positive_sum() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest positive_positive_diff "<<(positive_positive_diff() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest negative_negative_sum "<<(negative_negative_sum() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest negative_negative_diff "<<(negative_negative_diff() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest positive_positive_mul "<<(positive_positive_mul() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest positive_negative_mul "<<(positive_negative_mul() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest negative_negative_mul "<<(negative_negative_mul() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest comparison_operators "<<(comparison_operators() ? "OK" : "ERROR")<<std::endl;
}
