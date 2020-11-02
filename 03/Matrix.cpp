#include "Matrix.hpp"

/* Row class methods implementation */
Row::Row(const size_t max_size, const int64_t init_value): row_size(max_size), data(new int64_t[max_size]) {
    for(size_t i=0; i<max_size; i++) data[i] = init_value;
}

Row& Row::operator=(const Row &row) {
    if(row_size != row.row_size) throw std::invalid_argument("r=");
    for(size_t i=0; i<row_size; i++) data[i] = row.data[i];
    return *this;
}

int64_t& Row::operator[](const size_t i) {
    if(i >= row_size) throw std::out_of_range("r[]");
    return data[i];
}

const int64_t& Row::operator[](const size_t i) const {
    if(i >= row_size) throw std::out_of_range("r[]");
    return data[i];
}

std::ostream& operator<<(std::ostream &out, const Row &row) {
    for(size_t i=0; i<row.row_size; i++) out<<row.data[i]<<' ';
    return out;
}

Row& Row::operator*=(const int64_t value) {
    for(size_t i=0; i<row_size; i++) data[i] *= value;
    return *this;
}

Row Row::operator+(const Row &row) const {
    if(row_size != row.row_size) throw std::invalid_argument("r+");
    Row row_return(row_size, 0);
    for(size_t i=0; i<row_size; i++) row_return.data[i] = data[i] + row.data[i];
    return row_return;
}

bool Row::operator==(const Row &row) const {
    if(row_size != row.row_size) return false;
    for(int i=0; i<row_size; i++)
        if(data[i] != row.data[i]) return false;
    return true;
}

bool Row::operator!=(const Row &row) const {
    return not(*this == row);
}

Row::~Row() {
    delete[] data;
}

/* Matrix class methods implementation */
Matrix::Matrix(const size_t rows_size, const size_t cols_size, const int64_t init_value): num_rows(rows_size), 
                                                                                             num_cols(cols_size), 
                                                                                             data(new Row* [rows_size]) {
    for(size_t i=0; i<rows_size; i++) {
        data[i] = new Row(cols_size, init_value);
    }                          
}
                                                                                           
size_t Matrix::get_num_rows() const {
    return num_rows; 
}

size_t Matrix::get_num_cols() const {
    return num_cols;
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    if(num_rows != matrix.num_rows) throw std::invalid_argument("=");
    for(size_t i=0; i<num_rows; i++) {
        *(data[i]) = *(matrix.data[i]);
    }
    return *this;
}

Row& Matrix::operator[](const size_t i) {
    if(i >= num_rows) throw std::out_of_range("[]");
    return *(data[i]);
}

const Row& Matrix::operator[](const size_t i) const {
    if(i >= num_rows) throw std::out_of_range("[]");
    return *(data[i]);
}

std::ostream& operator<<(std::ostream &out, const Matrix &matrix) {
    for(size_t i=0; i<matrix.num_rows; i++) out<<*(matrix.data[i])<<std::endl;
    return out;
}

Matrix& Matrix::operator*=(const int64_t value) {
    for(size_t i=0; i<num_rows; i++) *(data[i]) *= value;
    return *this;
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    if(num_rows != matrix.num_rows) throw std::invalid_argument("+");
    Matrix matrix_return(num_rows, num_cols, 0);
    for(size_t i=0; i<num_rows; i++) {
        *(matrix_return.data[i]) = *(data[i]) + *(matrix.data[i]);
    }
    return matrix_return;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if(num_rows != matrix.num_rows) return false;
    for(size_t i=0; i<num_rows; i++)
        if(*(data[i]) == *(matrix.data[i])) continue;
        else return false;
    return true;
}

bool Matrix::operator!=(const Matrix &matrix) const {
    return not(*this == matrix);
}

Matrix::~Matrix() {
    for(size_t i=0; i<num_rows; i++)
        delete data[i];
    delete[] data;
}

