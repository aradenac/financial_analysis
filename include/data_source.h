#ifndef DATA_SOURCE_H
#define DATA_SOURCE_H

#include <memory>
#include <string>
#include <iostream>


#include "currency.h"
using namespace std;

namespace faf{
class data_source
{
    public:
        data_source(const string&);

        virtual void fetch_new_data();

        virtual shared_ptr<currency> parse();


        string m_data;
        string m_name;
};

class source_alphavantage : data_source {
    public:
        void fetch_new_data() override{
            cout << "fetching new data" << endl;
        }

        shared_ptr<currency> parse() override{
            cout << "parsing data" << endl;
        }
};
}
#endif // DATA_SOURCE_H
