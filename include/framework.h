#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
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

        cURLpp::Easy m_curl_handle;
};
}
#endif // FRAMEWORK_H
