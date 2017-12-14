#include "c_engine_display.h"
#include "../world/world.h"
#include "../world/location.h"

c_engine_display::c_engine_display()
{


}


void c_engine_display::displayWindow(){

    int worldSize_X = 40;
    int worldSize_Y = 20;

    world NewWorld(worldSize_X,worldSize_Y);
    sf::Vector2i v1;
    sf::Vector2f lastposition;


    //int specialcounter=0;




    sf::RenderWindow window(sf::VideoMode(worldSize_X*32, worldSize_Y*32), "Nope, son!");

    sf::RenderWindow menu_window(sf::VideoMode(window.getSize().x, 128)," ",sf::Style::None);

    sf::Text text1;
    sf::Font font;
    if(!font.loadFromFile("resources/Fonts/arial.ttf"));

    text1.setFont(font);
    text1.setString("Start Menu:: start start start start start start start start start start start start start start start start start start \n start start start start start start start start start start start start start start start start start start start start");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

    v1 = (window.getPosition());
    v1.x+=8;
    menu_window.setPosition(v1);

     sf::Texture start_menu_texture;
    if(!start_menu_texture.loadFromFile("sprites/Start.png"))
    {
     //error
    }
    sf::Sprite start_menu_sprite;
    start_menu_sprite.setTexture(start_menu_texture);





    window.setFramerateLimit(30);
    sf::Clock clock;
    sf::Clock fireballtimer;
    sf::Clock shotframes;

    sf::Time shotframetimer = sf::milliseconds(10);
    sf::Time shotduration = sf::milliseconds(400);
    sf::Time t1 = sf::milliseconds(100); //sprite speed

    sf::Texture fire_texture;
    if (!fire_texture.loadFromFile("sprites/FIREBALL.png"))
    {
        //SFML has its own generic image loading error
    }
    sf::Texture city_texture;
    if (!city_texture.loadFromFile("sprites/City.png"))
    {
        //SFML has its own generic image loading error
    }
     sf::Texture mountain_texture;
    if (!mountain_texture.loadFromFile("sprites/Mountains.png"))
    {
        //SFML has its own generic image loading error
    } sf::Texture forest_texture;
    if (!forest_texture.loadFromFile("sprites/Forest.png"))
    {
        //SFML has its own generic image loading error
    }
    sf::Texture grass_texture;
    if (!grass_texture.loadFromFile("sprites/Grass.png"))
    {
        //""
    }
    sf::Texture water_texture;
    if (!water_texture.loadFromFile("sprites/Water.png"))
    {
        //""
    }
    sf::Texture settler_texture;
    if (!settler_texture.loadFromFile("sprites/Grey Cloaked Traveler.png"))
    {
        //""
    }

    sf::Sprite city_sprite;
    city_sprite.setTexture(city_texture);
    sf::Sprite fire_sprite;
    fire_sprite.setTexture(fire_texture);
    sf::Sprite grass_sprite;
    grass_sprite.setTexture(grass_texture);
    sf::Sprite mountain_sprite;
    mountain_sprite.setTexture(mountain_texture);
    sf::Sprite forest_sprite;
    forest_sprite.setTexture(forest_texture);
    sf::Sprite water_sprite;
    water_sprite.setTexture(water_texture);
    sf::Sprite settler_sprite;
    settler_sprite.setTexture(settler_texture);

    settler_sprite.setPosition(0,0);

    while (window.isOpen())
    {
        while (menu_window.isOpen())
        {
            sf::Event menu_window_event;
            while(menu_window.pollEvent(menu_window_event))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                menu_window.close();
            }
            menu_window.clear();
            //menu_window.draw(start_menu_sprite);
            menu_window.draw(text1);
            menu_window.display();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if(clock.getElapsedTime()>t1)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                settler_sprite.move(0,-32);
                clock.restart();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                settler_sprite.move(0,32);
                clock.restart();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                settler_sprite.move(32,0);
                clock.restart();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                settler_sprite.move(-32,0);
                clock.restart();
            }


            if (NewWorld.get_type(NewWorld.getlocid(settler_sprite.getPosition().x, settler_sprite.getPosition().y)) == location::water)
            {
                settler_sprite.setPosition(lastposition);
            }
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::LShift)))
            {
                NewWorld.alter_loc(NewWorld.getlocid(settler_sprite.getPosition().x,settler_sprite.getPosition().y), location::city);
                clock.restart();
            }
            lastposition = settler_sprite.getPosition();

        }

        if(fireballtimer.getElapsedTime()>shotduration)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                fire_sprite.setPosition(lastposition);
                fireballtimer.restart();
            }
        }


        window.clear();
        for(int i = 0; i<=NewWorld.getsize(); i++)
        {
            switch (NewWorld.get_type(i))
            {
                case location::grassland:
                grass_sprite.setPosition(NewWorld.get_x(i)*32, NewWorld.get_y(i)*32);
                window.draw(grass_sprite);
                break;
                case location::forest:
                    forest_sprite.setPosition(NewWorld.get_x(i)*32, NewWorld.get_y(i)*32);
                window.draw(forest_sprite);
                    break;
                case location::mountain:
                    mountain_sprite.setPosition(NewWorld.get_x(i)*32, NewWorld.get_y(i)*32);
                    window.draw(mountain_sprite);
                    break;
                case location::water:
                    water_sprite.setPosition(NewWorld.get_x(i)*32, NewWorld.get_y(i)*32);
                    window.draw(water_sprite);
                    break;
                default:


                //std::cout<<"/n X:"<<NewWorld.get_x(i)<<" Y:"<<NewWorld.get_y(i)<<"\n";
                break;
            }

        }
        for(int i = 0; i<=NewWorld.getsize(); i++)
        {
            switch (NewWorld.get_entity(i))
            {
                case location::nothing:
                    break;
                case location::city:
                //std::cout<<"\n X:"<<NewWorld.get_x(i)<<" Y:"<<NewWorld.get_y(i)<<" "<<i;
                city_sprite.setPosition(NewWorld.get_x(i)*32, NewWorld.get_y(i)*32);

                window.draw(city_sprite);
                break;
                //std::cout<<"/n X:"<<NewWorld.get_x(i)<<" Y:"<<NewWorld.get_y(i)<<"\n";
            }
        }

        if(fireballtimer.getElapsedTime()<shotduration && shotframes.getElapsedTime()>shotframetimer)
        {
            window.draw(fire_sprite);
            fire_sprite.move(32,0);
            NewWorld.alter_loc(NewWorld.getlocid(fire_sprite.getPosition().x, fire_sprite.getPosition().y), location::nothing);
        }

        window.draw(settler_sprite);
        window.display();//}
    }
}
