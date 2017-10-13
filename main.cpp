#include <iostream>
#include "framework.h"

using namespace std;
int main(){
    faf::framework f;

    // Create a new market
    faf::market_id mid = f.create_market("EURUSD");

    // Run the loop
    f.start_thread_analysis();
}
