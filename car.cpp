#include "car.h"

// include typical methods, and look up typical values to assign to them
// contact Caroline or Abdullah for specifics, they have access to the shop and can take measurements

// WE NEED TRIG LIBRARIES FOR ORIENTATION, VERY IMPORTANT!!!


car::car()
{
    mass = 500; // kg
    gravity = 9.81; // m/s^2
    gravitational_acceleration = 9.81; // m/s^2
    weight = mass * gravity; // N
    distance = 0; // m
    velocity = 0; // m/s
    maxspeed 24; // 24 km/hr = 15 mph
    acceleration = 0; // m/s^2
    altitude = 0; // m above starting point?
    orientation = 90; // degrees on flat road
    throttle = 0; // m/s^2?
    engine_force = 0; // N
    gravitational_force = weight * sin(orientation); // N; NEED TRIG LIBRARY!
    frictional_force = 0; // N; needs to be updated by track class based on surface
    normal_force = gravitational_force * -1; // N; need to figure out direction scheme, also not necessarily true, but we'll cross that bridge when we come to it
    net_force = 0; // N
    power = 0; // W or HP?
    c_rr = 0; // unitless
    c_drag = 0; // unitless
    drag_area = 0; // m^2
}

  // accessor methods
double get_mass() {return mass;}
double get_gravity() {return gravity;}
double get_gravitational_acceleration() {return gravitational_acceleration;}
double get_weight() {return weight;}
double get_distance() {return distance;}
double get_velocity() {return velocity;}
double get_maxspeed() {return maxspeed;}
double get_acceleration() {return acceleration;}
double get_altitude() {return altitude;}
double get_orientation() {return orientation;}
double get_throttle() {return throttle;}
double get_engine_force() {return engine_force;}
double get_gravitational_force() {return gravitational_force;}
double get_frictional_force() {return frictional_force;}
double get_net_force() {return net_force;}
double get_power() {return power;}
double get_c_rr() {return c_rr;}
double get_c_drag() {return c_drag;}
double get_drag_area() {return drag_area;}

  // mutator methods
void set_mass(double m) {mass = m;}
void set_gravity(double g) {gravity = g;}
void set_gravitational_acceleration(double ga) {gravitational_acceleration = ga;}
void set_weight(double w) {weight = w;}
void set_distance(double d) {distance = d;}
void set_velocity(double v) {velocity = v;}
void set_maxspeed(double m) {maxspeed = m;}
void set_acceleration(double a) {acceleration = a;}
void set_altitude(double a) {altitude = a;}
void set_orientation(double o)
{
    orientation = o;
    gravitational_acceleration = gravity * sin(orientation);
    gravitational_force = mass * gravitational_acceleration;
    normal_force = gravitational_force * -1;
}
void set_throttle(double t) {throttle = t;}
void set_engine_force(double ef) {engine_force = ef;}
void set_gravitational_force(double gf) {gravitational_force = gf;}
void set_frictional_force(double ff) {frictional_force = ff;}
void set_net_force(double nf) {net_force = nf;}
void set_power(double p) {power = p;}
void set_c_rr(double cr) {c_rr = cr;}
void set_c_drag(double cd) {c_drag = cd;}
void set_drag_area(double da) {drag_area = da;}


// we might want to find a way to condense this, maybe into essential data and auxilary data, because it's quite clogged up rn
// can you work on the eqautions and relationships we need and get back to me with the necessary data values: ie we only need mass and gravity, storing weight separately is unnecessary, we can just calculate it upon returning it.
