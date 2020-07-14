#ifndef ADS_MULTIPLICATOR_H
#define ADS_MULTIPLICATOR_H

#include "number.h"


class Multiplicator
{
public:
    /// School method
    static Number product1(const Number& a, const Number& b);

    /// Karatsuba algorithm
    static Number product2(const Number& a, const Number& b);

    /// sum of a, b times
    static Number product3(const Number& a, const Number& b);
};


#endif //ADS_MULTIPLICATOR_H
