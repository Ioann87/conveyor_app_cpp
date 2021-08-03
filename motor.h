#ifndef MOTOR_H
#define MOTOR_H

#include <requirements.h>

class Motor {
protected:
    double U_in; //v
    double f_in; //Hz
    int speed; //rpm
    bool ABC;
    bool on;
    bool off;

public:
    Motor();
    ~Motor() {};
    void set_U(double);
    double get_U();
    void set_f(double);
    double get_f();
    void set_speed(int);
    int get_speed();
    void set_ABC(bool);
    bool get_ABC();
    void set_on(bool);
    bool get_on();
    void set_off(bool);
    bool get_off();

    void start(int, int, bool);
    void move(int, int);
    void stop();
    void choice_side();
    void rotate_forward();
    void rotate_back();
    void statistic();

    Motor& operator=(const Motor&);
};

#endif // MOTOR_H
