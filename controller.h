#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <motor.h>
#include <schalter.h>
#include <table.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Controler {
private:
    bool on;
    bool off;
    bool dir_f;
    bool dir_b;
    bool run;
    bool stop;
    //    Table tab;
protected:
public:
    std::vector<Table> tables;
    std::vector<Schalter> schalters;
    std::vector<Motor> motors;
    //graphics
    //    int x;
    //    int y;
    //    std::string path;
    //    sf::Image image;
    //    sf::Texture texture;
    //    sf::Sprite sprite;

    //buttons classes and graphics
    class ButtonOn {
    public:
        int x;
        int y;
        std::string path;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite_on;
        ButtonOn()
        {
            //graphic
            path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
            image.loadFromFile(path);
            image.createMaskFromColor(sf::Color(255, 255, 255));
            texture.loadFromImage(image);
            sprite_on.setTexture(texture);
            sprite_on.setTextureRect(sf::IntRect(0, 0, 80, 80));
            sprite_on.setColor(sf::Color(8, 110, 22));
            sprite_on.setPosition(80, 440);
            //    sprite.setOrigin(40 / 2, 40 / 2);
        }
        friend Controler;
    };
    class ButtonOff {
    public:
        int x;
        int y;
        std::string path;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite_off;
        ButtonOff()
        {
            //graphic
            path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
            image.loadFromFile(path);
            image.createMaskFromColor(sf::Color(255, 255, 255));
            texture.loadFromImage(image);
            sprite_off.setTexture(texture);
            sprite_off.setTextureRect(sf::IntRect(100, 0, 80, 80));
            sprite_off.setPosition(200, 440);
            //    sprite.setOrigin(40 / 2, 40 / 2);
        }
        friend Controler;
    };
    class ButtonDirection {
    public:
        int x;
        int y;
        std::string path;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite_dir;
        ButtonDirection()
        {
            //graphic
            path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
            image.loadFromFile(path);
            image.createMaskFromColor(sf::Color(255, 255, 255));
            texture.loadFromImage(image);
            sprite_dir.setTexture(texture);
            sprite_dir.setTextureRect(sf::IntRect(120, 100, 40, 40));
            sprite_dir.setPosition(360, 600);
            //    sprite.setOrigin(40 / 2, 40 / 2);
        }
        friend Controler;
    };
    class ButtonRun {
    public:
        int x;
        int y;
        std::string path;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite_run;
        ButtonRun()
        {
            //graphic
            path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
            image.loadFromFile(path);
            image.createMaskFromColor(sf::Color(255, 255, 255));
            texture.loadFromImage(image);
            sprite_run.setTexture(texture);
            sprite_run.setTextureRect(sf::IntRect(200, 0, 80, 80));
            //            sprite_run.setOrigin(80 / 2, 80 / 2);
            sprite_run.setPosition(360, 440);
            //    sprite.setOrigin(40 / 2, 40 / 2);
        }
        friend Controler;
    };

    class ButtonStop {
    public:
        int x;
        int y;
        std::string path;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite_stop;
        ButtonStop()
        {
            //graphic
            path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
            image.loadFromFile(path);
            image.createMaskFromColor(sf::Color(255, 255, 255));
            texture.loadFromImage(image);
            sprite_stop.setTexture(texture);
            sprite_stop.setTextureRect(sf::IntRect(0, 100, 80, 80));
            sprite_stop.setOrigin(80 / 2, 80 / 2);
            sprite_stop.setPosition(120, 600);
            //    sprite.setOrigin(40 / 2, 40 / 2);
        }
        friend Controler;
    };

    //controllers methods and constructors
    Controler();
    ~Controler() {};

    void controller_on()
    {
        for (size_t i = 0; i < 10; i++) {
            tables[i].table_move(rand() % 3 + 1);
        }
        return;
    }

    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();
    void set_dir_f(bool);
    bool get_dir_f();
    void set_dir_b(bool);
    bool get_dir_b();
    void set_run(bool);
    bool get_run();
    void set_stop(bool);
    bool get_stop();

    void set_tables(Table&);
    std::vector<Table> get_tables();
    void set_schalter(Schalter&);
    std::vector<Schalter> get_schalters();
    void set_motor(Motor&);
    std::vector<Motor> get_motors();

    friend ButtonOn;
    friend ButtonOff;
    friend ButtonDirection;
    friend ButtonStop;
};

#endif // CONTROLLER_H
