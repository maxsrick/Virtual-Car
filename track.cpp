#include "track.h"

track::track(const car* car)
{
    c_static_friction = 0.7; //change to typical value for asphalt
    c_dynamic_friction = 0.6; //change to typical value for asphalt
    inclination = 0.0;
    banking = 0.0;
    fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    m_car = car;
}

  //accessor methods
double track::get_c_static_friction() {return c_static_friction;}

double track::get_c_dynamic_friction() {return c_dynamic_friction;}

double track::get_inclination() {return inclination;}

double track::get_banking() {return banking;}

double track::get_fluid_density() {return fluid_density;}

  //mutator methods - note: adjust angles and density for gravity, etc.
void track::set_c_static_friction(double csf) {c_static_friction = csf;}

void track::set_c_dynamic_friction(double cdf) {c_dynamic_friction = cdf;}

void track::set_inclination(double i) {inclination = i;}

void track::set_banking(double b) {banking = b;}

void track::set_fluid_density(double fd) {fluid_density = fd;}
