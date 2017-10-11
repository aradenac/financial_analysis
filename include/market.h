#ifndef MARKET_H
#define MARKET_H

#include "data_source.h"
#include <memory>
#include <string>
namespace faf{
class market
{
    public:
        market(const string& name, shared_ptr<data_source> source);

    protected:

    private:

};
}
#endif // MARKET_H
