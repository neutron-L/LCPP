#ifndef QUOTE_HH
#define QUOTE_HH

#include <iostream>
#include <string>

class Quote 
{
public:
    Quote() = default;
    Quote(const Quote &)
    {
        std::cout << "call Quote copy-constructor\n";
    }
    Quote(Quote &&)
    {
        std::cout << "call Quote move-constructor\n";
    }
    Quote(const std::string & book, double sales_price) :
       bookNo(book), price(sales_price)  {}
    Quote& operator=(const Quote &)=default;
    Quote& operator=(Quote &&)=default;
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
    { return n * price; }
    virtual void debug() const;
    virtual Quote * clone() const & { return new Quote(*this); }
    virtual Quote * clone() && { return new Quote(std::move(*this)); }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price{};
};

class Disc_Quote : public Quote
{
public:
    Disc_Quote() = delete;
    Disc_Quote(const std::string & book, double price, 
        std::size_t qty, double disc) : 
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
    void debug() const = 0;
protected:
    std::size_t quantity{};
    double discount{};
};

class Bulk_Quote : public Disc_Quote
{
public:
    using Disc_Quote::Disc_Quote;
    // Bulk_Quote() = default;
    // Bulk_Quote(const std::string & book, double price, 
    //     std::size_t qty, double disc) : 
    //     Disc_Quote(book, price, qty, disc) {}
    double net_price(std::size_t) const override;
    void debug() const override;
    Bulk_Quote * clone() const & { return new Bulk_Quote(*this); }
    Bulk_Quote * clone() && { return new Bulk_Quote(std::move(*this)); }
};

#endif