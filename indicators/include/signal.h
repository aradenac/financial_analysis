#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
#include <vector>

using namespace std;

class Signal
{
    public:
        Signal();
        Signal(vector<pair<int,double> > &);

        void name(const string& );
        void generate_sma(const int&, Signal&);
        void generate_gnuplot();

    protected:

    private:
        string m_name;
        vector<pair<int,double>> m_vector;
};

#endif // SIGNAL_H
