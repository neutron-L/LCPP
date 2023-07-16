#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include "string.hh"
using namespace std;

class Cd
{
private:
    char * performers{};
    char * label{};
    int selections{};
    double playtime{};
public:
    Cd(char * s1, char * s2, int n, double x) : 
        performers(strdup(s1)), label(strdup(s2)), selections(n), playtime(x)
    {  }
    Cd(const Cd & d) :
        performers(strdup(d.performers)), label(strdup(d.label)), selections(d.selections), playtime(d.playtime)
    {  }
    Cd()=default;
    virtual ~Cd()
    {
        free(performers);
        free(label);
    }
    virtual void report() const;
    Cd & operator=(const Cd & d);
};

void Cd::report() const
{
    if (performers)
        cout << "performers: " << performers << endl;
    if (label)
        cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    free(performers);
    free(label);
    performers = strdup(d.performers);
    label = strdup(d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}

class Classic : public Cd
{
public:
    Classic() : Cd() {}
    Classic(char * s1, char * s2, char * s3, int n, double x) 
    : Cd(s1, s2, n, x), mainworks(strdup(s3))
    {    }
    Classic(const Classic & c) 
    : Cd(c), mainworks(strdup(c.mainworks))
    {    }
    void report() const override;
    Classic & operator=(const Classic & d);
    ~Classic()
    {
        free(mainworks);
    }
private:
    char * mainworks{};
};


void Classic::report() const
{
    Cd::report();
    if (mainworks)
        cout << "main works: " << mainworks << endl;
}

Classic & Classic::operator=(const Classic & d)
{
    free(mainworks);
    mainworks = strdup((static_cast<const Classic&>(d)).mainworks);
    Cd::operator=(d);

    return *this;
}

void Bravo(const Cd & disk)
{
    disk.report();
}

class Base
{
public:
    virtual int fcn()
    {
        cout << "call Base fcn(int)\n";
        return 0;
    }
};


class Derived : public Base
{
public:
    int fcn(int)
    {
        cout << "call Derived fcn(int)\n";
        return 0;
    }
    virtual void f2() {
        cout << "call Derived f2()\n";
    }
};

class D2 : public Derived
{
public:
    int fcn(int)
    {
        cout << "call D2 fcn(int)\n";
        return 0;
    }
    int fcn()
    {
        cout << "call D2 fcn()\n";
        return 0;
    }
    void f2()
    {
        cout << "call D2 f2()\n";
    }
};

int main()
{
    Base b1;
    Derived b2;
    D2 b3;

    Base * p1 = &b3;
    Derived * p2 = &b3;
    D2 * p3 = &b3;
    // p1->fcn(12);
    p2->fcn(12);
    p3->fcn(12);

    return 0;
}