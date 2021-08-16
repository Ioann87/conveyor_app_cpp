#ifndef CONVEYOR_H
#define CONVEYOR_H

#include <motor.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

class Conveyor {
public:
    std::string path;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Conveyor();

    void conveyor_on();
};

#endif // CONVEYOR_H