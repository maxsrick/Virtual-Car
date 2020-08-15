#include "track.h"

track::track()
{
    c_static_friction = 0.7; //change to typical value for asphalt
    c_dynamic_friction = 0.6; //change to typical value for asphalt
    inclination = 0.0;
    banking = 0.0;
    fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    length = 0.0;

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
    add_segment(&bot_turn);
    add_segment(&other_straight);
    add_segment(&top_turn);
}

  //accessor methods
double track::get_c_static_friction() {return c_static_friction;}

double track::get_c_dynamic_friction() {return c_dynamic_friction;}

double track::get_inclination() {return inclination;}

double track::get_banking() {return banking;}

double track::get_fluid_density() {return fluid_density;}

double track::get_length() {return length;}

segment* get_segment(int i) 
{
	if (i >= 0 && i < segments.size())
	{
		return &(segments[i]);
	}
}

int get_numsegs() {return numsegs;}

  //mutator methods - note: adjust angles and density for gravity, etc.
}
void track::set_c_static_friction(double csf) {c_static_friction = csf;}

void track::set_c_dynamic_friction(double cdf) {c_dynamic_friction = cdf;}

void track::set_inclination(double i) {inclination = i;}

void track::set_banking(double b) {banking = b;}

void track::set_fluid_density(double fd) {fluid_density = fd;}

void track::set_length(double l) {length = l;}

void track::add_segment(segment* seg) 
{
	segments.push_back(*seg)
	length+=seg.length;
	numsegs++;
}

double track::one_segment(car* Car, segment* Segment)
{
  double time = 0.0;
  if (Segment.turnangle==0)
  {
    double angle = Segment->inclination;
    double length = Segment->length;
    Car->set_orientation(angle);
    double net_force = Car->get_net_force_x();
    double a = net_force / Car->get_mass();
    double vf = sqrt(2*a*distance);
    double t = sqrt(2*distance/a);
    Car->travel(distance);
    Car->set_velocity(vf);
    Car->climb(length*sin(angle));
    return t;
  }else{
    double speed = Car->get_velocity();
    double length = Segment->length;
    double t = length/speed;
    return t;
  }
}

double track::run(car* Car)
{
    double time = 0.0;
    for (int i=0; i<numsegs(); i++)
    {
        time += one_segment(Car, get_segment(i));
    }
    return time;
}




