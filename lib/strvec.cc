#include "strvec.hh"


StrVec::StrVec(const StrVec & s)
{
    auto res = alloc_n_copy(s.begin(), s.end());
    elements = res.first;
    first_free = cap = res.second;
}

StrVec::StrVec(std::initializer_list<string> il)
{
    auto res = alloc_n_copy(il.begin(), il.end());
    elements = res.first;
    first_free = cap = res.second;
}

StrVec::StrVec(StrVec && s) noexcept 
    : elements(s.elements), first_free(s.first_free), cap(s.cap)  
{
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec & StrVec::operator=(const StrVec & s)
{
    auto res = alloc_n_copy(s.begin(), s.end());
    free();
    elements = res.first;
    first_free = cap = res.second;
    return *this;
}

StrVec & StrVec::operator=(StrVec && rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string & s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string && s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

void  StrVec::reserve(size_t size)
{

}

void StrVec::resize(size_t sz)
{
    if (sz <= size())
    {
        auto diff = size() - sz;
        while (diff--)
            alloc.destroy(--first_free);
    }
    else if (sz <= capacity())
    {
        auto diff = sz - size();
        while (diff--)
            alloc.construct(first_free++);
    }
    else
    {
        auto newdata = alloc.allocate(sz);
        auto last = uninitialized_copy(std::make_move_iterator(begin()), 
            std::make_move_iterator(end()), newdata);
        elements = newdata;
        first_free = last;
        auto diff = sz - size();
        while (diff--)
            alloc.construct(first_free++);
        cap = first_free;
    }
}

std::pair<string *, string *> StrVec::alloc_n_copy
    (const string* b, const string * e)
{   
    auto data = alloc.allocate(e - b);
    return { data, uninitialized_copy(b, e, data) };
}


void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{   
    auto size = this->size();
    auto newsize = size ? 2 * size : 1;
    auto newdata = alloc.allocate(newsize);
    auto dest = newdata;
    auto elem = elements;
    while (size--)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newsize;
}

std::ostream & operator<<(std::ostream & os, const StrVec & s)
{
    auto p = s.elements;
    while (p != s.first_free)
        os << *p++ << ' ';
    return os;
}