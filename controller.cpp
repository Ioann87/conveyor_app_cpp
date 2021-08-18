#include "controller.h"

Controler::Controler()
{
    on = false;
    off = true;
    dir_f = true;
    dir_b = false;
    run = false;
    stop = false;
    tables.reserve(10);
    schalters.reserve(10);
    motors.reserve(10);
}

void Controler::set_on(bool on) { this->on = on; }
bool Controler::get_on() { return on; }
void Controler::set_off(bool off) { this->off = off; }
bool Controler::get_off() { return off; }
void Controler::set_dir_f(bool dir) { this->dir_f = dir; }
bool Controler::get_dir_f() { return dir_f; }
void Controler::set_dir_b(bool dir) { this->dir_b = dir; }
bool Controler::get_dir_b() { return dir_b; }
void Controler::set_run(bool run) { this->run = run; }
bool Controler::get_run() { return run; }
void Controler::set_stop(bool stop) { this->stop = stop; }
bool Controler::get_stop() { return stop; }

void Controler::set_tables(Table& tab) { tables.push_back(tab); }
std::vector<Table> Controler::get_tables() { return tables; }

void Controler::set_motor(Motor& motor) { motors.push_back(motor); }
std::vector<Motor> Controler::get_motors() { return motors; }

void Controler::set_schalter(Schalter& schal) { schalters.push_back(schal); }
std::vector<Schalter> Controler::get_schalters() { return schalters; }
