#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <iostream>

#include <thread>

using namespace std;

namespace faf {
class framework
{
    public:
        framework();
        ~framework();
        void start_gui();
        void start_thread_analysis();

    protected:

    private:
        thread m_thread;

};
}
#endif // FRAMEWORK_H
