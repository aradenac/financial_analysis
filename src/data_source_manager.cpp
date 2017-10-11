#include "data_source_manager.h"
using namespace faf;
data_source_manager::data_source_manager()
{
    //ctor
}

shared_ptr<data_source> data_source_manager::get(const string& name){
    for(auto s : m_data_sources) if ( !name.compare(s->m_name) ) return s;
}

void data_source_manager::add(shared_ptr<data_source> s){
    m_data_sources.push_back(s);
}
