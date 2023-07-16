#ifndef PTR_HH
#define PTR_HH

#include <iostream>
#include <string>

//act as a value
class VPtr
{
    // friend std::ostream & operator<<(std::ostream & os, const VPtr & p);
public:
    VPtr(const std::string & s = std::string()) :
        ps(new std::string(s)), i(0) {}
    VPtr(const VPtr & vptr) : ps(new std::string(*vptr.ps)), i(vptr.i)
    {    }
    VPtr & operator=(const VPtr & );
    ~VPtr() { delete ps; }
    friend std::ostream & operator<<(std::ostream & os, const VPtr & p)
    {
        os << *p.ps << " " << p.i;
        return os;
    }
private:
    std::string *ps;
    int          i;
};

//act as a pointer
class PPtr
{
    friend std::ostream & operator<<(std::ostream & os, const PPtr & p);
public: 
    PPtr(const std::string & s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1))
    {}
    PPtr(const PPtr & p) :
        ps(p.ps), i(p.i), use(p.use)
    { ++*use; }
    PPtr & operator=(const PPtr & );
    ~PPtr();
    friend std::ostream & operator<<(std::ostream & os, const PPtr & p)
    {
        os << *p.ps << " " << p.i << ' ' << *p.use;
        return os;
    }
private:
    std::string * ps;
    int i;
    std::size_t *use;
};





#endif