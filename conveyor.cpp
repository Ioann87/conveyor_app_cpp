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

    int x0 = 20;
    int y0 = 20;
    //motors init
    std::vector<Motor> motors;
    motors.reserve(10);
    Motor motor;
    for (size_t i = 0, x = 40, y = 120; i < 10; i++, x += 120) {

        motor.set_position(x, y);
        motors.push_back(motor);
        std::cout << &motors[i] << std::endl;
    }

    //schalters init
    std::vector<Schalter> schalters;
    schalters.reserve(10);
    Schalter schalter;
    for (size_t i = 0, x = 20, y = 220; i < 10; i++, x += 120) {

        schalter.set_position(x, y);
        schalters.push_back(schalter);
        std::cout << &schalters[i] << std::endl;
    }

    //tables init
    std::vector<Table> tables;
    tables.reserve(10);

    Table table;
    for (size_t i = 0, x = 20, y = 20; i < 10; i++, x += 120) {

        table.set_position(x, y);
        tables.push_back(table);
        std::cout << &tables[i] << std::endl;
    }

    //controller init
    Controler controller;

    for (size_t i = 0; i < 10; i++) {
        controller.set_tables(tables[i]);
        controller.set_motor(motors[i]);
        controller.set_schalter(schalters[i]);
    }
    Controler::ButtonOn but_on;
    Controler::ButtonOff but_off;
    Controler::ButtonDirection but_dir;
    Controler::ButtonStop but_stop;
    Controler::ButtonRun but_run;

    tables = controller.get_tables();

    sf::CircleShape stop;
    stop.setRadius(40.f);
    stop.setFillColor(sf::Color(252, 11, 7));
    stop.setOutlineThickness(10);
    stop.setOutlineColor(sf::Color(255, 17, 0));
    stop.setPosition(120, 600);

    while (window.isOpen()) {
        //----------------------------------
        sf::Vector2i position = sf::Mouse::getPosition(window);
        //        std::cout << "x=" << position.x << " y=" << position.y << std::endl;

        sf::Event event;

        window.draw(sprite);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //controllers buttons
        //direction

        //backward
        if (360 <= position.x && position.x <= 400 && 600 <= position.y && position.y <= 640)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    controller.set_dir_b(true);
                    controller.set_dir_f(false);
                    but_dir.sprite_dir.setPosition(400, 600);
                    if (controller.get_on())
                        for (size_t i = 0; i < 10; i++) {
                            controller.schalters[i].set_direction(false);
                            controller.schalters[i].schalter_on_off();
                            window.draw(controller.schalters[i].sprite);
                        }
                    window.draw(but_dir.sprite_dir);
                }

        //forward
        if (400 <= position.x && position.x <= 440 && 600 <= position.y && position.y <= 640)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    controller.set_dir_b(false);
                    controller.set_dir_f(true);
                    but_dir.sprite_dir.setPosition(360, 600);
                    if (controller.get_on()) {
                        for (size_t i = 0; i < 10; i++) {
                            controller.schalters[i].set_direction(true);
                            controller.schalters[i].schalter_on_off();
                            window.draw(controller.schalters[i].sprite);
                        }
                    }
                    window.draw(but_dir.sprite_dir);
                }

        //run
        if (360 <= position.x && position.x <= 440 && 440 <= position.y && position.y <= 520)
            if (event.type == sf::Event::MouseButtonPressed)
                if (controller.get_on())
                    if (event.key.code == sf::Mouse::Left) {
                        controller.set_run(true);

                        but_run.sprite_run.setTextureRect(sf::IntRect(300, 0, 80, 80));
                        window.draw(but_run.sprite_run);

                        for (size_t i = 0; i < 10; i++) {

                            controller.motors[i].motor_move();
                            controller.tables[i].table_move(rand() % 3 + 1);

                            //controller.schalters[i].set_direction(controller.get_dir_b());
                            controller.schalters[i].schalter_on_off();
                        }
                    }

        //on / off
        //on
        if (80 <= position.x && position.x <= 160 && 440 <= position.y && position.y <= 520)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    controller.set_on(true);
                    controller.set_off(false);

                    for (size_t i = 0; i < 10; i++) {
                        controller.schalters[i].schalter_on();
                    }
                    but_on.sprite_on.setColor(sf::Color(0, 255, 34));
                    but_off.sprite_off.setColor(sf::Color(96, 1, 0));

                    window.draw(but_on.sprite_on);
                    window.draw(but_off.sprite_off);
                }
        //off
        if (200 <= position.x && position.x <= 280 && 440 <= position.y && position.y <= 520)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    controller.set_on(false);
                    controller.set_off(true);
                    for (size_t i = 0; i < 10; i++) {
                        controller.schalters[i].schalter_off();
                        controller.tables[i].table_move(3);
                    }
                    but_on.sprite_on.setColor(sf::Color(8, 110, 22));
                    but_off.sprite_off.setColor(sf::Color(252, 11, 7));
                    but_run.sprite_run.setColor(sf::Color(255, 157, 0));

                    window.draw(but_on.sprite_on);
                    window.draw(but_off.sprite_off);
                }

        //stop
        if (80 <= position.x && position.x <= 160 && 560 <= position.y && position.y <= 640)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    controller.set_stop(true);
                    controller.set_on(false);
                    controller.set_off(true);

                    controller.set_run(false);
                    controller.set_dir_b(false);
                    controller.set_dir_f(true);

                    but_on.sprite_on.setColor(sf::Color(8, 110, 22));
                    but_off.sprite_off.setColor(sf::Color(252, 11, 7));
                    but_run.sprite_run.setTextureRect(sf::IntRect(200, 0, 80, 80));
                    but_dir.sprite_dir.setPosition(360, 600);

                    for (size_t i = 0; i < 10; i++)
                        controller.schalters[i].schalter_off();

                    window.draw(but_on.sprite_on);
                    window.draw(but_off.sprite_off);
                    window.draw(but_dir.sprite_dir);
                    window.draw(but_run.sprite_run);
                    for (size_t i = 0; i < 10; i++)
                        controller.tables[i].table_move(3);
                }

        //motor rotation

        window.draw(but_on.sprite_on);
        window.draw(but_off.sprite_off);
        window.draw(but_dir.sprite_dir);
        window.draw(but_stop.sprite_stop);
        window.draw(but_run.sprite_run);
        for (size_t i = 0; i < 10; i++) {
            window.draw(controller.schalters[i].sprite);

            window.draw(controller.motors[i].sprite);
            window.draw(controller.tables[i].sprite);
        }

        window.display();
    }
}
