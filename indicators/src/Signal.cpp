#include "signal.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
Signal::Signal()
{

}

Signal::Signal(vector<pair<int, double> > &input){
    m_vector = input;
}

void Signal::name(const string& name){
    m_name = name;
}
void Signal::generate_sma(const int& sma_vals, Signal& smasig){
    vector<pair<int, double>> sma;

	for(auto it = m_vector.begin()+sma_vals; it != m_vector.end()  ; it++){
        double sum=0;
        auto it2 = it;
        advance(it2,-sma_vals);
        for(; it2!=it; it2++){
            sum += (*it2).second;
        }
        sma.emplace_back(distance(m_vector.begin(),it), sum/sma_vals);
    }

    smasig.m_vector = sma;
}
void Signal::generate_gnuplot(){
    ostringstream signal_ss;
    for ( auto el : m_vector) signal_ss << el.first << " " << el.second << endl;
    fstream signal_file;
    string signal_file_name(m_name+".dat");
    signal_file.open(signal_file_name, ios::out);
    signal_file << signal_ss.str() << endl;
    signal_file.close();
}
