#ifndef PARSER_H
#define PARSER_H
#include <memory>
#include <string>

using namespace std;


namespace faf{

class data_source;

class parser
{
    public:
        parser();

        virtual string parse(const data_source&);

    protected:

    private:

};

class parser_avj : public parser {
    public:
        string parse(const data_source& s)override{
            return "source parsed";
        }
};
}
#endif // PARSER_H
