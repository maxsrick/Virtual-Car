#ifndef CAR_H
#define CAR_H

#include "track.h"
#include "motor.h"

class car
{
  public:
      //constructor
    car(track* Track, motor* Motor);

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
    double get_normal_force();
    double get_net_force_x();
    double get_net_force_y();
    double get_power();
    double get_c_rolling_resistance();
    double get_c_drag();
    double get_drag_force();
    double get_drag_area();
    
      //mutator methods
    void set_mass(double m);
    void set_orientation(double o);
    void set_throttle(double t);
    void set_engine_force(double ef);
    void set_power(double p);
    void set_c_rolling_resistance(double cr);
    void set_c_drag(double cd);
    void set_drag_area(double da);
    void set_drag_force(double df);
    void set_velocity(double v);
    void climb(double d);
    void travel(double d);
    
  private:
    double m_mass;
    
    double m_s; //displacement
    double m_v; //velocity
    double m_a; //acceleration
    
    double m_altitude;
    double m_orientation; //angle of inclination of track
    
    double m_throttle;
    double m_engine_force;
    double m_gravitational_force_x;
    double m_gravitational_force_y;
    double m_normal_force;
    double m_net_force_x;
    double m_net_force_y;
    double m_drag_force;
    double m_power;
    
    double m_c_rolling_resistance; //coefficient of rolling resistance
    double m_c_drag; // coefficient of drag
    double m_drag_area; //drag area

    track* m_track;
    motor* m_motor;
};

#endif
