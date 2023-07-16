#include <iostream>
#include <memory>
#include <vector>
#include "quote.hh"

using namespace std;

double print_total(ostream & os, 
            const Quote & item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>(Quote("110", 50)));
    basket.push_back(make_shared<Quote>(Bulk_Quote("110", 50, 10, 0.25)));
    Quote * p = new Bulk_Quote("110", 50, 10, 0.75);
    auto bulk = Bulk_Quote("110", 50, 10, 0.75);
    cout << bulk.net_price(15) << endl;
    cout << basket.back()->net_price(15) << endl;
    cout << p->net_price(15) << endl;
    
    return 0;
}