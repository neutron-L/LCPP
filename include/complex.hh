#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

class complex 
{
    friend std::ostream & operator<<(std::ostream &, const complex & );
    friend std::istream & operator>>(std::istream &, complex & );
    friend complex operator*(double , const complex &);
    friend complex operator~(complex);
public:
    complex(double r = 0, double i = 0)
    : re(r), im(i)
    {}
    complex & operator+=(const complex &);
    complex operator+(const complex &) const;
    complex operator-(const complex &) const;
    complex operator*(const complex &) const;
    complex operator*(double) const;
    double real() const { return re; }
    double imag() const { return im; }
private:
    double re{}, im{};
};

#endif