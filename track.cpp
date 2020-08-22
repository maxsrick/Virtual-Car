#include "track.h"
#include "car.h"
#include <math.h>
#include <iostream>
using namespace std;
track::track()
{
    c_static_friction = 0.7; //change to typical value for asphalt
    c_dynamic_friction = 0.6; //change to typical value for asphalt
    inclination = 0.0;
    banking = 0.0;
    fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    length = 0.0;
    num_segs = 0;

    segment long_straight;
    long_straight.inclination = 0.4612 * M_PI / 180.0;
    long_straight.length = 584.3;
    segment top_turn;
    top_turn.turnangle = M_PI;
    top_turn.length = 58.996;
    segment other_straight(long_straight);
    other_straight.inclination *= -1.0;
    segment bot_turn(top_turn);
    add_segment(&long_straight);
    //add_segment(&bot_turn);
    //add_segment(&other_straight);
    //add_segment(&top_turn);
}

  //accessor methods
double track::get_c_static_friction() {return c_static_friction;}

double track::get_c_dynamic_friction() {return c_dynamic_friction;}

double track::get_inclination() {return inclination;}

double track::get_banking() {return banking;}

double track::get_fluid_density() {return fluid_density;}

double track::get_length() {return length;}

segment* track::get_segment(int i)
{
    if (i >= 0 && i < segments.size())
    {
        return &(segments[i]);
    }
    return nullptr;
}

int track::get_numsegs() {return num_segs;}

  //mutator methods - note: adjust angles and density for gravity, etc.

void track::set_c_static_friction(double csf) {c_static_friction = csf;}

void track::set_c_dynamic_friction(double cdf) {c_dynamic_friction = cdf;}

void track::set_inclination(double i) {inclination = i;}

void track::set_banking(double b) {banking = b;}

void track::set_fluid_density(double fd) {fluid_density = fd;}

void track::set_length(double l) {length = l;}

void track::add_segment(segment* seg)
{
    segments.push_back(*seg);
    length+=seg->length;
    num_segs++;
}

double track::one_segment(car* Car, segment* Segment)
{
  if (Segment->turnangle==0)
  {
    double angle = Segment->inclination;
    double distance = Segment->length;
    double vi = Car->get_velocity();
    Car->set_orientation(angle);
    double net_force = Car->get_net_force_x();
    double a = net_force / Car->get_mass();
    cout << "net force: " << net_force << endl;
    double vf = sqrt(vi*vi + 2*a*distance);
    double t = 0.0;
    double t1 = (1/a)*(-vi + sqrt(vi*vi + 2*a*distance)); //will need to change
    double t2 = (1/a)*(-vi - sqrt(vi*vi + 2*a*distance));
    if (t1 > 0)
    {
      t = t1;
    }else{
      t = t2;
    }
    Car->travel(distance);
    Car->set_velocity(vf);
    Car->climb(distance*sin(angle));
    return t;
  }else{
    double speed = Car->get_velocity(); //use net force instead to keep friction part of it
    double length = Segment->length;
    double t = length/speed;
    return t;
  }
}

double track::run(car* Car)
{
    double time = 0.0;
    for (int i=0; i<num_segs; i++)
    {
        time += one_segment(Car, get_segment(i));
    }
    return time;
}

void track::reset_segments()
{
    for (int i=0; i<num_segs; i++)
    {
        segments.pop_back();
    }
    num_segs = 0;
}



