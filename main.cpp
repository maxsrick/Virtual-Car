#include "car.h"
#include "track.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    track* t = new track; //put this all into a default constructor
    car* c = new car(t);
    c->set_mass(20);
    c->set_velocity(0.2);
    double time = t->run(c);
    cout << "time: " << time << endl;
    delete c;
    delete t;
}
