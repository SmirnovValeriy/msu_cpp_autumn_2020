#include "Matrix.hpp"
#include <cassert>
#include <vector>
#include <iomanip>

/* Creating default matrix */
bool default_matrix() {
    try {
        Matrix matrix(10, 9, 100);
        return true;
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Creating matrix with size (1, 1) */
bool one_one_matrix() {
    try {
        Matrix matrix(1, 1, 0);
        return (matrix[0][0] == 0) and (matrix[0][0] = 1 == 1);
    }
    /* any unknown exception is error */
    catch(...) {
        return false;
    }
}

/* Checking get_num_rows(), get_num_cols() methods */
bool get_num_row_functions() {
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
bool index_operator_correct() {
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
bool index_operator_incorrect_row() {
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
bool index_operator_incorrect_col() {
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
bool equality_operator() {
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
bool mul_assign_operator() {
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
bool sum_correct_sizes() {
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
bool sum_incorrect_sizes_row() {
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
bool sum_incorrect_sizes_col() {
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
bool assign_correct_sizes() {
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
bool assign_incorrect_sizes_row() {
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
bool assign_incorrect_sizes_col() {
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
bool index_operator_const() {
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
bool inequality_operator() {
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
    std::cout.width(44);
    std::cout<<std::left<<"Unittest default_matrix"<<(default_matrix() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest one_one_matrix"<<(one_one_matrix() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest get_num_row_functions"<<(get_num_row_functions() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest index_operator_correct "<<(index_operator_correct() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest index_operator_incorrect_row "<<(index_operator_incorrect_row() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest index_operator_incorrect_col "<<(index_operator_incorrect_col() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest equality_operator "<<(equality_operator() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest mul_assign_operator "<<(mul_assign_operator() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest sum_correct_sizes "<<(sum_correct_sizes() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest sum_incorrect_sizes_row "<<(sum_incorrect_sizes_row() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest sum_incorrect_sizes_col "<<(sum_incorrect_sizes_col() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest assign_correct_sizes "<<(assign_correct_sizes() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest assign_incorrect_sizes_row "<<(assign_incorrect_sizes_row() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest assign_incorrect_sizes_col "<<(assign_incorrect_sizes_col() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest index_operator_const "<<(index_operator_const() ? "OK" : "ERROR")<<std::endl;
    std::cout.width(44);
    std::cout<<std::left<<"Unittest inequality_operator "<<(inequality_operator() ? "OK" : "ERROR")<<std::endl;
    return 0;
}

