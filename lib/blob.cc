#include <stdexcept>  

#include "blob.hh"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : 
    data(std::make_shared<std::vector<std::string>>(il))
    {}

void StrBlob::check(size_type i, const std::string & msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string & StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}


std::string & StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string & StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}


StrBlobPtr & StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string & msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    else if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

StrBlobPtr & StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr & StrBlobPtr::operator--()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

std::string & StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string * StrBlobPtr::operator->() const
{
    return & this->operator*();
}

