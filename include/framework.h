#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include "market_id.h"
#include "market.h"

using namespace std;

namespace faf {
class framework
{
    public:
        framework();
        ~framework();
        void start_gui();
        void start_thread_analysis();
        market_id create_market(const string& );

        thread m_thread;
        bool m_thread_activated ;
        vector<shared_ptr<market>> m_markets;


};
}
#endif // FRAMEWORK_H
