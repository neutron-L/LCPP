#include "ptr.hh"

VPtr & VPtr::operator=(const VPtr & p)
{
    auto newp = new std::string(*p.ps);
    delete ps;
    ps = newp;
    i = p.i;

    return *this;
}

PPtr & PPtr::operator=(const PPtr & p)
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ++*p.use;
    ps = p.ps;
    use = p.use;
    return *this;
}


PPtr::~PPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}