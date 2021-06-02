#include <iostream>
#include <vector>

#ifndef bigint_hpp
#define bigint_hpp

class BigInt {
    /* Number of digitals */
    size_t len;
    /* Value of the number is stored as a string
       If the number is negative, data[0] == '-' */
    char * data;
    
public:
    BigInt();
    BigInt(const std::string &str);
    BigInt(int64_t value);
    BigInt(const BigInt &other);
    BigInt(BigInt &&other);
    BigInt& operator=(const BigInt &other);
    BigInt& operator=(BigInt &&other);
    BigInt operator-() const;
    bool operator>(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator==(const BigInt &other) const;
    bool operator!=(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;
    
    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt operator*(const BigInt &other) const;

    ~BigInt();
    
    friend std::ostream& operator<<(std::ostream &out, const BigInt &num);
};

#endif
