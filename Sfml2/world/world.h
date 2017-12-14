#ifndef WORLD_H
#define WORLD_H
#include "location.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


class world
{
public:
    world(int x, int y);
    void peak();
    void build_locations();
    void LocationsToFile();
    void alter_loc(int loc_id, location::loc_entity);
    location::loc_entity get_entity(int i);
    int getsize();
    int get_x(int i);
    int get_y(int i);
    location::loc_type get_type(int i);
    int getlocid(int xcor, int ycor);

protected:

private:
    std::vector<location> loc_container {};

    int MAPSIZE_X;
    int MAPSIZE_Y;
};

#endif // WORLD_H
