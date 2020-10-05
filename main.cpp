#include "car.h"
#include "track.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    track* t = new track; //put this all into a default constructor
    car* c = new car(t);
    c->set_mass(33.11); //73 pound estimate weight
    c->set_velocity(6.7); //15 mph
    double time = t->time_to_run(c);
    double ms = t->get_total_length()/time;
    cout << "time: " << time << " s"<< endl;
    cout << "average velocity: " << ms << " m/s" << endl;
    cout << "distance: " << t->get_total_length() << endl;
    delete c;
    delete t;
}