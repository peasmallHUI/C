//stock.h  -- Stock class declaration with constructors, destrutor 
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
    private:
        std::string company;
        long shares;
        double shares_v;
        double total_v;
        void set_tot() {total_v = shares * shares_v;}
    public:
        Stock();
        Stock(const std::string & co, long n = 0, double pr = 0.0);
        ~Stock();
        void buy(long );
};
#endif