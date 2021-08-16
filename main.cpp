#include <controller.h>
#include <conveyor.h>
#include <motor.h>
#include <schalter.h>
#include <table.h>
#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

int main()
{
    Conveyor conveyor;

    conveyor.conveyor_on();
    return 0;
}
