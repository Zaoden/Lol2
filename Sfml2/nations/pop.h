#ifndef POP_H
#define POP_H
#include <string>


class pop
{
public:
    pop();
    virtual ~pop();




    unsigned int GetSIZE()              {return SIZE;}

    void SetSIZE(unsigned int val)      {SIZE = val;}

    std::string getNAME()               {return name;}

    void SetCOORDINATES(int val)        {coordinates = val;}
    int GetCOORDINATES()                {return coordinates;}




private:
    std::string name;
    unsigned int SIZE;
    unsigned int LOYALTY;
    int coordinates;
};

#endif // POP_H
