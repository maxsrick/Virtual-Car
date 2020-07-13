#ifndef TRACK_H
#define TRACK_H

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
    double get_length();
    
      //mutator methods
    void set_c_static_friction(double csf);
    void set_c_dynamic_friction(double cdf);
    void set_inclination(double i);
    void set_banking(double b);
    void set_fluid_density(double fd);
    void set_length(double l);
    
  private:
      //data members; note down units for all measurements in comments
    double c_static_friction; // co-efficient of static friction
    double c_dynamic_friction; // co-efficient of dynamic friction
    double inclination; // angle of inclination
    double banking; // angle of banking
    double fluid_density; // only used for air in our case
    double length;
};

#endif
