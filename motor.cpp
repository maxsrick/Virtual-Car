#include <math.h>
#include <string>
#include <iostream>
#include <chrono>
#include <sys/time.h>
#include <ctime>

#include "motor.h"
#include "track.h"
#include "./throttle/rampingCopy.h"

using namespace std;

motor::motor(track* Track) // Need to add parameter to choose rampingType
: m_track(Track)
{
    // TODO: Add in a way to choose which type of ramping function the user wants 
    rampingType = "Linear";
    if (rampingType == "Linear")
    {
        m_ramp = nullptr;
        m_rpm = 0;
        m_torque = 0;
        m_force = 0;
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
    int speed = m_ramp->newSpd(throttle, get_time());
    double voltage = (speed * 24)/255 ; //converts speed into a percentage of battery
    return voltage;
}

// Automatically updates m_rpm
double motor::rungeKuttaRPM(double timeStart, double timeEnd, double step, double voltage)
{
    // Find number of iterations
    int numIter = (timeEnd - timeStart)/step;
    double angularVelocity = m_rpm*0.10472;

    for (int i = 0; i < numIter; i++)
    {
        // Update values
        double deltaV = voltage - angularVelocity/(WINDING);
        double current = deltaV/sqrt(pow(WINDING_RESISTANCE,2) + pow(angularVelocity*INDUCTANCE, 2));
        double m_torque = TORQUE_CONSTANT*current*GEAR_RATIO;
        double acceleration = m_torque/MOMENT_INERTIA;

        // Calculate c1, c2, c3, c4
        double c1 = step*acceleration*1;
        double c2 = step*acceleration*(1+c1/2);
        double c3 = step*acceleration*(1+c2/2);
        double c4 = step*acceleration*(1+c3);
            
        // Calculate instanteous rpm 
        angularVelocity += c1/6 + c2/3 + c3/3 + c4/6;
    }

    // Set rpm for next iteration
    m_rpm = angularVelocity/0.10472;

    return m_rpm;
}

double motor::get_force() 
{
    // Compute and return motor output force
    m_force = m_torque/RADIUS;
    return m_force;
}

int main()
{
    // track* Track = nullptr;
    // motor vroom = new motor(Track);

    cout << map(7, 3, 13, 0, 10) << endl;
}