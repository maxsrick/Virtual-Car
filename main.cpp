#include "car.h"
#include "track.h"
#include <iostream>
#include <math.h>

using namespace std;

const double estimate_weight = 73.0; //pounds oops

double down_ramp(car* Car, track* Track)
{
    Car->set_velocity(0.1); //so we use dynamic friction
    double angle = Track->get_inclination();
    double distance = Track->get_length();
    Car->set_orientation(angle);
    cout << Car->get_gravitational_force_x() << endl;
    double net_force = Car->get_net_force_x();
    //cout << Car->get_frictional_force() << endl;
    cout << "net: " << net_force << endl;
    double a = net_force / Car->get_mass();
    cout << "a: " << a << endl;
    double vf = sqrt(2*a*distance);
    cout << "vf: " << vf << endl;
    double t = sqrt(2*distance/a);
    Car->travel(distance);
    Car->set_velocity(vf);
    return t;
}

double one_segment(car* Car, segment* Segment)
{
    double time = 0.0;
    if (Segment.turnangle==0)
    {
        //ramp
    }
    else
    {
        //turn physics
    }
    return time;
}

double run(car* Car, track* Track)
{
    double time = 0.0;
    for (int i=0; i<Track.numsegs(); i++)
    {
        time += one_segment(Car, get_segment(i));
    }
    return time;
}

int main()
{
    segment long_straight;
    long_straight.inclination = 0.4612 * M_PI / 180.0;
    long_straight.length = 584.3;
    segment top_turn;
    top_turn.turnangle = M_PI;
    top_turn.length = 58.996;
    segment other_straight(long_straight);
    segment bot_turn(top_turn);

    track* t = new track;
    t.add_segment(&long_straight);
    t.add_segment(&bot_turn);
    t.add_segment(&other_straight);
    t.add_segment(&top_turn);

    car* c = new car(t);
    c->set_mass(20);
    delete c;
    delete t;
}
