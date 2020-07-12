#include "car.h"
#include "track.h"
#include <math.h>
// include typical methods, and look up typical values to assign to them
// contact Caroline or Abdullah for specifics, they have access to the shop and can take measurements

car::car(const track* track)
{
    mass = 500; // kg
    gravity = 9.81; // m/s^2
    gravitational_acceleration = 9.81; // m/s^2
    weight = mass * gravity; // N
    distance = 0; // m
    velocity = 0; // m/s
    acceleration = 0; // m/s^2
    altitude = 0; // m above starting point?
    orientation = 90; // degrees on flat road
    throttle = 0; // m/s^2?
    engine_force = 0; // N
    gravitational_force = weight * sin(orientation); // N
    normal_force = gravitational_force * -1; // N; need to figure out direction scheme, also not necessarily true, but we'll cross that bridge when we come to it
    net_force = 0; // N
    power = 0; // W or HP?
    c_rr = 0; // unitless
    c_drag = 0; // unitless
    drag_area = 0; // m^2
    m_track = track;
}
double frictional_force()
{
    if (speed==0)
        return m_track->get_c_static_friction(); 
    else 
        return m_track->get_c_dynamic_friction();
}

  // accessor methods
double get_mass() {return mass;}
double get_gravity() {return gravity;}
double get_gravitational_acceleration() {return gravitational_acceleration;}
double get_distance() {return distance;}
double get_velocity() {return velocity;}
double get_acceleration() {return acceleration;}
double get_altitude() {return altitude;}
double get_orientation() {return orientation;}
double get_throttle() {return throttle;}
double get_engine_force() {return engine_force;}
double get_gravitational_force() {return gravitational_force;}
double get_frictional_force() {return frictional_force;}
double get_normal_force() {return normal_force}
double get_net_force() {return net_force;}
double get_power() {return power;}
double get_c_rr() {return c_rr;}
double get_c_drag() {return c_drag;}
double get_drag_area() {return drag_area;}

  // mutator methods
void set_mass(double m) {mass = m;}
void set_altitude(double a) {altitude = a;}
void set_orientation(double o)
{
    orientation = o;
    gravitational_acceleration = gravity * sin(orientation);
    net_force -= gravitational_force;
    net_force -= normal_force;
    gravitational_force = mass * gravitational_acceleration;
    normal_force = gravitational_force * -1;
    net_force += gravitational_force;
    net_force += normal_force;
}
void set_throttle(double t) {throttle = t;}
void set_engine_force(double ef) {engine_force = ef;}
void set_frictional_force(double ff)
{
    net_force -= frictional_force;
    frictional_force = ff;
    net_force += frictional_force;
}
void set_net_force(double nf) {net_force = nf;}
void set_power(double p) {power = p;}
void set_c_rr(double cr) {c_rr = cr;}
void set_c_drag(double cd) {c_drag = cd;}
void set_drag_area(double da) {drag_area = da;}
void travel(double d) {distance+=d;}

//we might need weight and then an x and y of gravitational
// we might want to find a way to condense this, maybe into essential data and auxilary data, because it's quite clogged up rn
// can you work on the eqautions and relationships we need and get back to me with the necessary data values: ie we only need mass and gravity, storing weight separately is unnecessary, we can just calculate it upon returning it.
