#ifndef MARKET_H
#define MARKET_H

#include "data_source.h"
#include "market_id.h"
#include <memory>
#include <string>
namespace faf{
class market
{
    public:
        market(const string& name, shared_ptr<data_source> source);

        market_id m_market_id;
        string m_name;
        shared_ptr<data_source> m_source;
};
}
#endif // MARKET_H
