#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    using ArrayDb = std::valarray<double>;

    std::string name;
    ArrayDb scores;

    std::ostream & arr_out(std::ostream& os) const;

public:
    Student() : name("Null Student"), scores()
    {}
    explicit Student(const std::string & s)
    : name(s), scores()
    {}
    explicit Student(int n) : name("Null Student"), scores(n)
    {}
    Student(const std::string & s, const ArrayDb & a)
    : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)
    : name(str), scores(pd, n)
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