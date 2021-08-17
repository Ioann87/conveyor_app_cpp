#include <schalter.h>

Schalter::Schalter()
{
    on = false;
    off = true;
    U_in = 0;
    f_in = 0;
    U_out = 0;
    f_out = 0;
    signal = false;
    direction = true;

    //graphic
    path = "/home/shastiva/c_projects/conveyor/conv_texture.png";
    image.loadFromFile(path);
    image.createMaskFromColor(sf::Color(255, 255, 255));
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(200, 100, 40, 40));
    //    sprite.setOrigin(40 / 2, 40 / 2);
}

void Schalter::statistic()
{
    std::cout << "Schalter: " << std::endl;
    std::cout << (on ? "ON" : "OFF") << std::endl;
    std::cout << "U_in: " << U_in << std::endl;
    std::cout << "f_in: " << f_in << std::endl;
    std::cout << "U_out: " << U_out << std::endl;
    std::cout << "f_out: " << f_out << std::endl;
    std::cout << "signal: " << signal << std::endl;
    std::cout << "direction: " << (direction ? "forward" : "back")
              << std::endl;
    motor.statistic();
    return;
}

void Schalter::schalter_on()
{
    set_on(true);
    set_off(false);
    set_U(400);
    set_f(50);

    return;
}

void Schalter::schalter_off()
{
    set_off(true);
    set_on(false);
    set_U(0);
    set_f(0);

    return;
}

void Schalter::start_motor(bool direction)
{
    set_signal(true);
    set_direction(direction);
    motor.set_ABC(direction);
    set_U_out(200);
    set_f_out(25);
    motor.start(U_out, f_out, direction);
    set_U_out(400);
    set_f_out(50);
    motor.move(U_out, f_out);

    return;
}

void Schalter::stop_motor()
{
    set_U_out(0);
    set_f_out(0);
    set_signal(0);
    motor.stop();

    return;
}

void Schalter::set_on(bool on) { this->on = on; }
bool Schalter::get_on() { return on; }
void Schalter::set_off(bool off) { this->off = off; }
bool Schalter::get_off() { return off; }
void Schalter::set_U(int U) { this->U_in = U; }
int Schalter::get_U() { return U_in; }
void Schalter::set_f(int f) { this->f_in = f; }
int Schalter::get_f() { return f_in; }
void Schalter::set_U_out(int U) { this->U_out = U; }
int Schalter::get_U_out() { return U_out; }
void Schalter::set_f_out(int f) { this->f_out = f; }
int Schalter::get_f_out() { return f_out; }
void Schalter::set_signal(bool signal) { this->signal = signal; }
bool Schalter::get_signal() { return signal; }
void Schalter::set_direction(bool direction) { this->direction = direction; }
bool Schalter::get_direction() { return direction; }

void Schalter::set_motor(Motor motor) { this->motor = motor; }
Motor Schalter::get_motor() { return motor; }

Schalter& Schalter::operator=(const Schalter& schal)
{
    this->set_U(schal.U_in);
    this->set_f(schal.f_in);
    this->set_U_out(schal.U_out);
    this->set_f_out(schal.f_out);
    this->set_on(schal.on);
    this->set_off(schal.off);
    this->set_signal(schal.signal);
    this->set_direction(schal.direction);
    return *this;
}
