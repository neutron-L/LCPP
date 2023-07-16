#ifndef STRVEC_HH
#define STRVEC_HH

#include <iostream>
#include <memory>
#include <string>

using std::string;

class StrVec
{
    friend std::ostream & operator<<(std::ostream &, const StrVec & );
    
public:
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<string>);
    StrVec(StrVec &&) noexcept;

    StrVec & operator=(const StrVec &);
    StrVec & operator=(StrVec &&) noexcept;
    std::string & operator[](std::size_t n) { return elements[n]; }
    const std::string & operator[](std::size_t n) const { return elements[n]; }
    ~StrVec();

    void push_back(const string&);
    void push_back(string&&) ;
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t);
    void resize(size_t);
    string* begin() const { return elements; }
    string* end() const { return first_free; }


private:
    static std::allocator<string> alloc;
    string * elements;
    string * first_free;
    string * cap;

    void chk_n_alloc()
    {
        if (size() == capacity())
        {
            std::cout << "size = " << size() << " call reallocate()\n";
            reallocate();
        }
    }

    std::pair<string *, string *> alloc_n_copy
    (const string* b, const string * e);

    void free();
    void reallocate();
};

#endif