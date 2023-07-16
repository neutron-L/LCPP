#include <iostream>
#include "mail.hh"
using namespace std;


int main()
{
    Message m1, m2;
    Folder f1, f2;

    m1.save(f1);
    m2.save(f2);

    swap(m1, m2);    

    return 0;
}