#include <math.h>

#include "motor.h"
#include "track.h"

using namespace std;

motor::motor(track* Track)
: m_track(Track), m_winding(WINDING), m_voltage(VOLTAGE), m_no_load_speed(NO_LOAD_SPEED), m_speed_to_torque_slope(SPEED_TO_TORQUE_RATIO),
  m_max_efficiency(MAX_EFFIENCY), m_speed_at_rated_power(SPEED_AT_RATED_POWER), m_rated_current(RATED_CURRENT), 
  m_motor_constant(MOTOR_CONSTANT), m_winding_resistance(WINDING_RESISTANCE), m_no_load_current(NO_LOAD_CURRENT),
  m_damping_factor(DAMPING_FACTOR), m_static_friction(STATIC_FRICTION), m_velocity_constant(VELOCITY_CONSTANT),
  m_torque_constant(TORQUE_CONSTANT), m_rotor_inertia(ROTOR_INERTIA)
{
    // TODO: possibly set calculated motor specs here by calling functions
}

  //accessor methods
double motor::get_motor_sprocket() {return m_motor_sprocket;}
double motor::get_gear_ratio() {return m_gear_ratio;}
double motor::get_wheel_sprocket() {return m_wheel_sprocket;}
double motor::get_torque() {return m_torque;}
double motor::get_force() {return m_force;}
    
  //mutator methods
void motor::set_motor_sprocket(double m)
{
    // TODO: implement
}

void motor::set_gear_ratio(double o)
{
    // TODO: implement
}

void motor::set_wheel_sprocket(double t)
{
    // TODO: implement
}

void motor::set_torque(double ef)
{
    // TODO: implement
}

void motor::set_force(double p)
{
    // TODO: implement
}