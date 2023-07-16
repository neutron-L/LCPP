#ifndef STRING_HH
#define STRING_HH

#include <iostream>
#include <memory>
using std::allocator;

class String
{
    friend std::ostream & operator<<(std::ostream &, const String &);
public:
    String() : start(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char * str);
    String(const String & str);
    String(String && str) noexcept;
    String& operator=(const String & str);
    String& operator=(String && str) noexcept;

    bool operator==(const String &);
    bool operator!=(const String &);
    bool operator<(const String &);
    char & operator[](std::size_t idx) { return start[idx]; }
    const char & operator[](std::size_t idx) const { return start[idx]; }

    size_t size() const { return first_free - start; }
    size_t capacity() const { return cap - start; }
    char * begin() const { return start; }
    char * end() const { return first_free; }

    void push_back(const char &);
    void push_back(char &&);

    ~String();
private:
    static allocator<char> alloc;
    char * start;
    char * first_free;
    char * cap;

    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void chk_n_alloc()
    {
        if (size() == capacity())
        {
            std::cout << "size = " << size() << " call reallocate()\n";
            reallocate();
        }
    }
    void reallocate();
    void free();
};

#endif