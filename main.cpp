#include <iostream>
#include "framework.h"

using namespace std;
int main(){
    faf::framework f;

    // Create a new market
    faf::market_id mid = f.create_market("EURUSD");

    // Create an alert
    //f.create_alert<faf::alerts::less_than>(mid, faf::alert_manager::)

    // Run the loop
    f.start_thread_analysis();
}
