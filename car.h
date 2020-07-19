#ifndef CAR_H
#define CAR_H

#include "track.h"

class car
{
  public:
      //constructor
    car(track* Track);

      //auxillary functions
    double frictional_force();
    void update_net_force();

      //accessor methods
    double get_mass();
    double get_distance();
    double get_velocity();
    double get_maxspeed();
    double get_acceleration();
    double get_altitude();
    double get_orientation();
    double get_throttle();
    double get_engine_force();
    double get_gravitational_force_x();
    double get_gravitational_force_y();
    double get_frictional_force();
    double get_normal_force();
    double get_net_force_x();
    double get_net_force_y();
    double get_power();
    double get_c_rr();
    double get_c_drag();
    double get_drag_force();
    double get_drag_area();
    
      //mutator methods
    void set_mass(double m);
    void set_altitude(double a);
    void set_orientation(double o);
    void set_throttle(double t);
    void set_engine_force(double ef);
    void set_power(double p);
    void set_c_rr(double cr);
    void set_c_drag(double cd);
    void set_drag_area(double da);
    void set_drag_force(double df);
    void set_velocity(double v);
    void travel(double d);
    
  private:
      //note down units for all measurements in comments
    double mass;
    double gravity; //initialize to 9.81 in constructor
    
    double distance;
    double velocity;
    double maxspeed;
    double acceleration;
    
    double altitude;
    double orientation; //equal to angle of inclination of track
    
    double throttle; //set to engine acceleration?
    double engine_force;
    double gravitational_force_x;
    double gravitational_force_y;
    double normal_force;
    double net_force_x;
    double net_force_y;
    double drag_force;
    double power;
    
    double c_rr; //coefficient of rolling resistance
    double c_drag; // coefficient of drag
    double drag_area; //drag area
    track* m_track;
};

#endif
