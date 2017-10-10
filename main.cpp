#include <iostream>
#include <thread>
using namespace std;

void mythreadfunc(){
    cout << "bonjour" << endl;
}

int main(){
    thread my_thread(mythreadfunc);
    my_thread.join();
    return 0;
}
