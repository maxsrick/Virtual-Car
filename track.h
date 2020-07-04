#idndef TRACK_H
#def TRACK_H

#inlcude "car.h"

class track
{
  public:
      //constructor
    track();
    
      //accessor methods
    double get_c_static_friction();
    double get_c_dynamic_friction();
    double get_inclination();
    double get_banking();
    double get_fluid_density();
    
      //mutator methods
    void set_c_static_friction(double csf);
    void set_c_dynamic_friction(double cdf);
    void set_inclination(double i);
    void set_banking(double b);
    void set_fluid_density(double fd);
    
  private:
      //data members; note down units for all measurements in comments
    double c_static_friction; // co-efficient of static friction
    double c_dynamic_friction; // co-efficient of dynamic friction
    double inclination; // angle of inclination
    double banking; // angle of banking
    double fluid_density; // only used for air in our case
    car* shadow; // is this the best way to link the two classes?
};

#endif








/*
 Drag Testing

 Goal: Calculating the drag force on the car.
 
 Through the DAQ, we can measure acceleration, velocity, altitude, and orientation in real-time. Using this information, we may be able to conduct an experiment to roughly calculate the drag force acting on the car. We could do so by allowing the car to “free-fall” down the ramp, without any external force from the engine. Then, we can use Newton’s second law to calculate the drag force: ∑F = mgsinθ−μN−Fd. Further, we may attempt to calculate the drag coefficient, which we find from Fd = 0.5 * CρAv2, where C is the drag coefficient.
 */
