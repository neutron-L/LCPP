#include <iostream>
#include "quote.hh"

void Quote::debug() const
{
    std::cout << " isbn: " << bookNo << std::endl;
    std::cout << "price: " << price << std::endl;
}


double Bulk_Quote::net_price(std::size_t cnt) const 
{
    if (cnt >= quantity)
        return cnt * discount * price;
    else
        return cnt * price;
}

void Bulk_Quote::debug() const
{
    Quote::debug();
    std::cout << "quantity: " << quantity << std::endl;
    std::cout << "discount: " << price << std::endl;
}