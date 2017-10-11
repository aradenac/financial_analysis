#ifndef DATA_SOURCE_MANAGER_H
#define DATA_SOURCE_MANAGER_H

#include "data_source.h"
#include <vector>
#include <memory>
#include <string>
namespace faf{
class data_source_manager
{
    public:
        data_source_manager();
        shared_ptr<data_source> get(const string&);
        void add ( shared_ptr<data_source> );

    protected:

    private:
        vector<shared_ptr<data_source>> m_data_sources;
};
}
#endif // DATA_SOURCE_MANAGER_H
