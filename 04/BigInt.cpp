#include "BigInt.hpp"


BigInt::BigInt(): len(1), data(new char[len+1]) {
    data[0] = '0';
    data[1] = '\0';
}

BigInt::BigInt(const std::string &str) {
    if(str.size() == 0) {
        len = 1;
        data = new char[len+1];
        data[0] = '0';
        data[1] = '\0';
    }
    else {
        bool minus = str[0] == '-';
        bool plus = str[0] == '+';
        size_t j = minus + plus;
        size_t str_size = str.size();
        
        /* Drop meaningless zeros */
        for(; j < str_size - 1 and str[j] == '0'; j++);
        len = str.size() - j + minus;
        data = new char[len+1];
        char t;
        if(minus) data[0] = str[0];
        for(size_t i=minus; i<len; i++) {
            t = str[j + i - minus];
            if(!isdigit(t)) throw std::invalid_argument(std::string(1, t));
            else data[i] = t;
        };
    }
    data[len] = '\0';
}

BigInt::BigInt(int64_t value) {
    BigInt to_copy_from(std::to_string(value));
    data = to_copy_from.data;
    len = to_copy_from.len;
    to_copy_from.data = nullptr;
    to_copy_from.len = 0;
}

BigInt::BigInt(const BigInt &other) {
    len = other.len;
    data = new char[len+1];
    for(size_t i=0; i<len; i++) data[i] = other.data[i];
    data[len] = '\0';
}

BigInt::BigInt(BigInt &&other) {
    data = other.data;
    len = other.len;
    other.data = nullptr;
    other.len = 0;
}

BigInt& BigInt::operator=(const BigInt &other) {
    if(this == &other) return *this;
    len = other.len;
    char * tmp = new char[len+1];
    delete[] data;
    data = tmp;
    tmp = nullptr;
    for(size_t i=0; i<len; i++) data[i] = other.data[i];
    data[len] = '\0';
    return *this;
}

BigInt& BigInt::operator=(BigInt &&other) {
    if(this == &other) {
        return *this;
    }
    delete[] data;
    data = other.data;
    len = other.len;
    other.data = nullptr;
    other.len = 0;
    return *this;
}

BigInt BigInt::operator-() const {
    if(data[0] == '0') return *this;
    bool minus = data[0] == '-';
    char * tmp = new char[len + 1 - 2 * minus + 1];
    if(!minus) tmp[0] = '-';
    for(size_t i = !minus; i<len + 1 - 2 * minus; i++) tmp[i] = data[i - 1 + 2 * minus];
    tmp[len + 1 - 2 * minus] = '\0';
    BigInt val(tmp);
    delete[] tmp;
    return val;
}

bool BigInt::operator>(const BigInt &other) const {
    if(data[0] == '-')
        if(other.data[0] == '-')
            if(len != other.len) return len < other.len;
            else {
                for(size_t i=1; i<len; i++) {
                    if(data[i] < other.data[i]) return true;
                    if(data[i] > other.data[i]) return false;
                }
                return false;
            }
        else return false;  
    else 
        if(other.data[0] != '-')
            if(len != other.len) return len > other.len;
            else {
                for(size_t i=0; i<len; i++) {
                    if(data[i] < other.data[i]) return false;
                    if(data[i] > other.data[i]) return true;
                }
                return false;
            }
        else return true;       
}

bool BigInt::operator==(const BigInt &other) const {
    if(data[0] == '-' and other.data[0] != '-' or data[0] != '-' and other.data[0] == '-') return false;
    if(len != other.len) return false;
    for(size_t i = 1; i<len; i++) {
        if(data[i] != other.data[i]) return false;
    }
    return true;
}

bool BigInt::operator!=(const BigInt &other) const {
    return not(*this == other);
}

bool BigInt::operator<(const BigInt &other) const {
    return not(*this > other) and not(*this == other);
}

bool BigInt::operator>=(const BigInt &other) const {
    return *this > other or *this == other;
}

bool BigInt::operator<=(const BigInt &other) const {
    return *this < other or *this == other;
}

BigInt add(const char * str1, size_t len1, const char * str2, size_t len2) {
    char * tmp = new char[len1 + 2];
    int overflow = 0;
    size_t i = 0;
    for(; i<len2; i++) {
        overflow = (str1[len1 - 1 - i] - '0') + (str2[len2 - 1 - i] - '0') + overflow;
        tmp[len1 - i] = char(overflow % 10 + '0');
        overflow = overflow / 10;
    }
    for(; i<len1; i++) {
        overflow = (str1[len1 - 1 - i] - '0') + overflow;
        tmp[len1 - i] = char(overflow % 10 + '0');
        overflow = overflow / 10;
    }
    tmp[0] = char(overflow + '0');
    tmp[len1 + 1] = '\0';
    BigInt val(tmp);
    delete[] tmp;
    return val;
}

BigInt substract(const char * str1, size_t len1, const char * str2, size_t len2) {
    char * tmp = new char[len1+2];
    bool borrow = false;
    size_t i = 0;
    for(; i<len2; i++) {
        if((str1[len1 - 1 - i] - '0') - borrow < (str2[len2 - 1 - i] - '0')) {
            tmp[len1 - 1 - i] = char(str1[len1 - 1 - i] + 10 - borrow - str2[len2 - 1 - i] + '0');
            borrow = 1;
        }
        else {
            tmp[len1 - 1 - i] = char(str1[len1 - 1 - i] - borrow - str2[len2 - 1 - i] + '0');
            borrow = 0;
        }
    }
    for(; i<len1; i++) {
        if(borrow and str1[len1 - 1 - i] == '0') {
            tmp[len1 - 1 - i] = '9';
            borrow = 1;
        }
        else {
            tmp[len1 - 1 - i] = char(str1[len1 - 1 - i] - borrow);
            borrow = 0;
        }
    }
    tmp[len1+1] = '\0';
    BigInt val(tmp);
    delete[] tmp;
    return val;
}

BigInt BigInt::operator+(const BigInt &other) const {
    if(data[0] == '-')
        if(other.data[0] == '-')
            if(-(*this) >= -other) return -add(data + 1, len - 1, other.data + 1, other.len - 1);
            else return -add(other.data + 1, other.len - 1, data + 1, len - 1);
        else
            if(-(*this) >= other) return -substract(data + 1, len - 1, other.data, other.len);
            else return substract(other.data, other.len, data + 1, len - 1);
    else
        if(other.data[0] == '-')
            if(*this >= -other) return substract(data, len, other.data + 1, other.len - 1);
            else return -substract(other.data + 1, other.len - 1, data, len);
        else
            if(*this >= other) return add(data, len, other.data, other.len);
            else return add(other.data, other.len, data, len);
}

BigInt BigInt::operator-(const BigInt &other) const {
    return *this + (-other);
}

BigInt BigInt::operator*(const BigInt &other) const {
    bool minus1 = data[0] == '-';
    bool minus2 = other.data[0] == '-';
    int overflow = 0;
    size_t baselength = len - minus1 + 1;
    char ** tmp = new char*[other.len - minus2];
    for(size_t i=0; i<other.len - minus2; i++) tmp[i] = new char[baselength + i + 1];
    for(size_t i=0; i<other.len - minus2; i++) {
        for(size_t j = 0; j<i; j++) tmp[i][baselength + i - 1 - j] = '0';
        overflow = 0;
        for(size_t j=0; j<len - minus1; j++) {
            overflow = (data[len - 1 - j] - '0') * (other.data[other.len - 1 - i] - '0') + overflow;
            tmp[i][baselength - 1 - j] = char(overflow % 10 + '0');
            overflow = overflow / 10;
        }
        tmp[i][0] = char(overflow + '0');
        tmp[i][baselength + i] = '\0';
    }
    BigInt mul(0);
    for(size_t i=0; i<other.len - minus2; i++) {
        mul = mul + BigInt(tmp[i]);
        delete[] tmp[i];
    }
    delete[] tmp;
    if(minus1 xor minus2) return -mul;
    else return mul;
}

BigInt::~BigInt() {
    delete[] data;
}

std::ostream& operator<<(std::ostream &out, const BigInt &num) {
    for(size_t i=0; i<num.len; i++) out<<(num.data[i]);
    return out;
}
