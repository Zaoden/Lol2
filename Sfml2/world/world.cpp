#include "world.h"

world::world(int x, int y)
{

    MAPSIZE_X = x;
    MAPSIZE_Y = y;
    build_locations();
    LocationsToFile();


}
void world::build_locations()
{
    int randomseed;
    srand(time(NULL));


    int current_id = 0;
    for(int y=0; y<=MAPSIZE_Y; y++)
    {
        for (int x=0; x<=MAPSIZE_X; x++)
        {
            randomseed = rand() % 10;
            loc_container.push_back(location(current_id, x, y, randomseed));
            current_id++;

            std::cout<<"\n X:"<<x<<" Y:"<<y<<" "<<randomseed<<" "<<current_id;
        }
    }
    /*
    for (int i=0; i < x*y; i++){
        loc_container.push_back(location(i)); //add x y coordinates to each location via loops
    }

    int b = 0;
    for (int i=0; i < x*y; i++){
        if (b==x)
            b=0;
        loc_container[i].assign_x(b);
        b++;
        }

    int c = 0;
    int temp = 0;

    for (int i=0; i < x*y; i++){
        if (c==x){
            c=0;
            temp++;
        }
        loc_container[i].assign_y(temp);
        c++;
          }
          */
}


void world::peak()
{

    std::cout << loc_container.size() << std::endl;

    for ( int x =0; ((unsigned)x)<loc_container.size(); x++)



        loc_container[x].test();


}


void world::LocationsToFile()
{


    std::ofstream myfile;
    myfile.open("example.txt"); //adds more to file, change
    for (int i = 0; ((unsigned)i)<loc_container.size(); i++)
    {
        myfile << "(" << loc_container[i].getX() << "," << loc_container[i].getY() << ") ";
        if (loc_container[i].getX() == MAPSIZE_X - 1 )
        {
            myfile << "\n";
        }

    }
    myfile.close();

}

int world::getsize()
{
    return loc_container.size();
}

int world::get_x(int i)
{

    return loc_container[i].getX();
}

int world::get_y(int i)
{
    //std::cout<<loc_container[i].getY();
    return loc_container[i].getY();
}

location::loc_type world::get_type(int i)
{
    return loc_container[i].getloc_type();
}

void world::alter_loc(int loc_id, location::loc_entity new_displayed_entity)
{

    loc_container[loc_id].alter_entity(new_displayed_entity);

}

int world::getlocid(int xcor, int ycor)
{
    xcor/=32; ycor/=32;
    int current_id= 0;
    int loc_id = 0;
    for(int y=0; y<=MAPSIZE_Y; y++)
    {
        for(int x=0; x<=MAPSIZE_X; x++)
        {
            //std::cout<<"\n "<<current_id<<" X:"<<x<<" Y:"<<y;
            if ((y==ycor)&&(x==xcor))
            {
                loc_id=current_id;
            }
            current_id++;

        }
    }

    return loc_id;
}
location::loc_entity world::get_entity(int i)
{
    return loc_container[i].get_displayed_entity();
}


