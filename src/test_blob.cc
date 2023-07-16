#include <iostream>

#include "blob.hh"

using namespace std;

int main()
{
    StrBlob b = {"a", "an", "the"};
    while (b.size())
    {
        cout << b.back() << ' ';
        b.pop_back();
    }
    cout << endl;
    b.push_back("this");
    cout << b.size() << endl;
    cout << b.back() << ' ' << b.front() << endl;
    b.push_back("where");
    cout << b.back() << ' ' << b.front() << endl;
    StrBlob b2 = b;
    b2.push_back("that");
    cout << b.back() << ' ' << b.front() << endl;
    cout << b.size();

    StrBlobPtr p(b);
    cout << *p << endl;
    cout << p->size() << endl;
    *p = "okay";
    cout << *p << endl;
    cout << b.front() << endl;
    cout << p->size() << endl;

    return 0;
}