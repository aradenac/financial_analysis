#include "market.h"
#include "framework.h"
#include <curlpp/cURLpp.hpp>

using namespace faf;
market::market(framework* f, const string& name)
{
    m_name = name;
    m_framework =f;
}

void market::do_your_job(){
    cout << "doing job for market " <<m_name<<endl;
    update();
    parse();
    check_alerts();
}
void market::update(){
    m_framework->m_curl_handle.perform();
}
void market::parse(){
}
void market::check_alerts(){}
void market::add_indicator(const string& name, shared_ptr<indicator> indicator){}
void market::remove_indicator(const string& name){}
