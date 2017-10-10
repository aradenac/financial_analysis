#include "framework.h"

#include <iostream>
using namespace faf;
using namespace std;

static void thread_worker(framework* f){
    // for each market suscribed
    // update the currency
    // compute the indicators
    // check alerts

}

framework::framework()
{
    //ctor
}
framework::~framework(){
    m_thread.join();
}

void framework::start_gui(){
    cout << "Starting gui" << endl;
}

void framework::start_thread_analysis(){
    cout << "Starting thread analysis" << endl;


    m_thread = thread(thread_worker, this);

}
