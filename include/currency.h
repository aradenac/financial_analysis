#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
namespace faf{
struct exchange_rate{
    tm date;
    double opening;
    double closing;
    double high;
    double low;
};

typedef vector<exchange_rate> currency;

}
#endif // CURRENCY_H
