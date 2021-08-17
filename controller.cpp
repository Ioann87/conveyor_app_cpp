#include "controller.h"

Controler::Controler()
{
    on = false;
    off = true;
    tables.reserve(10);
    schalters.reserve(10);
    motors.reserve(10);
}

void Controler::set_on(bool on) { this->on = on; }
bool Controler::get_on() { return on; }
void Controler::set_off(bool off) { this->off = off; }
bool Controler::get_off() { return off; }

void Controler::set_tables(Table& tab) { tables.push_back(tab); }
std::vector<Table> Controler::get_tables() { return tables; }

void Controler::set_motor(Motor& motor) { motors.push_back(motor); }
std::vector<Motor> Controler::get_motors() { return motors; }

void Controler::set_schalter(Schalter& schal) { schalters.push_back(schal); }
std::vector<Schalter> Controler::get_schalters() { return schalters; }
