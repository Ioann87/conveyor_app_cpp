#include <requirements.h>

#ifndef TABLE_H
#define TABLE_H
#include <schalter.h>
class Table {
private:
    Schalter schal;

public:
    Table() {};
    ~Table() {};
    //    class Motor ;
    //    class Schalter ;

    void set_schalter(Schalter);
    Schalter get_schalter();

    void move_table();
    void move_forward();
    void move_back();

    void statistic();

    void connect_table(bool);
    void take_signal(bool, bool);

    //    friend Motor;
    //    friend Schalter;
};

#endif // TABLE_H
