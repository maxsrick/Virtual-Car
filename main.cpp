#include "car.h"
#include "track.h"
#include <iostream>
#include <math.h>

using namespace std;

//const double estimate_weight = 73.0; //pounds oops; shouldn't be in main

double down_ramp(car* Car, track* Track) // if not required, MUST be removed; just clogs up code
{
    // changing this sign made no difference?? are axes set up properly?
    Car->set_velocity(0.1); //so we use dynamic friction
    // this method isn't called at all
    
    // how is the track giving an inclination if the each segment has its own angle???
//    double angle = Track->get_inclination();
    double angle = M_PI/4; // 45 degree ramp for simulation
    
    
    double distance = Track->get_length();
    Car->set_orientation(angle);
    //cout << Car->get_gravitational_force_x() << endl;
    double net_force = Car->get_net_force_x();
    //cout << Car->get_frictional_force() << endl;
    
    // why are we calculating and coutting stuff in the main???
    
    cout << "net: " << net_force << endl;
    double a = net_force / Car->get_mass();
    cout << "a: " << a << endl;
    double vf = sqrt(2*a*distance);
    cout << "vf: " << vf << endl;
    double t = sqrt(2*distance/a);
    Car->travel(distance);
    Car->set_velocity(vf);
    return t;
} //delete this function later

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
