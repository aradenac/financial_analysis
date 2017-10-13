#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include "data_source.h"
#include "parser.h"
#include "market_id.h"
#include "market.h"
#include "data_source_manager.h"

using namespace std;

namespace faf {
class framework
{
    public:
        framework();
        ~framework();
        void start_gui();
        void start_thread_analysis();
        market_id create_market(const string&, const string& );
        shared_ptr<data_source> find_source(const string& );
        /*shared_ptr<parser> find_parser(const string& );*/
    protected:

    private:
        thread m_thread;
        vector<shared_ptr<market>> m_markets;
        data_source_manager m_dsm;

};
}
#endif // FRAMEWORK_H
