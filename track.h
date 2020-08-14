#ifndef TRACK_H
#define TRACK_H
#include <vector>

//may not need banking

struct segment
{
  double inclination = 0; // radians
  double length = 0;      // meters
  double banking = 0;     // radians
  double turnangle = 0;   // radians
};

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
    void add_segment(segment* seg);
    segment* get_segment(int i);
    int get_numsegs();

    double one_segment(car* Car, segment* Segment);
    double track::run(car* Car);

  private:
      //data members; note down units for all measurements in comments
    double c_static_friction; // co-efficient of static friction
    double c_dynamic_friction; // co-efficient of dynamic friction
    double inclination; // angle of inclination
    double banking; // angle of banking
    double fluid_density; // only used for air in our case
    double length;
    std::vector<segment> segments;
    int num_segs;
};

#endif
