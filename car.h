#ifndef CAR_H
#define CAR_H

class car
{
  public:
    car();
    //include typical accessor and mutator methods
  private:
    double mass;
    const double gravity; //initialize to 9.81 in constructor
    double gravitational_acceleration; //start at 9.81, adjust when orientation changes
    double weight;
    
    double distance;
    double velocity;
    double maxspeed;
    double acceleration;
    
    double altitude;
    double orientation; //equal to angle of inclination of track
    
    double throttle; //set to engine acceleration?
    double engine_force;
    double gravitational_force;
    double frictional_force; //calculated using coefficients from track class
    double net_force;
    double power;
    
    double c_rr; //coefficient of rolling resistance
    double c_drag; // coefficient of drag
    double drag_area; //drag area
};

#endif



/*
 Drag Testing

 Goal: Calculating the drag force on the car.
 
 Through the DAQ, we can measure acceleration, velocity, altitude, and orientation in real-time. Using this information, we may be able to conduct an experiment to roughly calculate the drag force acting on the car. We could do so by allowing the car to “free-fall” down the ramp, without any external force from the engine. Then, we can use Newton’s second law to calculate the drag force: ∑F = mgsinθ−μN−Fd. Further, we may attempt to calculate the drag coefficient, which we find from Fd = 0.5 * CρAv2, where C is the drag coefficient.
 
 Expected relationships:
 when orientation changes, gravitational force and altitude change
 when any force changes, net force changes, as well as velocity, acceleration, etc.
 */
