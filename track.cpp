#include "track.h"
#include "car.h"
#include "physics.h"
#include <math.h>
#include <iostream>
using namespace std;
track::track()
{
    m_c_static_friction = 0.7; //change to typical value for asphalt
    m_c_dynamic_friction = 0.6; //change to typical value for asphalt
    m_fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    m_length = 0.0;
    m_num_segs = 0;

    // straight downward ramp
    segment tester; // need better variable names; why would a new member know what long_straight means? 
//    long_straight.inclination = -1.0 * 0.4612 * M_PI / 180.0; // where has this number come from? that's near zero inclination
    
    tester.inclination = -M_PI/4; // temporary measure; signage scheme must be determined!!! Use negative for downward ramp? causes issues with gravity sign and formula, perhaps invert and use negative angle for incline
    
    tester.length = 584.3;
    add_segment(&tester);
    // turn at top
//    segment top_turn;
//    top_turn.turnangle = M_PI;
//    top_turn.length = 58.996;
//    add_segment(&top_turn);
    // straight upward ramp
//    segment other_straight(long_straight);
//    other_straight.inclination *= -1.0;
//    add_segment(&other_straight);
    // turn at bottom of ramp
//    segment bot_turn(top_turn);
//    add_segment(&bot_turn);
    
}

  //accessor methods
double track::get_c_static_friction() {return m_c_static_friction;}

double track::get_c_dynamic_friction() {return m_c_dynamic_friction;}

double track::get_fluid_density() {return m_fluid_density;}

double track::get_length() {return m_length;}

segment* track::get_segment(int i)
{
    if (i >= 0 && i < m_segments.size())
    {
        return &(m_segments[i]);
    }
    return nullptr;
}

int track::get_numsegs() {return m_num_segs;}

  //mutator methods - note: adjust angles and density for gravity, etc.

void track::set_c_static_friction(double csf) {m_c_static_friction = csf;}

void track::set_c_dynamic_friction(double cdf) {m_c_dynamic_friction = cdf;}

void track::set_fluid_density(double fd) {m_fluid_density = fd;}

void track::set_length(double l) {m_length = l;}

void track::add_segment(segment* seg)
{
    m_segments.push_back(*seg);
    m_length+=seg->length;
    m_num_segs++;
}


// can we put physics formulae into their own methods? that way we can act on data much more cleanly and efficiently
double track::run_one_segment(car* Car, segment* Segment)
{
  if (Segment->turnangle==0)
  {
    double angle = Segment->inclination;
    double distance = Segment->length;
    double vi = Car->get_velocity();
//      cerr << "vi: " << vi << endl;
    Car->set_orientation(angle);
    double net_force = Car->get_net_force_x(); // you can't just label the x component as net force
//      cerr << "net X: " << net_force << endl;
    double a = net_force / Car->get_mass();
//    cerr << "net force: " << net_force << endl;
    double vf = v_uas(vi, a, distance);
//      cerr << "vf: " << vf << endl;
    double t = t_usa(vi, distance, a); // evidently need a more consistent naming scheme
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
    for (int i=0; i<m_num_segs; i++)
    {
        time += run_one_segment(Car, get_segment(i));
    }
    return time;
}

void track::reset_segments()
{
    for (int i=0; i<m_num_segs; i++)
    {
        m_segments.pop_back();
    }
    m_num_segs = 0;
}



