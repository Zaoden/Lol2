#ifndef NATION_H
#define NATION_H
#include <string>
#include <vector>
#include "pop.h"

class nation
{
public:
    nation();
    virtual ~nation();


    std::string getName() {return name;}




private:
    unsigned int gold;
    std::string name;
    std::vector<pop> pop_list {};
};

#endif // NATION_H
