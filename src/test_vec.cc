#include <iostream>
#include "strvec.hh"

using namespace std;

int main()
{
    StrVec s1;
    s1.push_back("hello");
    s1.push_back("world");
    s1.push_back("america");
    s1.push_back("america");
    auto s2 = s1;
    cout << s2 << endl;
    s2.push_back("aloha");
    cout << s1 << endl;
    cout << s2 << endl;
    s2.push_back("aloha");
    cout << s2 << endl;

    return 0;
}