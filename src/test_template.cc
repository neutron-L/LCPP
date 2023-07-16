#include <iostream>
#include <vector>
#include <list>

#include "template.hh"

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

template <typename T>
T foo(T *p)
{
    T tmp = *p;
    return tmp;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template <typename Iter, typename T>
Iter find(Iter begin, Iter end, const T &val)
{
    while (begin != end && *begin != val)
        ++begin;
    return begin;
}

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for (auto &elem : arr)
        cout << elem << endl;
}

template <typename T, unsigned N>
T *begin(const T (&arr)[N])
{
    return &arr[0];
}

template <typename T, unsigned N>
T *end(const T (&arr)[N])
{
    return &arr[N - 1];
}



int main()
{
    double *p = new double;
    DebugDelete d;
    d(p);
    int * ip = new int;
    d(ip);
    
    return 0;
};