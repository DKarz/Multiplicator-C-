
#include <algorithm>
#include "number.h"
#include <iostream>
#include <math.h>
#include <random>
#include <ctime>

typedef Number::String String;

void Number::print()
{
    String str = _strRepresent;
    reverse(str.begin(), str.end());
    String pr;
    for (Ull i = 0; i < str.size(); ++i)
    {
        pr += str[i];
        if ((i + 1) % 3 == 0 && (i + 1) != str.size()) pr += " ";
    }
    reverse(pr.begin(), pr.end());
    std::cout << pr << '\n';
}

Number::Number(const String& str) : _strRepresent(str)
{}

bool Number::operator==(const Number& b) const
{
    return (_strRepresent == b._strRepresent);
}

bool Number::operator!=(const Number& b) const
{
    return (_strRepresent != b._strRepresent);
}

bool Number::isZero() const
{
    if (_strRepresent == "0")
        return true;
    return false;
}

Number Number::zero()
{
    String temp = "0";
    Number zero(temp);
    return zero;
}

String Number::getNumber() const
{
    return _strRepresent;
}

Number::Number(const Ull& len)
{
    String str("");
    Ull c = 0;
    srand(time(NULL));
    while (c < len)
    {
        c++;
        str += std::to_string(rand() % 9);
    }
    _strRepresent = str;
}

char Number::getDigitR(const Ull& i) const
{
    return _strRepresent[_strRepresent.size() - i];
}

char Number::getDigitL(const Ull& i) const
{
    return _strRepresent[i - 1];
}

char Number::operator[](const Ull& i) const
{
    return getDigitR(i - 1);
}

Ull Number::size() const
{
    return _strRepresent.size();
}

char notnine(char x)
{
    switch (x)
    {
        case '0':
            return '1';
            break;
        case '1':
            return '2';
            break;
        case '2':
            return '3';
            break;
        case '3':
            return '4';
            break;
        case '4':
            return '5';
            break;
        case '5':
            return '6';
            break;
        case '6':
            return '7';
            break;
        case '7':
            return '8';
            break;
        case '8':
            return '9';
            break;

    }
    return '0';
}

void Number::operator++()
{

    String s = _strRepresent;
    if (s[s.size() - 1] != '9')
    {
        s[s.size() - 1] = notnine(s[s.size() - 1]);
        _strRepresent = s;
        return;
    }

    int j = 0;
    while (s[s.size() - 1 - j] == '9')
        j = j + 1;

    if (s.size() == j)
    {
        s = '1';
        for (int i = 0; i < j; i++)
            s += '0';
    } else if (s.length() != j)
    {
        s[s.size() - 1 - j] = notnine(s[s.size() - 1 - j]);
        for (int i = 0; i < j; i++)
            s[s.size() - j + i] = '0';
    }
    _strRepresent = s;
    return;
}

Number Number::maxNum(const Number& a, const Number& b)
{
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    for (Ull i = 0; i < a.size(); ++i)
    {
        if (a[i] > b[i]) return a;
        if (a[i] < b[i]) return b;
    }
    return a;
}

Number Number::minNum(const Number& a, const Number& b)
{
    if (a.size() < b.size()) return a;
    if (a.size() > b.size()) return b;
    for (Ull i = 0; i < a.size(); ++i)
    {
        if (a[i] < b[i]) return a;
        if (a[i] > b[i]) return b;
    }
    return b;
}

Number& Number::operator=(const Number& b)
{
    (*this)._strRepresent = b._strRepresent;
    return (*this);
}

Number Number::sum(const Number& a, const Number& b)
{

    String x = a._strRepresent;
    String y = b._strRepresent;
    String output;
    Ull l = std::min(x.size(), y.size());
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int p = 0;
    for (Ull i = 0; i < l; i++)
    {
        int dig = ((x[i] - '0') + (y[i] - '0') + p);
        p = dig / 10;
        char digit = std::to_string(dig % 10)[0];
        output += digit;
    }
    String oth, big;
    if (x.size() > y.size()) big = x;
    else big = y;
    oth = big.substr(l, big.size() - 1);

    if (p > 0)
    {
        if (oth.size() == 0)
        {
            oth = "0";
        }
        std::reverse(oth.begin(), oth.end());
        Number temp(oth);
        ++temp;
        oth = temp._strRepresent;
        std::reverse(oth.begin(), oth.end());
    }
    output += oth;
    std::reverse(output.begin(), output.end());
    Number out(output);
    return out;

}

Number Number::operator+(const Number& b)
{
    return sum((*this), b);
}

std::ostream& operator<<(std::ostream& s, const Number& num)
{
    s << num.getNumber();
    return s;
}



///////////////////////////////////////////////////////////////////////////////




