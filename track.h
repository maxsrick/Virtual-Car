#ifndef TRACK_H
#define TRACK_H
#include <vector>

class car;

struct segment
{
  double inclination=0; // radians
  double length=0;      // meters
  double banking=0;     // radians
  double turnangle=0;   // radians, may not need
};

class track
{
  public:
      //constructor
    track();
    
      //accessor methods
    double get_c_static_friction();
    double get_c_dynamic_friction();
    double get_fluid_density();
    double get_total_length();
    
      //mutator methods
    void set_c_static_friction(double csf);
    void set_c_dynamic_friction(double cdf);
    void set_fluid_density(double fd);
    void add_segment(segment* seg);
    segment* get_segment(int i);
    int get_numsegs();

    double time_to_run_one_segment(car* Car, segment* Segment);
    double time_to_run(car* Car);
    void reset_segments();

  private:
      //data members; note down units for all measurements in comments
    double m_c_static_friction; // co-efficient of static friction
    double m_c_dynamic_friction; // co-efficient of dynamic friction
    double m_fluid_density; // only used for air in our case
    double m_total_length;
    std::vector<segment> m_segments;
    int m_num_segs;
};

#endif
