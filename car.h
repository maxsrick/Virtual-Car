#ifndef CAR_H
#define CAR_H

class track;

class car
{
  public:
      //constructor
    car();
    
      //accessor methods
    double get_mass();
    double get_gravity();
    double get_gravitational_acceleration();
    double get_weight();
    double get_distance();
    double get_velocity();
    double get_maxspeed();
    double get_acceleration();
    double get_altitude();
    double get_orientation();
    double get_throttle();
    double get_engine_force();
    double get_gravitational_force();
    double get_frictional_force();
    double get_normal_force();
    double get_net_force();
    double get_power();
    double get_c_rr();
    double get_c_drag();
    double get_drag_area();
    
      //mutator methods
    void set_mass(double m);
    void set_gravity(double g);
    void set_gravitational_acceleration(double ga);
    void set_weight(double w);
    void set_distance(double d);
    void set_velocity(double v);
    void set_maxspeed(double m);
    void set_acceleration(double a);
    void set_altitude(double a);
    void set_orientation(double o);
    void set_throttle(double t);
    void set_engine_force(double ef);
    void set_gravitational_force(double gf);
    void set_frictional_force(double ff);
    void set_normal_force(double nf);
    void set_net_force(double nf);
    void set_power(double p);
    void set_c_rr(double cr);
    void set_c_drag(double cd);
    void set_drag_area(double da);
    
  private:
      //note down units for all measurements in comments
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
    double normal_force;
    double net_force;
    double power;
    
    double c_rr; //coefficient of rolling resistance
    double c_drag; // coefficient of drag
    double drag_area; //drag area
    track* m_track;
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
