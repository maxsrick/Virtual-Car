#include <math.h>

#include "motor.h"
#include "track.h"

#include "./throttle/rampingCopy.h"

#include <string>

#include <chrono>
#include <sys/time.h>
#include <ctime>

using namespace std;

motor::motor(track* Track) // Need to add parameter to choose rampingType
: m_track(Track), m_winding(WINDING), m_voltage(VOLTAGE), m_no_load_speed(NO_LOAD_SPEED), m_speed_to_torque_slope(SPEED_TO_TORQUE_RATIO),
  m_max_efficiency(MAX_EFFIENCY), m_speed_at_rated_power(SPEED_AT_RATED_POWER), m_rated_current(RATED_CURRENT), 
  m_motor_constant(MOTOR_CONSTANT), m_winding_resistance(WINDING_RESISTANCE), m_no_load_current(NO_LOAD_CURRENT),
  m_damping_factor(DAMPING_FACTOR), m_static_friction(STATIC_FRICTION), m_velocity_constant(VELOCITY_CONSTANT),
  m_torque_constant(TORQUE_CONSTANT), m_rotor_inertia(ROTOR_INERTIA)
{
    // TODO: Add in a way to choose which type of ramping function the user wants 
    rampingType = "Linear";
    if (rampingType == "Linear")
    {
        m_ramp = new Linear;
    }
    // TODO: possibly set calculated motor specs here by calling functions
}

unsigned long motor::get_time()
{
   //gets current time (since start of program)
   time_t now = time(nullptr);
   //converts from s ->ms
   now *= 1000;
   return now;   
}

double motor::get_voltage(int throttle) //throttle will be taken from UI (IDK how that will be implemented)
{
    int speed = m_ramp->newSpd(throttle, getTime());
    double voltage = (speed * 24)/255 ; //converts speed into a percentage of battery
    return voltage;
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

int main()
{}