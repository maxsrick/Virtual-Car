#ifndef MOTOR_H
#define MOTOR_H

#include "track.h"

// Motor Data for 60LH351A
const double WINDING = 175;
const double VOLTAGE = 24;
const double NO_LOAD_SPEED = 4200; 
const double SPEED_TO_TORQUE_RATIO = 6.3; 
const double MAX_EFFIENCY = 92; 
const double SPEED_AT_RATED_POWER = 2697/3289;
const double RATED_CURRENT = 31/19;
const double MOTOR_CONSTANT = 17.9;
const double WINDING_RESISTANCE = 0.186;
const double NO_LOAD_CURRENT = 0.24;
const double DAMPING_FACTOR = .2;
const double STATIC_FRICTION = 1;
const double VELOCITY_CONSTANT = 175;
const double TORQUE_CONSTANT = 7.71;
const double ROTOR_INERTIA = 11.8;

class motor
{
  public:
      //constructor
    motor(track* car);

      //accessor methods
    double get_motor_sprocket();
    double get_gear_ratio();
    double get_wheel_sprocket();
    double get_torque();
    double get_force();
    
      //mutator methods
    void set_motor_sprocket(double m);
    void set_gear_ratio(double o);
    void set_wheel_sprocket(double t);
    void set_torque(double ef);
    void set_force(double p);
    
  private:
      // Related objects
    track* m_track;

      // Given constants
    double m_winding;
    double m_voltage;
    double m_no_load_speed; 
    double m_speed_to_torque_slope; 
    double m_max_efficiency; 
    double m_speed_at_rated_power;
    double m_rated_current;
    double m_motor_constant;
    double m_winding_resistance;
    double m_no_load_current;
    double m_damping_factor;
    double m_static_friction;
    double m_velocity_constant;
    double m_torque_constant;
    double m_rotor_inertia;
    
      // Calculated motor specs
    double m_motor_sprocket; 
    double m_gear_ratio;
    double m_wheel_sprocket; 
    double m_torque;
    double m_force; 
};

#endif
