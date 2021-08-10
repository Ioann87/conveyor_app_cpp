#include <requirements.h>

int main()
{
    //    Motor motor;
    //    Schalter schal;
    //    Table tab;

    //    schal.set_motor(motor);

    //    tab.set_schalter(schal);

    //    tab.statistic();

    //    tab.connect_table(true);

    //    tab.statistic();

    //    tab.take_signal(true, true);

    //    tab.statistic();

    //    tab.take_signal(false, true);

    //    tab.statistic();

    //    tab.take_signal(true, false);

    //    tab.statistic();

    //    int arr[30] = { 0 };
    //    //    arr[0] = 1;
    //    //    arr[1] = 1;
    //    int j = 0;
    //    int k = 0;
    //    int s1 = 1;
    //    int s2 = 2;
    //    int temp = 0;
    //    //    bool sign = false;
    //    //    cin >> sign;
    //    //    if (sign) {
    //    while (true) {
    //        //        arr[j] = s1;
    //        for (int i = 0; i < 30; i++) {
    //            cout << arr[i] << " ";
    //        }
    //        cout << endl;

    //        //            arr[j] = s2;
    //        //            arr[j - 1] = s1;
    //        //            arr[j - 2] = 0;
    //        //            //            arr[j - 29] = s1;
    //        //            j = 0;
    //        //        }
    //        //        arr[j] = s1;
    //        //        j++;
    //        //        arr[j] = s1;
    //        //        if (j >= 2) {
    //        //            arr[j - 1] = s2;
    //        //            arr[j - 2] = s1;
    //        //            arr[j - 3] = 0;
    //        //        } else if (j >= 4) {
    //        //            arr[0] = arr[29];
    //        //        }

    //        //        j++;
    //        arr[k] = s1;
    //        arr[k - 1] = s2;
    //        for (j = 29; j > 0; j--) {
    //            arr[j] = arr[j - 1];
    //            //            arr[j - 29] = arr[j];
    //        }

    //        k++;

    //        if (k >= 2) {
    //            arr[k - 1] = s2;
    //            arr[k - 2] = s1;
    //            arr[k - 3] = 0;
    //            arr[0] = arr[29];
    //        }

    //        sleep(1);
    //        //        if (arr[29] == 1)
    //        //            break;
    //        //        arr[j - 2] = 0;
    //        //        arr[j - 1] = 1;
    //        //        arr[j] = 2;
    //        //        arr[j + 1] = 1;
    //        //        arr[j + 2] = 1;

    //        //        j++;
    //    }
    //    //    }

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Conveyor");

    sf::Image conv_tab;

    conv_tab.loadFromFile("/home/shastiva/c_projects/conveyor/conveyor.png");

    sf::Texture conv_texture;

    conv_texture.loadFromImage(conv_tab);

    sf::Sprite conv_sprite;

    conv_sprite.setTexture(conv_texture);
    conv_sprite.setPosition(0, 0);
    int x = 20;
    int y = 20;

    bool log[10] = { 0 };

    bool dir = false;

    //Controller buttons

    RectangleShape but_on;
    but_on.setSize(Vector2f(80, 80));
    if (dir)
        but_on.setFillColor(Color::Green);
    else
        but_on.setFillColor(Color(50, 50, 50));
    but_on.setPosition(80, 440);

    RectangleShape but_off;
    but_off.setSize(Vector2f(80, 80));
    if (dir)
        but_off.setFillColor(Color(50, 50, 50));
    else
        but_off.setFillColor(Color::Red);
    but_off.setPosition(200, 440);

    CircleShape but_stop;
    if (!dir) {
        but_stop.setRadius(40);
        but_stop.setFillColor(Color(200, 0, 0));
        but_stop.setOutlineThickness(10);
        but_stop.setOutlineColor(Color(50, 50, 50));
    } else {
        but_stop.setRadius(40);
        but_stop.setFillColor(Color(250, 0, 0));
    }
    but_stop.setPosition(80, 560);

    RectangleShape but_run;
    but_run.setSize(Vector2f(80, 80));
    if (dir) {
        but_run.setFillColor(Color(255, 165, 0));
    } else {
        but_run.setFillColor(Color(255, 140, 0));
    }
    but_run.setPosition(360, 440);

    RectangleShape but_dir;
    but_dir.setSize(Vector2f(40, 40));
    but_dir.setFillColor(Color(0, 0, 0, 190));
    if (dir)
        but_dir.setPosition(360, 600);
    else
        but_dir.setPosition(400, 600);

    //Tables, motors, schalters

    sf::RectangleShape rect[10];
    CircleShape circ[10];
    RectangleShape schal_on[10];
    RectangleShape schal_off[10];

    for (size_t i = 0; i < 10; i++) {
        rect[i].setSize(sf::Vector2f(100, 50));
        circ[i].setRadius(20);
        //schalter on and direction
        schal_on[i].setSize(Vector2f(20, 40));
        schal_on[i].setFillColor(Color::Green);
        if (dir)
            schal_on[i].setPosition(x + 20, y + 160);
        else
            schal_on[i].setPosition(x, y + 160);

        schal_off[i].setSize(Vector2f(40, 40));
        schal_off[i].setPosition(x, y + 200);
        if (!dir)
            schal_off[i].setFillColor(Color::Red);
        else
            schal_off[i].setFillColor(Color(50, 50, 50));
        if (dir)
            rect[i].setFillColor(sf::Color::Green);
        else
            rect[i].setFillColor(sf::Color::Red);
        rect[i].setPosition(x, y);
        circ[i].setFillColor(Color::Blue);
        circ[i].setPosition(x, y + 80);
        x += 120;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(conv_sprite);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            for (size_t i = 0; i < 10; i++) {
                window.draw(schal_on[i]);
                window.draw(schal_off[i]);
                window.draw(rect[i]);
                window.draw(circ[i]);
            }
        window.draw(but_on);
        window.draw(but_off);
        window.draw(but_stop);
        window.draw(but_run);
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            but_dir.setPosition(360, 600);
            //            IntRect(400, 600, 40, 40);
            //            but_dir.setPosition(400, 600);
            but_dir.setFillColor(Color(0, 0, 0, 190));
            window.draw(but_dir);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            for (size_t i = 0; i < 10; i++) {
                schal_on[i].setPosition(x + 20, y + 160);
            }
            but_dir.setPosition(400, 600);
            //            IntRect(400, 600, 40, 40);
            //            but_dir.setPosition(400, 600);
            but_dir.setFillColor(Color(0, 0, 0, 190));
            for (size_t i = 0; i < 10; i++)
                window.draw(schal_on[i]);
            window.draw(but_dir);
        }

        if (Mouse::isButtonPressed(Mouse::Right)) {
            but_dir.setPosition(360, 600);
            window.draw(but_dir);
        }
        window.display();
    }
    return 0;
}
