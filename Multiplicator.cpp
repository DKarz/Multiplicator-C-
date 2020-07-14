#include "Multiplicator.h"
#include <string>
#include <algorithm>

typedef std::string String;

void addZero(String& str, const Ull& n)
{
    String zeroes("");
    for (Ull i = 0; i < n; i++)
    {
        zeroes += "0";
    }
    str += zeroes;
}

Number Multiplicator::product1(const Number& a, const Number& b)
{
    Number zero("0");
    if (a.isZero() || b.isZero())
        return Number::zero();
    String x = a.getNumber();
    String y = b.getNumber();
    Number output("0");
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    std::vector<Number> toSum;
    for (Ull i = 0; i < a.size(); i++)
    {
        std::string temp;
        int add = 0;
        for (Ull j = 0; j < b.size(); j++)
        {
            int digit = (x[i] - '0') * (y[j] - '0') + add;
            add = digit / 10;
            digit = digit % 10;
            temp += std::to_string(digit);
            if (j == b.size() - 1) temp += std::to_string(add);
        }
        reverse(temp.begin(), temp.end());
        addZero(temp, i);
        Number t(temp);
        toSum.push_back(t);
    }
    for (Ull i = 0; i < toSum.size(); ++i)
    {
        output = Number::sum(output, toSum[i]);
    }
    Ull ttt = 0;
    for (Ull i = 0; i < output.size(); i++)
    {
        if (output.getNumber()[i] != '0')
        {
            ttt = i;
            break;
        }
    }
    String ans = output.getNumber().substr(ttt, output.getNumber().size());
    Number answer(ans);
    return answer;
}


Number addZ(Number& y, Ull& n)
{
    String zeroes("");
    String t = y.getNumber();
    for (Ull i = 0; i < n; i++)
        zeroes += "0";
    t += zeroes;
    Number s(t);
    return s;
}

Number Multiplicator::product2(const Number& xx, const Number& yy)
{
    if (xx.isZero() || yy.isZero())
        return Number::zero();
    if (xx.size() <= 1 || xx.size() <= 1)
        return Multiplicator::product3(xx, yy);
    Ull n = xx.size();
    Ull x = n - n / 2;
    Ull m = yy.size();
    Ull y = m - m / 2;
    Ull ex = n / 2, ey = m / 2;
    Ull XY = n + m - (x + y);
    Number a(xx.getNumber().substr(0, x));
    Number b(xx.getNumber().substr(x, n / 2));
    Number c(yy.getNumber().substr(0, y));
    Number d(yy.getNumber().substr(y, m / 2));
    Number t1 = product2(a, c);
    Number t2 = product2(b, c);
    Number t3 = product2(a, d);
    Number t4 = product2(b, d);
    Number tt1 = addZ(t1, XY);
    Number tt2 = addZ(t2, ey);
    Number tt3 = addZ(t3, ex);
    Number tt4 = t4;
    Number res = Number::sum(Number::sum(Number::sum(tt1, tt2), tt3), tt4);
    return res;
}

Number Multiplicator::product3(const Number& a, const Number& b)
{
    if (a.isZero() || b.isZero())
        return Number::zero();
    Number out("0");
    Number t("0");
    while (t != a)
    {
        ++t;
        out = Number::sum(out, b);
    }

    return out;
}


