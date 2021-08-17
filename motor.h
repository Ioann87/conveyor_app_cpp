#ifndef MOTOR_H
#define MOTOR_H

//#include <schalter.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

class Motor {
protected:
    //physical characteristics
    double U_in; //v
    double f_in; //Hz
    int speed; //rpm
    bool ABC;
    bool on;
    bool off;

public:
    //graphics
    int x;
    int y;
    std::string path;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Motor();
    ~Motor() {};
    void set_U(double);
    double get_U();
    void set_f(double);
    double get_f();
    void set_speed(int);
    int get_speed();
    void set_ABC(bool);
    bool get_ABC();
    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();

    void set_position(int x, int y)
    {
        this->x = x;
        this->y = y;
        sprite.setPosition(x, y);
        return;
    }

    void motor_move()
    {
        int rad = 0;

        while (rad != 100) {

            sprite.rotate(rad);
            rad += 1;
        }
        return;
    }

    void start(int, int, bool);
    void move(int, int);
    void stop();
    void choice_side();
    void rotate_forward();
    void rotate_back();
    void statistic();

    Motor& operator=(const Motor&);
    //    friend Schalter;
};

#endif // MOTOR_H
