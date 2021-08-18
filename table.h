#ifndef TABLE_H
#define TABLE_H

//#include <controller.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <schalter.h>

class Table {
private:
public:
    Schalter schal;
    //graphics
    int x;
    int y;
    std::string path;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Table()
    {
        //graphic
        path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
        image.loadFromFile(path);
        image.createMaskFromColor(sf::Color(255, 255, 255));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 200, 100, 50));
        //        sprite.setOrigin(40 / 2, 40 / 2);
    };
    ~Table() {};
    //    class Motor ;
    //    class Schalter ;

    void set_position(int x, int y)
    {
        this->x = x;
        this->y = y;
        sprite.setPosition(x, y);
        return;
    }

    void table_move(int s)
    {
        if (s == 1)
            sprite.setTextureRect(sf::IntRect(120, 200, 100, 50));
        else if (s == 2)
            //            sleep(1);
            sprite.setTextureRect(sf::IntRect(240, 200, 100, 50));
        //            sleep(1);
        else if (s == 3)
            sprite.setTextureRect(sf::IntRect(0, 200, 100, 50));
        //            sleep(1);
        schal.schalter_on_off();
        return;
    }

    void set_schalter(Schalter&);
    Schalter get_schalter();

    void move_table();
    void move_forward();
    void move_back();

    void statistic();

    void connect_table(bool);
    void take_signal(bool, bool);

    //    friend Motor;
    //    friend Schalter;
    //    friend Controler;
};

#endif // TABLE_H
