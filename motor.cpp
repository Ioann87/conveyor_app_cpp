#include <motor.h>

Motor::Motor()
{
    U_in = 0;
    f_in = 0;
    speed = 0;
    ABC = true;
    on = false;
    off = true;

    //graphic
    path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
    image.loadFromFile(path);
    image.createMaskFromColor(sf::Color(255, 255, 255));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(320, 100, 40, 40));
    sprite.setOrigin(40 / 2, 40 / 2);
}

void Motor::start(int U, int f, bool direction)
{
    std::cout << "signal to start" << std::endl;
    set_on(true);
    set_off(false);
    set_U(U);
    set_f(f);
    set_speed(1500);
    set_ABC(direction);
    choice_side();

    return;
}

void Motor::move(int U, int f)
{
    set_U(U);
    set_f(f);
    set_speed(3000);

    return;
}

void Motor::stop()
{

    std::cout << "signal to stop.." << std::endl;
    set_on(false);
    set_off(true);
    set_U(0);
    set_f(0);
    set_speed(0);
    set_ABC(true);
    std::cout << "motor off" << std::endl;

    return;
}

void Motor::choice_side()
{
    if (ABC) {
        rotate_forward();
    } else {
        rotate_back();
    }
    return;
}

void Motor::rotate_forward()
{
    std::cout << "motor rotate front" << std::endl;
    return;
}
void Motor::rotate_back()
{
    std::cout << "motor rotate back" << std::endl;
    return;
}

void Motor::statistic()
{
    std::cout << "Motor: " << std::endl;
    std::cout << (on ? "ON" : "OFF") << std::endl;
    std::cout << "V: " << get_U() << std::endl;
    std::cout << "Hz: " << get_f() << std::endl;
    std::cout << "RPM: " << get_speed() << std::endl;
    std::cout << (ABC ? "ABC" : "ACB") << std::endl;
    return;
}

void Motor::set_U(double U) { this->U_in = U; }
double Motor::get_U() { return U_in; }
void Motor::set_f(double f) { this->f_in = f; }
double Motor::get_f() { return f_in; }
void Motor::set_speed(int speed) { this->speed = speed; }
int Motor::get_speed() { return speed; }
void Motor::set_ABC(bool ABC) { this->ABC = ABC; }
bool Motor::get_ABC() { return ABC; }
void Motor::set_on(bool on) { this->on = on; }
bool Motor::get_on() { return on; }
void Motor::set_off(bool off) { this->off = off; }
bool Motor::get_off() { return off; }

Motor& Motor::operator=(const Motor& motor)
{
    this->set_U(motor.U_in);
    this->set_f(motor.f_in);
    this->set_ABC(motor.ABC);
    this->set_speed(motor.speed);
    this->set_on(motor.on);
    this->set_off(motor.off);
    return *this;
}
