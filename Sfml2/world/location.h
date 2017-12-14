#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>





class location
{
public:
    enum loc_entity
    {
        nothing,
        city

    };
    enum loc_type
    {

        grassland,
        forest,
        mountain,
        water

    };

    location(int id, int x, int y, int randomloc);
    void assign_x(unsigned int x);
    void assign_y(unsigned int y);
    int getX();
    int getY();
    loc_type getloc_type();
    void test();
    void alter_entity(loc_entity);
    loc_entity get_displayed_entity();



protected:

private:
    unsigned   int x_location = 0;
    unsigned   int y_location = 0;
    unsigned   int LOC_ID = 100;
    loc_type location_type;
    loc_entity displayed_entity;
};

#endif // LOCATION_H
