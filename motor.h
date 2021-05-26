#ifndef MOTOR_H
#define MOTOR_H

#include <string>

// Motor Data for 60LH351A
const double WINDING = 175*0.10472;
const double VOLTAGE = 24;
const double NO_LOAD_SPEED = 4200; 
const double SPEED_TO_TORQUE_RATIO = 6.3; 
const double MAX_EFFIENCY = 92; 
const double SPEED_AT_RATED_POWER = 3289;
const double RATED_CURRENT = 19;
const double MOTOR_CONSTANT = 17.9;
const double WINDING_RESISTANCE = 0.186;
const double NO_LOAD_CURRENT = 0.24;
const double DAMPING_FACTOR = .2;
const double STATIC_FRICTION = 1;
const double VELOCITY_CONSTANT = 175;
const double TORQUE_CONSTANT = 7.71*0.00706;
const double ROTOR_INERTIA = 11.8;
const double INDUCTANCE = 0.00016;
const double GEAR_RATIO = 9;
const double MOMENT_INERTIA = 35*pow(0.1, 2); // TODO: check numeric values
const double RADIUS = 10; // Need to calculate or find out for torque -> force calculation
class Ramping;

class motor
{
  public:
    // Constructor
    motor();

    // Simulation functions
    unsigned long get_time();
    double get_voltage(int throttle);
    double rungeKuttaRPM(double timeStart, double timeEnd, double step, double voltage);
    double get_force(); 
    double hold15MPH(double speed);

  private:
    // Related objects
    Ramping* m_ramp;

    string rampingType;

    // Changing motor simulated values
    double m_rpm;
    double m_torque;
    double m_force;

      // Constant motor specs
    double m_motor_sprocket; 
    double m_gear_ratio;
    double m_wheel_sprocket; 
};

#endif
