#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double> 
{
private:
    using ArrayDb = std::valarray<double>;
    std::ostream & arr_out(std::ostream& os) const;

public:
    Student() : std::string("Null Student"), ArrayDb()
    {}
    explicit Student(const std::string & s)
    : std::string(s), ArrayDb()
    {}
    explicit Student(int n) : std::string("Null Student"), ArrayDb(n)
    {}
    Student(const std::string & s, const ArrayDb & a)
    : std::string(s), ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)
    : std::string(str), ArrayDb(pd, n)
    {}
    ~Student() {}
    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    // friend 
    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
};

#endif