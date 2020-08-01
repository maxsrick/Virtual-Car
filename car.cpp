#include "car.h"
#include "track.h"
#include <math.h>
#include <iostream>
// include typical methods, and look up typical values to assign to them
// contact Caroline or Abdullah for specifics, they have access to the shop and can take measurements

// Note: x-axis is positive to the right
//       y-axis is positive in the downward direction, aka gravity is positive

car::car(track* Track)
{
    mass = 33; // kg
    gravity = 9.81; // m/s^2
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
double car::frictional_force()
{
    if (velocity==0) // is velocity = 0, use coefficient for static friction
        return (m_track->get_c_static_friction())*normal_force;
    else // if velocity is non-zero, use coefficient for dynamic friction
        return (m_track->get_c_dynamic_friction())*normal_force;
}

void car::update_net_force()
{
    net_force_x = frictional_force() + drag_force + gravitational_force_x + engine_force;
    net_force_y = gravitational_force_y + normal_force;
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
void car::set_altitude(double a) {altitude = a;}
void car::set_orientation(double o)
{
    orientation = o;
    gravitational_force_x = mass * gravity * sin(orientation); 
    gravitational_force_y = mass * gravity * cos(orientation);
    normal_force = (-1.0) * gravitational_force_y; // normal force is in the opposite direction
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
