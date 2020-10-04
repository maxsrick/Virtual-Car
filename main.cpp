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
    vector<double> c1;
    vector<double> c2;
    /*c1.push_back(-228);
    c1.push_back(170);
    c1.push_back(4);
    c2.push_back(183);
    c2.push_back(-132);
    c2.push_back(-1);

    cout << t->angle_between_coordinates(&c2, &c1) << endl;
    cout << t->distance_between_coordinates(&c2, &c1) << endl;*/
    double time = t->time_to_run(c);
    double ms = t->get_total_length()/time;
    cout << "time: " << time << " s"<< endl;
    cout << "average velocity: " << ms << " m/s" << endl;
    cout << "distance: " << t->get_total_length() << endl;
    delete c;
    delete t;
}