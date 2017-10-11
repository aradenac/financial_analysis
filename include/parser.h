#ifndef PARSER_H
#define PARSER_H
#include <memory>
#include <string>
namespace faf{
class parser
{
    public:
        parser();

        virtual string parse(const data_source&);

    protected:

    private:

};

class parser_avj : parser {
    public:
        string parse(const data_source& s)override{
            return "source parsed";
        }
}
}
#endif // PARSER_H
