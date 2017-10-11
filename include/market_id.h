#ifndef MARKET_ID_H
#define MARKET_ID_H

#include <ctime>
namespace faf {
class market_id
{
    public:
        market_id();

    protected:

    private:
        std::clock_t m_id;

};
}
#endif // MARKET_ID_H
