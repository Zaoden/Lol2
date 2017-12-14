#include "location.h"

location::location(int id, int x, int y, int randomloc)
{
    LOC_ID = id;
    location::assign_x(x);
    location::assign_y(y);
    switch (randomloc)
    {
    case 0:
        location_type = grassland;
        break;
    case 1:
        location_type = forest;
        break;
    case 2:
        location_type = mountain;
        break;
    case 3:
        location_type = water;
        break;
    default:
        location_type = grassland;
    }
}

void location::assign_x(unsigned int x)
{

    x_location = x;
}
void location::assign_y(unsigned int y)
{

    y_location = y;
}
int location::getX()
{
    return x_location;
}
int location::getY()
{
    return y_location;

}

location::loc_type location::getloc_type()
{
    return location_type;
}

void location::alter_entity(loc_entity changeto)
{
    displayed_entity = changeto;
    //std::cout<<"\n X:"<<x_location<<" Y:"<<y_location<<" "<<LOC_ID;

}

location::loc_entity location::get_displayed_entity()
{
    return location::displayed_entity;
}


void location::test()
{
    std::cout << "location id: " << LOC_ID << "\n" << x_location << "," << y_location << "\n";

}
