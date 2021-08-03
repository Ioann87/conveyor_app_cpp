#include <requirements.h>

Controler::Controler()
{
    on = false;
    off = true;
    tables.reserve(9);
}

void Controler::set_on(bool on) { this->on = on; }
bool Controler::get_on() { return on; }
void Controler::set_off(bool off) { this->off = off; }
bool Controler::get_off() { return off; }

void Controler::set_tables(Table tab) { tables.push_back(tab); }
std::vector<Table> Controler::get_tables() { return tables; }
