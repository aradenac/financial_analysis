#ifndef DATA_SOURCE_H
#define DATA_SOURCE_H

#include <memory>
#include <string>
#include <iostream>


#include "currency.h"
using namespace std;
#include <memory>



namespace faf{

class parser;

class data_source
{
    public:
        virtual void fetch_new_data();

        virtual shared_ptr<currency> parse();


        string m_data;
        string m_name;
        shared_ptr<parser> m_parser;
};

class source_alphavantage : public data_source {
    public:
        source_alphavantage(const string& name){
            m_name = name;
        }

        void fetch_new_data() override{
            cout << "fetching new data" << endl;
        }

        shared_ptr<currency> parse() override{
            cout << "parsing data" << endl;
        }
};
}
#endif // DATA_SOURCE_H
