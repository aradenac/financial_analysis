#include "market.h"
using namespace faf;
market::market(const string& name)
{
    m_name = name;
}

void market::do_your_job(){
    update();
    parse();
    check_alerts();
}
void market::update(){
    cout << "updating" << endl;
}
void market::parse(){
}
void market::check_alerts(){}
void market::add_indicator(const string& name, shared_ptr<indicator> indicator){}
void market::remove_indicator(const string& name){}
