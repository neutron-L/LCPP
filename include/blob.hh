#ifndef BLOB_HH
#define BLOB_HH

#include <vector>
#include <memory>

using std::shared_ptr;
using std::weak_ptr;
using std::vector;


class StrBlobPtr;
class StrBlob
{
    friend StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string & t) { data->push_back(t); }
    void pop_back();

    std::string & front();
    std::string & back();

    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() 
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string & msg) const;
};


class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob & a, size_t sz = 0) 
    : wptr(a.data), curr(sz) {}
    std::string & deref() const;
    StrBlobPtr & incr();

    StrBlobPtr & operator++();
    StrBlobPtr & operator--();

    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

    std::string & operator*() const;
    std::string * operator->() const;
private:
    shared_ptr<vector<std::string>> check(std::size_t, const std::string &) const;
    weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif