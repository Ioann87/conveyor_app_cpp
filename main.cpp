#include <requirements.h>

int main()
{
    Motor motor;
    Schalter schal;
    Table tab;

    schal.set_motor(motor);

    tab.set_schalter(schal);

    tab.statistic();

    tab.connect_table(true);

    tab.statistic();

    tab.take_signal(true, true);

    tab.statistic();

    return 0;
}
