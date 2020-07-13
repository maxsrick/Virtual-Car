#include "car.h"
#include "track.h"
#include <iostream>
#include <math.h>

using namespace std;

const double estimate_weight = 73.0; //pounds oops

double down_ramp(car* Car, track* Track)
{
    double angle = Track->get_inclination();
    double distance = Track->get_length();
    Car->set_orientation(angle);
    double net_force = Car->get_net_force();
    double a = net_force / Car->get_mass();
    double vf = sqrt(2*a*distance);
    double t = sqrt(2*distance/a);
    Car->travel(distance);
    Car->set_velocity(vf);
    return t;
}

int main()
{
    track* t = new track;
    t->set_inclination(30);
    t->set_length(100);
    car* c = new car(t);
    c->set_mass(estimate_weight);
    double seconds = down_ramp(c, t);
    cout << seconds << endl;
}
