
#ifndef ADS_NUMBER_H
#define ADS_NUMBER_H

#include <string>
#include <iostream>
#include <vector>

typedef unsigned long long Ull;

class Number
{
public:
    typedef std::string String;
public:
    Number() {}

    /// Constructs a number using the given parameter \a str.
    Number(const String& str);

    /// Constructs a random by given \a length.
    Number(const Ull& len);

    /// Increase  the number by one
    void operator++();

    /// Checks for equality
    bool operator==(const Number& b) const;

    /// Checks if two numbers are not equal
    bool operator!=(const Number& b) const;

    /// Checks if number is 0
    bool isZero() const;

    /// output the number with spaces after each three digits
    void print();

    /// Always returns 0
    static Number zero();

    /// Assigning
    Number& operator=(const Number& b);

    /// returns str representation
    String getNumber() const;

    /// Returns i-th digit from right
    char getDigitR(const Ull& i) const;

    /// Returns i-th digit from left
    char getDigitL(const Ull& i) const;

    /// Returns i-th digit from right
    char operator[](const Ull& i) const;

    /// Returns the number of digits
    Ull size() const;

    /// Returns the sum of two given numbers
    static Number sum(const Number& a, const Number& b);

    /// Sum
    Number operator+(const Number& b);

    /// Returns the value of the smallest number
    static Number minNum(const Number& a, const Number& b);

    /// Returns the value of the greatest number
    static Number maxNum(const Number& a, const Number& b);

private:
    String _strRepresent;

}; // end of Number class

std::ostream& operator<<(std::ostream& s, const Number& num);

#endif //ADS_NUMBER_H