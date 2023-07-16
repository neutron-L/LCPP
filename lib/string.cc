#include <iostream>
#include <cstring>
#include "string.hh"

String::String(const char * str)
{
    size_t len = strlen(str);
    auto b = str;
    auto e = str + len;
    auto ret = alloc_n_copy(b, e);
    start = ret.first;
    first_free = cap = ret.second;
}

String::String(const String & str)
{
    std::cout << "call Str copy-constructor\n";
    auto ret = alloc_n_copy(str.begin(), str.end());
    start = ret.first;
    first_free = cap = ret.second;
}


String::String(String && str) noexcept 
    : start(str.start), first_free(str.first_free), cap(str.cap)
{
    std::cout << "call Str move-constructor\n";
    str.start = str.first_free = str.cap = nullptr;
}


String& String::operator=(const String & str)
{
    std::cout << "call Str copy-assign\n";
    free();
    auto ret = alloc_n_copy(str.begin(), str.end());
    start = ret.first;
    first_free = cap = ret.second;

    return *this;
}


String& String::operator=(String && str) noexcept
{
    if (this != &str)
    {
        free();
        start = str.start;
        first_free = str.first_free;
        cap = str.cap;
        str.start = str.first_free = str.cap = nullptr;
    }
    return *this;
}

void String::push_back(const char & c)
{
    
}


void String::push_back(char && c)
{

}

String::~String()
{
    free();
}

std::pair<char *, char *> String::alloc_n_copy(const char * b, const char * e)
{
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };   
}


void String::reallocate()
{
    auto sz = size();
    auto new_size = sz ? 2 * sz : 1;
    auto new_start = alloc.allocate(new_size);
    auto p = start;
    while (p != first_free)
        alloc.
}


void String::free()
{
    for (auto p = first_free; p != start;)
        alloc.destroy(--p);
    alloc.deallocate(start, cap - start);
}

std::ostream & operator<<(std::ostream & os, const String & str)
{
    for (auto p = str.begin(); p != str.end(); ++p)
        os << *p;
    return os;
}

bool String::operator==(const String & rhs)
{
    
}

bool String::operator!=(const String &)
{

}


bool String::operator<(const String &)
{

}