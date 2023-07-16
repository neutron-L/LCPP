#include <iostream>
#include "ptr.hh"

using namespace std;


VPtr foo(VPtr * p, VPtr q)
{
    VPtr x(*p), y = q;
    VPtr * heap = new VPtr(y);
    delete heap;
    return y;
}

PPtr bar(PPtr * p, PPtr q)
{
    PPtr x(*p), y = q;
    PPtr * heap = new PPtr(y);
    delete heap;
    return y;
}

int main()
{
    // test VPtr
    VPtr p1("aloha");
    VPtr p2 = p1;
    cout << p1 << endl;
    cout << p2 << endl;

    // test PPtr
    PPtr p3("hello");
    PPtr p4("world");
    cout << p3 << endl;
    cout << p4 << endl;
    p4 = p3;
    cout << p3 << endl;
    cout << p4 << endl;
    // call function
    return 0;
}