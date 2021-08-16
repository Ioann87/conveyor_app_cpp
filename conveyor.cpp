#include "conveyor.h"

Conveyor::Conveyor()
{
    path = "/home/shastiva/c_projects/conveyor/conveyor.png";
}

void Conveyor::conveyor_on()
{
    image.loadFromFile(path);
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    sprite.setPosition(0, 0);

    //create window application
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Conveyor");

    std::vector<Motor> motors;
    motors.reserve(10);

    int x0 = 20;
    int y0 = 20;

    Motor mot1, mot2, mot3;
    mot1.set_position(x0 + 20, y0 + 100);
    mot2.set_position(x0 + 140, y0 + 100);
    mot3.set_position(x0 + 260, y0 + 100);

    while (window.isOpen()) {
        //----------------------------------
        sf::Vector2i position = sf::Mouse::getPosition(window);
        std::cout << "x=" << position.x << " y=" << position.y << std::endl;

        sf::Event event;

        //        for (size_t i = 0; i < 10; i++) {
        //            motors[i].set_position(x0, y0 + 100);
        //            x0 += 100;
        //        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //motor rotation

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {

            //            sf::Transform transform1, transform2, transform3;
            //            transform1.rotate(25, { 40, 120 });
            //            window.draw(c, transform);
            mot1.motor_move();
            mot2.motor_move();
            mot3.motor_move();
            //            transform2.rotate(25, { 160, 120 });
            //            transform3.rotate(25, { 280, 120 });
            //            window.draw(mot1.sprite, transform1);
            //            window.draw(mot2.sprite, transform2);
            //            window.draw(mot3.sprite, transform3);
        }

        window.clear(sf::Color(50, 50, 50, 50));
        window.draw(sprite);
        //motor draw
        window.draw(mot1.sprite);
        window.draw(mot2.sprite);
        window.draw(mot3.sprite);
        //        for (size_t i = 0; i < 10; i++) {
        //            motors[i].set_position(x0, y0 + 100);
        //            x0 += 100;
        //            window.draw(motors[i].sprite);
        //        }
        window.display();
    }
}
