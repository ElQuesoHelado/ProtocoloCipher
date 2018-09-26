#ifndef MATHFUNC_HPP
#define MATHFUNC_HPP
#include <vector>

namespace fmath {
//Modulo
inline int Modulo(int a, int b)
{
    int r = a - b * (a / b);
    return (r < 0) ? r += b : r;
}

//euclides
inline int mcd(int a, int b)
{
    int r, d, c;
    r = Modulo(a, b);
    d = b;
    while (r > 0) {
        c = d;
        d = r;
        r = Modulo(c, d);
    }
    return d;
}

//euclides extendido HAC // return vector(d,x,y)
inline std::vector<int> euclext(int a, int b)
{
    int q, r,
        x = 1,
        x2 = 1,
        x1 = 0,
        y = 0,
        y2 = 0,
        y1 = 1;
    std::vector<int> result(3);

    if (b == 0) {
        result = { a, x, y };
        return result;
    }

    while (b > 0) {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    result = { a, x2, y2 };
    return result;
}
}

#endif
