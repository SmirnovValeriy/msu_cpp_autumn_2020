#include "Matrix.hpp"
#include <cassert>
#include <vector>

/* Creating default matrix */
bool unittest_1() {
    try {
        Matrix matrix(10, 9, 100);
        return true;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking get_num_rows(), get_num_cols() methods */
bool unittest_2() {
    try {
        Matrix matrix(20, 25, 10);
        size_t rows = matrix.get_num_rows();
        size_t cols = matrix.get_num_cols();
        return (rows == 20) and (cols == 25);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator[] with proper index */
bool unittest_3() {
    try {
        Matrix matrix(15, 15, 2);
        int64_t m_10_10 = matrix[10][10];
        matrix[10][10] = 3;
        int64_t changed = matrix[10][10];
        return (m_10_10 == 2) and (changed == 3);
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator[] with improper row index */
bool unittest_4() {
    try {
        Matrix matrix(15, 15, 2);
        int64_t m_10_10 = matrix[15][10];
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::out_of_range &oor) {
        /* Error if the exception came from another location */
        return oor.what() == std::string("[]");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator[] with improper column index */
bool unittest_5() {
    try {
        Matrix matrix(7, 7, 4);
        int64_t m_10_10 = matrix[3][10];
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::out_of_range &oor) {
        /* Error if the exception came from another location */
        return oor.what() == std::string("r[]");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator == */
bool unittest_6() {
    try {
        Matrix matrix_1(10, 10, 2);
        /* Equal matrix */
        Matrix matrix_2(10, 10, 2);
        /* Matrix with same shape but different values */
        Matrix matrix_3(10, 10, 3);
        /* Matrix with different shape */
        Matrix matrix_4(20, 20, 2);
        return (matrix_1 == matrix_2) and !(matrix_1 == matrix_3) and !(matrix_1 == matrix_4);
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator *= */
bool unittest_7() {
    try {
        Matrix matrix_1(13, 12, 2);
        return (matrix_1 *= 17) == Matrix(13, 12, 34);
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator + with proper matrices sizes*/
bool unittest_8() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(30, 32, 6);
        Matrix matrix_3(30, 32, 10);
        return (matrix_1 + matrix_2) == matrix_3;
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator + with inequal row sizes*/
bool unittest_9() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(32, 32, 6);
        matrix_1 + matrix_2;
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::invalid_argument &ia) {
        /* Error if the exception came from another location */
        return ia.what() == std::string("+");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator + with inequal column sizes*/
bool unittest_10() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(30, 28, 6);
        matrix_1 + matrix_2;
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::invalid_argument &ia) {
        /* Error if the exception came from another location */
        return ia.what() == std::string("r+");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator = with proper matrices sizes*/
bool unittest_11() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(30, 32, 6);
        Matrix matrix_3(30, 32, 0);
        matrix_3 = matrix_2 = matrix_1;
        
        return matrix_3 == matrix_1 and matrix_2 == matrix_1;
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator = with inequal row sizes*/
bool unittest_12() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(32, 32, 6);
        matrix_1 = matrix_2;
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::invalid_argument &ia) {
        /* Error if the exception came from another location */
        return ia.what() == std::string("=");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator + with inequal column sizes*/
bool unittest_13() {
    try {
        Matrix matrix_1(30, 32, 4);
        Matrix matrix_2(30, 28, 6);
        matrix_1 = matrix_2;
        /* Error if no exception was thrown */
        return false;
    }
    catch(const std::invalid_argument &ia) {
        /* Error if the exception came from another location */
        return ia.what() == std::string("r=");
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator [] for const instances: read element */
bool unittest_14() {
    try {
        const Matrix matrix_1(5, 5, 10);
        return matrix_1[0][0] == 10;
    }
    /* Any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking operator != */
bool unittest_15() {
    try {
        Matrix matrix_1(10, 10, 2);
        /* Equal matrix */
        Matrix matrix_2(10, 10, 2);
        /* Matrix with same shape but different values */
        Matrix matrix_3(10, 10, 3);
        /* Matrix with different shape */
        Matrix matrix_4(20, 20, 2);
        return !(matrix_1 != matrix_2) and (matrix_1 != matrix_3) and (matrix_1 != matrix_4);
    }
    /* Any unknown exception is error */
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
    std::cout<<"Unittest_15 "<<(unittest_15() ? "OK" : "ERROR")<<std::endl;
    return 0;
}

