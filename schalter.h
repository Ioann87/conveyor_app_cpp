#ifndef SCHALTER_H
#define SCHALTER_H

//#include <controller.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <motor.h>

class Schalter {

private:
    bool on;
    bool off;
    int U_in;
    int f_in;

    int U_out;
    int f_out;

    bool signal;

    bool direction;

public:
    Motor motor;
    //graphics
    int x;
    int y;
    std::string path;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    //    sf::Font font;
    //    sf::Text text;

    Schalter();
    ~Schalter() {};

    void set_position(int x, int y)
    {
        this->x = x;
        this->y = y;
        sprite.setPosition(x, y);

        return;
    }

    void schalter_on_off()
    {
        /*if (s == 44) {
            sprite.setTextureRect(sf::IntRect(200, 100, 40, 40));
            sprite.setPosition(x, y);
        }*/
        /*else*/
        if (direction) {
            //            sleep(1);
            sprite.setTextureRect(sf::IntRect(280, 100, 20, 40));
            sprite.setPosition(x + 20, y - 40);
            //            text.setString("ABC");
        }
        //            sleep(1);
        else {
            sprite.setTextureRect(sf::IntRect(280, 100, 20, 40));
            sprite.setPosition(x, y - 40);
            //            text.setString("ACB");
            //            sleep(1);
        }
        motor.motor_move();
        return;
    }

    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();

    void set_U(int);
    int get_U();
    void set_f(int);
    int get_f();

    void set_U_out(int);
    int get_U_out();
    void set_f_out(int);
    int get_f_out();

    void set_signal(bool);
    bool get_signal();
    void set_direction(bool);
    bool get_direction();

    void set_motor(Motor&);
    Motor get_motor();

    //methods for schalter
    void statistic();
    void schalter_on();
    void schalter_off();
    void start_motor(bool);
    void stop_motor();

    Schalter& operator=(const Schalter&);
    //    friend Controler;
};

#endif // SCHALTER_H
