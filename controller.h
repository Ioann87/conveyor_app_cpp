#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <table.h>

#include <iostream>
#include <vector>

class Controler {
private:
    bool on;
    bool off;
    //    Table tab;
    std::vector<Table> tables;

public:
    Controler();
    ~Controler() {};

    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();

    void set_tables(Table);
    std::vector<Table> get_tables();
};

#endif // CONTROLLER_H
