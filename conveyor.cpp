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

    //timer
    sf::Clock clock;
    float timer = 0;
    float stop_timer = 0;

    //text
    sf::Font font;
    font.loadFromFile("/home/shastiva/c_projects/conveyor/arial.ttf");
    //info
    sf::Text info("", font);
    info.setPosition(x0 + 480, y0 + 360);
    info.setCharacterSize(30);
    info.setColor(sf::Color::Black);
    info.setString("Information: ");
    //stop
    sf::Text push_stop("STOP CONVEYOR", font);
    push_stop.setPosition(x0 + 650, y0 + 340);
    push_stop.setCharacterSize(50);
    push_stop.setColor(sf::Color::White);
    //direction phases
    sf::Text dir("", font);
    dir.setPosition(x0 + 480, y0 + 400);
    dir.setCharacterSize(30);
    dir.setColor(sf::Color::Black);
    dir.setString("Phases: ABC");
    //speed rotation
    sf::Text speed("", font);
    speed.setPosition(x0 + 480, y0 + 440);
    speed.setCharacterSize(30);
    speed.setColor(sf::Color::Black);
    speed.setString("RPM: 0");
    //schalters characteristics
    sf::Text
        schal("", font),
        u_in("", font),
        f_in("", font),
        u_out("", font),
        f_out("", font);
    //on off
    schal.setPosition(x0 + 480, y0 + 480);
    schal.setCharacterSize(30);
    schal.setColor(sf::Color::Black);
    schal.setString("Schalter: OFF");
    //voltage in
    u_in.setPosition(x0 + 520, y0 + 520);
    u_in.setCharacterSize(30);
    u_in.setColor(sf::Color::Black);
    u_in.setString("U_in(V): 0");
    //frequence in
    f_in.setPosition(x0 + 520, y0 + 560);
    f_in.setCharacterSize(30);
    f_in.setColor(sf::Color::Black);
    f_in.setString("f_in(Hz): 0");
    //voltage out
    u_out.setPosition(x0 + 520, y0 + 600);
    u_out.setCharacterSize(30);
    u_out.setColor(sf::Color::Black);
    u_out.setString("U_out(V): 0");
    //frequence out
    f_out.setPosition(x0 + 520, y0 + 640);
    f_out.setCharacterSize(30);
    f_out.setColor(sf::Color::Black);
    f_out.setString("f_out(Hz): 0");

    //action
    while (window.isOpen()) {
        //timer
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        if (controller.get_run())
            timer += time;
        else if (controller.get_stop())
            stop_timer += time;
        else {
            timer = 0;
            stop_timer = 0;
        }

        std::cout << timer << " : " << stop_timer << std::endl;

        //        std::cout << time << std::endl;
        //----------------------------------
        sf::Vector2i position = sf::Mouse::getPosition(window);

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
                            controller.motors[i].set_ABC(false);
                            controller.schalters[i].schalter_on_off();
                            window.draw(controller.schalters[i].sprite);
                            //                            window.draw(controller.motors[i].info);
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
                            controller.motors[i].set_ABC(true);
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
                        controller.set_off(false);
                        controller.set_stop(false);
                        but_run.sprite_run.setTextureRect(sf::IntRect(300, 0, 80, 80));
                        window.draw(but_run.sprite_run);
                        for (size_t i = 0; i < 10; i++) {
                            controller.schalters[i].start_motor(controller.get_dir_f());
                            controller.schalters[i].schalter_on_off();
                        }
                        push_stop.setColor(sf::Color::White);
                    }

        if (controller.get_run()) {
            if (timer < 3000) {
                for (size_t i = 0; i < 10; i++) {
                    if (controller.get_dir_f()) {
                        dir.setString("Phases: ABC");
                        controller.motors[i].sprite.rotate(1);
                        controller.tables[i].table_move(1);
                    } else if (controller.get_dir_b()) {
                        dir.setString("Phases: ACB");
                        controller.motors[i].sprite.rotate(-1);
                        controller.tables[i].table_move(1);
                    }
                }
                speed.setString("RPM: 1500");
                u_out.setString("U_out(V): 200");
                f_out.setString("f_out(Hz): 25");
            } else {
                for (size_t i = 0; i < 10; i++) {
                    if (controller.get_dir_f()) {
                        dir.setString("Phases: ABC");
                        controller.motors[i].sprite.rotate(5);
                        controller.tables[i].table_move(2);

                    } else if (controller.get_dir_b()) {
                        dir.setString("Phases: ACB");
                        controller.motors[i].sprite.rotate(-5);
                        controller.tables[i].table_move(2);
                    }
                }
                speed.setString("RPM: 3000");
                u_out.setString("U_out(V): 400");
                f_out.setString("f_out(Hz): 50");
            }
        }

        //
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
                    schal.setString("Schalter: ON");
                    u_in.setString("U_in(V): 400");
                    f_in.setString("f_in(Hz): 50");
                    u_out.setString("U_out(V): 0");
                    f_out.setString("f_out(Hz): 0");
                }
        //off
        if (200 <= position.x && position.x <= 280 && 440 <= position.y && position.y <= 520)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {

                    controller.set_on(false);
                    controller.set_off(true);
                    controller.set_run(false);
                    for (size_t i = 0; i < 10; i++) {
                        controller.schalters[i].schalter_off();
                        controller.tables[i].table_move(3);
                    }
                    but_on.sprite_on.setColor(sf::Color(8, 110, 22));
                    but_off.sprite_off.setColor(sf::Color(252, 11, 7));
                    but_run.sprite_run.setColor(sf::Color(255, 157, 0));

                    window.draw(but_on.sprite_on);
                    window.draw(but_off.sprite_off);
                    schal.setString("Schalter: OFF");
                    u_in.setString("U_in(V): 0");
                    f_in.setString("f_in(Hz): 0");
                    u_out.setString("U_out(V): 0");
                    f_out.setString("f_out(Hz): 0");
                }
        if (controller.get_off()) {

            timer += time;
            if (timer < 2000) {
                for (size_t i = 0; i < 10; i++) {
                    controller.motors[i].sprite.rotate(1);
                    controller.tables[i].table_move(1);
                }
                speed.setString("RPM: 1500");
                u_in.setString("U_in(V): 400");
                f_in.setString("f_in(Hz): 50");
                u_out.setString("U_out(V): 200");
                f_out.setString("f_out(Hz): 25");
            } else {
                for (size_t i = 0; i < 10; i++) {
                    controller.tables[i].table_move(3);
                    controller.motors[i].sprite.rotate(0);
                }
                speed.setString("RPM: 0");
                u_in.setString("U_in(V): 0");
                f_in.setString("f_in(Hz): 0");
                u_out.setString("U_out(V): 0");
                f_out.setString("f_out(Hz): 0");
            }
        }

        //        if (controller.get_off()) {
        //            if (timer < 3000)
        //                for (size_t i = 0; i < 10; i++) {

        //                    if (controller.get_dir_f()) {
        //                        controller.motors[i].sprite.rotate(10 * time);

        //                        controller.tables[i].table_move(2);

        //                    } else {
        //                        controller.motors[i].sprite.rotate(-1 * time);
        //                    }
        //                }
        //            else
        //                for (size_t i = 0; i < 10; i++) {
        //                    if (controller.get_dir_f()) {
        //                        controller.motors[i].sprite.rotate(1 * time);

        //                        controller.tables[i].table_move(1);

        //                    } else {
        //                        controller.motors[i].sprite.rotate(-10 * time);
        //                    }
        //                }
        //        }

        //stop
        if (80 <= position.x && position.x <= 160 && 560 <= position.y && position.y <= 640)
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left) {
                    timer = 0;
                    controller.set_stop(true);
                    controller.set_on(true);
                    controller.set_off(false);

                    controller.set_run(false);
                    controller.set_dir_b(false);
                    controller.set_dir_f(true);

                    //                    but_on.sprite_on.setColor(sf::Color(8, 110, 22));
                    //                    but_off.sprite_off.setColor(sf::Color(252, 11, 7));
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
                    schal.setString("Schalter: ON");
                    push_stop.setColor(sf::Color::Red);

                    //                    u_in.setString("U_in(V): 0");
                    //                    f_in.setString("f_in(Hz): 0");
                    //                    u_out.setString("U_out(V): 0");
                    //                    f_out.setString("f_out(Hz): 0");
                }

        if (controller.get_stop()) {
            stop_timer += time;
            if (timer < 2000) {
                for (size_t i = 0; i < 10; i++) {
                    controller.motors[i].sprite.rotate(1);
                    controller.tables[i].table_move(1);
                    speed.setString("RPM: 1500");
                    u_in.setString("U_in(V): 400");
                    f_in.setString("f_in(Hz): 50");
                    u_out.setString("U_out(V): 200");
                    f_out.setString("f_out(Hz): 25");
                }
            } else {
                for (size_t i = 0; i < 10; i++) {
                    controller.tables[i].table_move(3);
                    speed.setString("RPM: 0");
                    u_in.setString("U_in(V): 400");
                    f_in.setString("f_in(Hz): 50");
                    u_out.setString("U_out(V): 0");
                    f_out.setString("f_out(Hz): 0");
                    controller.motors[i].sprite.rotate(0);
                }
            }
        }
        //        if (controller.get_stop()) {

        //            if (timer < 3000)
        //                for (size_t i = 0; i < 10; i++) {

        //                    if (controller.get_dir_f()) {
        //                        controller.motors[i].sprite.rotate(10 * time);

        //                        controller.tables[i].table_move(2);

        //                    } else {
        //                        controller.motors[i].sprite.rotate(-10 * time);
        //                    }
        //                }

        //            else if (timer < 4000)
        //                for (size_t i = 0; i < 10; i++) {
        //                    if (controller.get_dir_f()) {
        //                        controller.motors[i].sprite.rotate(1 * time);

        //                        controller.tables[i].table_move(1);

        //                    } else {
        //                        controller.motors[i].sprite.rotate(-10 * time);
        //                        controller.tables[i].table_move(3);
        //                    }
        //                }
        //            else
        //                for (size_t i = 0; i < 10; i++)
        //                    window.draw(controller.motors[i].sprite);
        //        }

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
        window.draw(info);
        window.draw(push_stop);
        window.draw(dir);
        window.draw(speed);
        window.draw(schal);
        window.draw(u_in);
        window.draw(f_in);
        window.draw(u_out);
        window.draw(f_out);
        window.display();
    }
}
