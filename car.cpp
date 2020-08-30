#include "car.h"
#include "track.h"
#include <math.h>
#include <iostream>

using namespace std;
// include typical methods, and look up typical values to assign to them
// contact Caroline or Abdullah for specifics, they have access to the shop and can take measurements

car::car(track* Track)
{
    // perhaps the m_ scheme would be helpful
    mass = 500; // kg
    gravity = -9.81; //m/s^2
    distance = 0; // m
    velocity = 0; // m/s
    acceleration = 0; // m/s^2
    altitude = 0; // m above starting point?
    orientation = 90; // degrees
    gravitational_force_x = 0;
    gravitational_force_y = gravity * mass;
    throttle = 0; // m/s^2?
    engine_force = 0; // N
    net_force_x = 0; // N
    net_force_y = 0; // N
    power = 0; // W or HP?
    c_rr = 0; // unitless
    c_drag = 0; // unitless
    drag_force =0 ; // N
    drag_area = 0; // m^2
    m_track = Track;
}
//auxillary functions
double car::frictional_force() // sign conventions are absolutely fucked, we need to create documentation to describe what sign convention we plan on using (which we probably should have decided earlier)
{
    if (velocity==0)
        return (-1.0 * m_track->get_c_static_friction())*normal_force; // opposes other forces
    else if (velocity > 0)
        return (-1.0 * m_track->get_c_dynamic_friction())*normal_force;
    else
        return m_track->get_c_dynamic_friction()*normal_force;
}

void car::update_net_force()
{
//    std::cerr << "friction: " << frictional_force() << " gravity: " << gravitational_force_x << std::endl;
    // signs now fixed
    net_force_x = frictional_force() + drag_force + gravitational_force_x + engine_force;
//    cerr << "net X: " << net_force_x << endl;
    net_force_y = gravitational_force_y + normal_force;
//    cerr << "net Y: " << net_force_y << endl;
}

  // accessor methods
double car::get_mass() {return mass;}
double car::get_distance() {return distance;}
double car::get_velocity() {return velocity;}
double car::get_acceleration() {return acceleration;}
double car::get_altitude() {return altitude;}
double car::get_orientation() {return orientation;}
double car::get_throttle() {return throttle;}
double car::get_engine_force() {return engine_force;}
double car::get_gravitational_force_x() {return gravitational_force_x;}
double car::get_gravitational_force_y() {return gravitational_force_y;}
double car::get_frictional_force() {return frictional_force();}
double car::get_normal_force() {return normal_force;}
double car::get_net_force_x() {return net_force_x;}
double car::get_net_force_y() {return net_force_y;}
double car::get_power() {return power;}
double car::get_c_rr() {return c_rr;}
double car::get_c_drag() {return c_drag;}
double car::get_drag_area() {return drag_area;}
double car::get_drag_force() {return drag_force;}

  // mutator methods
void car::set_mass(double m) {mass = m;}
void car::climb(double d) {altitude += d;}
void car::set_orientation(double o)
{
    orientation = o;
//    cerr << "o: " << o << endl;
    gravitational_force_x = mass * gravity * sin(orientation);
//    std :: cerr << mass << " * " << gravity << " * " << sin(orientation) << std::endl;
//    std::cerr << "grav_x: " << gravitational_force_x << std::endl;
    gravitational_force_y = mass * gravity * cos(orientation);
    normal_force = (-1.0) * gravitational_force_y;
    update_net_force();
}
void car::set_throttle(double t) {throttle = t;}
void car::set_engine_force(double ef) {engine_force = ef;}
void car::set_power(double p) {power = p;}
void car::set_c_rr(double cr) {c_rr = cr;}
void car::set_c_drag(double cd) {c_drag = cd;}
void car::set_drag_area(double da) {drag_area = da;}
void car::set_drag_force(double df) {drag_force = df;}
void car::travel(double d) {distance += d;}
void car::set_velocity(double v) {velocity = v;}
