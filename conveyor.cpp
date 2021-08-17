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

    //    Table tab1, tab2, tab3;
    //    tab1.set_position(x0, y0);
    //    tab2.set_position(x0 + 120, y0);
    //    tab3.set_position(x0 + 240, y0);
    //tables init
    std::vector<Table> tables;
    tables.reserve(10);

    //    Table table;
    //    for (size_t i = 0, x = 20, y = 20; i < 10; i++, x += 120) {
    //        table.set_position(x, y);
    //        tables.push_back(table);
    //        std::cout << &tables[i] << std::endl;
    //    }

    //schalters init
    std::vector<Schalter> schalters;
    schalters.reserve(10);
    Schalter schalter;
    for (size_t i = 0, x = 20, y = 220; i < 10; i++, x += 120) {
        schalter.set_position(x, y);
        schalters.push_back(schalter);
        std::cout << &schalters[i] << std::endl;
    }

    //controller init
    Controler controller;
    Table table;
    for (size_t i = 0, x = 20, y = 20; i < 10; i++, x += 120) {
        table.set_position(x, y);
        controller.set_tables(table);
        std::cout << &tables[i] << std::endl;
    }
    Controler::ButtonOn but_on;
    Controler::ButtonOff but_off;
    Controler::ButtonDirection but_dir;
    Controler::ButtonStop but_stop;

    tables = controller.get_tables();

    while (window.isOpen()) {
        //----------------------------------
        sf::Vector2i position = sf::Mouse::getPosition(window);
        //        std::cout << "x=" << position.x << " y=" << position.y << std::endl;

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
            //            mot1.motor_move();
            //            mot2.motor_move();
            //            mot3.motor_move();
            for (size_t i = 0; i < 10; i++)
                motors[i].motor_move();

            for (size_t i = 0; i < 10; i++)
                tables[i].table_move(rand() % 3 + 1);

            for (size_t i = 0; i < 10; i++)
                schalters[i].schalter_on_off(rand() % 3 + 1);

            //            tab1.table_move(1);
            //            tab2.table_move(2);
            //            tab3.table_move(3);
            //            transform2.rotate(25, { 160, 120 });
            //            transform3.rotate(25, { 280, 120 });
            //            window.draw(mot1.sprite, transform1);
            //            window.draw(mot2.sprite, transform2);
            //            window.draw(mot3.sprite, transform3);
        } else {
            for (size_t i = 0; i < 10; i++)
                tables[i].table_move(3);
            for (size_t i = 0; i < 10; i++)
                schalters[i].schalter_on_off(44);
        }

        window.clear(sf::Color(50, 50, 50, 50));
        window.draw(sprite);
        //motor draw
        for (size_t i = 0; i < 10; i++)
            window.draw(motors[i].sprite);

        //        window.draw(mot1.sprite);
        //        window.draw(mot2.sprite);
        //        window.draw(mot3.sprite);
        //table draw

        for (size_t i = 0; i < 10; i++)
            window.draw(tables[i].sprite);

        // schalter draw
        for (size_t i = 0; i < 10; i++)
            window.draw(schalters[i].sprite);

        window.draw(but_on.sprite_on);
        window.draw(but_off.sprite_off);
        window.draw(but_dir.sprite_dir);
        window.draw(but_stop.sprite_stop);

        //        window.draw(tab1.sprite);
        //        window.draw(tab2.sprite);
        //        window.draw(tab3.sprite);

        //        for (size_t i = 0; i < 10; i++) {
        //            motors[i].set_position(x0, y0 + 100);
        //            x0 += 100;
        //            window.draw(motors[i].sprite);
        //        }
        window.display();
    }
}
