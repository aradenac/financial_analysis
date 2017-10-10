#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main (){

	// Create a signal
    vector<double> signal {1,2,3,2,3,1,2,1,3,2,2,1,2,4,7,11,12,13,12,13,14,11,15,11,12,10,11,12,13,10,9,7,5,1,2,3,1};
    vector<pair<int, double>> vec;

    for ( auto it = signal.begin(); it!=signal.end(); it++){
        int x = distance(signal.begin(),it);
        double y = *it;
        vec.emplace_back(x, y);

        //cout << x << ' ' << y << endl;
    }


	// Apply the moving average
	vector<pair<int, double>> sma;
    int sma_vals = 2 ;
	for(auto it = vec.begin()+sma_vals; it != vec.end()  ; it++){
        double sum=0;
        auto it2 = it;
        advance(it2,-sma_vals);
        for(; it2!=it; it2++){
            sum += (*it2).second;
        }
        sma.emplace_back(distance(vec.begin(),it), sum/sma_vals);
	}

	// apply a second moving average
    vector<pair<int, double>> sma2;
    int sma2_vals = 5 ;
	for(auto it = vec.begin()+sma2_vals; it != vec.end()  ; it++){
        double sum=0;
        auto it2 = it;
        advance(it2,-sma2_vals);
        for(; it2!=it; it2++){
            sum += (*it2).second;
        }
        sma2.emplace_back(distance(vec.begin(),it), sum/sma2_vals);
	}

	// save the file

	// create the plot
	// signal to file
    ostringstream signal_ss;
    for ( auto el : vec) signal_ss << el.first << " " << el.second << endl;
    fstream signal_file;
    string signal_file_name("signal.dat");
    signal_file.open(signal_file_name, ios::out);
    signal_file << signal_ss.str() << endl;
    signal_file.close();
    cout << "signal file written successfuly" << endl;

    // sma to file
    ostringstream sma_ss;
    for ( auto el : sma) sma_ss << el.first << " " << el.second << endl;
    fstream sma_file;
    string sma_file_name("sma.dat");
    sma_file.open(sma_file_name, ios::out);
    sma_file << sma_ss.str() << endl;
    sma_file.close();
    cout << "sma file written successfuly" << endl;

    // sma2 to file
    ostringstream sma2_ss;
    for ( auto el : sma2) sma2_ss << el.first << " " << el.second << endl;
    fstream sma2_file;
    string sma2_file_name("sma2.dat");
    sma2_file.open(sma2_file_name, ios::out);
    sma2_file << sma2_ss.str() << endl;
    sma2_file.close();
    cout << "sma2 file written successfuly" << endl;
	return 0;
}
