#include "framework.h"
#include <iostream>
using namespace faf;
using namespace std;

static void thread_worker(framework* f){
    // for each market suscribed
    // update the currency
    // compute the indicators
    // check alerts

    cout << f->m_thread_activated << endl;
    while(f->m_thread_activated){
        for(auto market:f->m_markets){
            this_thread::sleep_for(1us);
            market->do_your_job();
        }
    }

    cout << "worker thread done !" << endl;

}

framework::framework()
{
    // Create data souce manager and add it some sources
    // note that in the futures sources could be fetched from files, ....

    m_thread_activated = true;
    // create eurusd source
    /*shared_ptr<parser_avj> parser_avj;
    shared_ptr<data_source> s (new data_source("EURUSD", static_pointer_cast<faf::parser>(parser_avj)) );*/

}
framework::~framework(){
    this_thread::sleep_for(1us);// letting time for the thread to start before stting false
    m_thread_activated = false;
    if(m_thread.joinable()) m_thread.join();
}
/*
shared_ptr<data_source> framework::find_source(const string& name){
    for ( auto s : m_dsm.get_source_list() ) if ( !name.compare(s.m_name) ) return s;
}*/
/*
shared_ptr<parser> framework::find_parser(const string& name){
    for ( s : m_data_parsers ) if ( !name.compare(s.m_name) ) return s;
}*/

market_id framework::create_market(const string& name){

    //shared_ptr<data_source> find_source(source_name);
    shared_ptr<market> m ( new market(name) );

    m_markets.push_back(m);

    cout << "New market created with id "<<m->m_market_id<<endl;

    return m->m_market_id;
}

void framework::start_gui(){
    cout << "Starting gui" << endl;
}

void framework::start_thread_analysis(){
    cout << "Starting thread analysis" << endl;

    m_thread = thread(thread_worker, this);

}
