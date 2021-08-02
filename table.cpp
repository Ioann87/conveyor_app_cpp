#include <requirements.h>

void Table::statistic()
{
    schal.statistic();

    return;
}

void Table::connect_table(bool connect)
{
    if (connect)
        schal.schalter_on();
    else
        schal.schalter_off();
    return;
}

void Table::take_signal(bool signal, bool direction)
{
    if (signal)
        schal.start_motor(direction);
    else
        schal.stop_motor();

    return;
}

void Table::move_forward()
{
    std::cout << "Table move forward" << std::endl;
    return;
}

void Table::move_back()
{
    std::cout << "Table move back" << std::endl;
    return;
}

void Table::move_table()
{

    return;
}

void Table::set_schalter(Schalter schal) { this->schal = schal; }
Schalter Table::get_schalter() { return schal; }
