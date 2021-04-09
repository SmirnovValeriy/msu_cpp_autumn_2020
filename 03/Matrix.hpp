#include <iostream>

#ifndef matrix_hpp
#define matrix_hpp

class Row {
    size_t row_size;
    int64_t *data;
    
public:
    Row(size_t max_size, int64_t init_value=0);
    Row& operator=(const Row &row);
    int64_t& operator[](size_t i);
    const int64_t& operator[](size_t i) const;
    Row& operator*=(int64_t value);
    Row operator+(const Row &row) const;
    bool operator==(const Row &row) const;
    bool operator!=(const Row &row) const;
;    
    friend std::ostream& operator<<(std::ostream &out, const Row &row);
    ~Row();
};

class Matrix {
    size_t num_rows;
    size_t num_cols;
    Row **data;

public:
    Matrix(size_t rows_size, size_t cols_size, int64_t init_value=0);
    size_t get_num_rows() const;
    size_t get_num_cols() const;
    Matrix& operator=(const Matrix &matrix);
    Row& operator[](size_t i);
    const Row& operator[](size_t i) const;
    Matrix& operator*=(int64_t value);
    Matrix operator+(const Matrix &matrix) const;
    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;
    
    friend std::ostream& operator<<(std::ostream &out, const Matrix &matrix);
    ~Matrix();
};
#endif

