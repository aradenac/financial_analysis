#ifndef MARKET_ID_H
#define MARKET_ID_H

#include <ctime>
#include <ostream>
using namespace std;
namespace faf {
class market_id
{
    public:
        market_id();

        std::clock_t m_id;

        friend ostream& operator<<(ostream&os, market_id& m){
            os << m.m_id;
            return os;
        }
};

}
#endif // MARKET_ID_H
