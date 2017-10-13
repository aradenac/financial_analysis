#ifndef MARKET_H
#define MARKET_H

#include "market_id.h"
#include <memory>
#include "alert.h"
#include <string>
#include <iostream>
using namespace std;
namespace faf{

class indicator;
class market
{
    public:
        market(const string& name);

        void do_your_job();

        void update();
        void parse();
        void check_alerts();
        void add_indicator(const string&, shared_ptr<indicator>);
        void remove_indicator(const string&);


        market_id m_market_id;
        string m_name;
};
}
#endif // MARKET_H
