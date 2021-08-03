#include <requirements.h>

#ifndef SCHALTER_H
#define SCHALTER_H

#include <motor.h>

class Schalter {

private:
    bool on;
    bool off;
    int U_in;
    int f_in;

    int U_out;
    int f_out;

    bool signal;

    bool direction;

    Motor motor;

public:
    Schalter();
    ~Schalter() {};

    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();

    void set_U(int);
    int get_U();
    void set_f(int);
    int get_f();

    void set_U_out(int);
    int get_U_out();
    void set_f_out(int);
    int get_f_out();

    void set_signal(bool);
    bool get_signal();
    void set_direction(bool);
    bool get_direction();

    void set_motor(Motor);
    Motor get_motor();

    //methods for schalter
    void statistic();
    void schalter_on();
    void schalter_off();
    void start_motor(bool);
    void stop_motor();

    Schalter& operator=(const Schalter&);
};

#endif // SCHALTER_H
