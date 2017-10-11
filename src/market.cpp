#include "market.h"
using namespace faf;
market::market(const string& name, shared_ptr<data_source> source)
{
    m_name = name;
    m_source = source;
}
