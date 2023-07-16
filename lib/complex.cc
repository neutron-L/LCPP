#include "complex.hh"

std::ostream & operator<<(std::ostream & os, const complex & c)
{
    os << "(" << c.re << ", " << c.im << "i)";
    return os;
}   

std::istream & operator>>(std::istream & is, complex & c)
{
    std::cout << "real: ";
    if (std::cin >> c.re)
    {
        std::cout << "imaginary: ";
        std::cin >> c.im;
    }

    return is;
}

complex operator*(double d, const complex & c)
{
    return c * d;
}

complex & complex::operator+=(const complex & c)
{
    re += c.re;
    im += c.im;
    return *this;
}

complex complex::operator+(const complex & c) const
{
    return complex(re + c.re, im + c.im);
}

complex complex::operator-(const complex & c) const
{
    return complex(re - c.re, im - c.im);
}

complex complex::operator*(const complex & c) const
{
    return complex(re * c.re - im * c.im, re * c.im + im * c.re);
}
 
complex complex::operator*(double x) const
{
    return complex(x * this->re, x * this->im);
}

complex operator~(complex c)
{
    c.im = -c.im;
    return c;
}