#include "track.h"
#include "car.h"
#include "physics.h"
#include <math.h>
using namespace std;

track::track()
{
    m_c_static_friction = 0.7; //change to typical value for asphalt
    m_c_dynamic_friction = 0.6; //change to typical value for asphalt
    m_fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    m_total_length = 0.0;
    m_num_segs = 0;

    //new updated track
    segment top_turn;
    top_turn.turnangle = M_PI;
    top_turn.length = 147.836;

    segment long_downhill;
    long_downhill.length = 580.762;
    long_downhill.inclination = -0.00998 * M_PI / 180.0;

    segment bot_turn;
    bot_turn.turnangle = M_PI;
    bot_turn.length = 90.785;

    segment first_uphill;
    first_uphill.length = 291.049;
    first_uphill.inclination = 0;

    segment second_uphill;
    second_uphill.length = 306.149;
    second_uphill.inclination = 0.0165 * M_PI / 180.0;

    add_segment(&top_turn);
    add_segment(&long_downhill);
    add_segment(&bot_turn);
    add_segment(&first_uphill);
    add_segment(&second_uphill);
}

  //accessor methods
double track::get_c_static_friction() {return m_c_static_friction;}
double track::get_c_dynamic_friction() {return m_c_dynamic_friction;}
double track::get_fluid_density() {return m_fluid_density;}
double track::get_total_length() {return m_total_length;}

segment* track::get_segment(int i)
{
    if (i >= 0 && i < m_segments.size())
        return &(m_segments[i]);
    
    return nullptr;
}

int track::get_numsegs() {return m_num_segs;}

  //mutator methods - note: adjust angles and density for gravity, etc.

void track::set_c_static_friction(double csf) {m_c_static_friction = csf;}
void track::set_c_dynamic_friction(double cdf) {m_c_dynamic_friction = cdf;}
void track::set_fluid_density(double fd) {m_fluid_density = fd;}

void track::add_segment(segment* seg)
{
    m_segments.push_back(*seg);
    m_total_length+=seg->length;
    m_num_segs++;
}

double track::time_to_run_one_segment(car* Car, segment* Segment)
{
  if (Segment->turnangle==0) // if the segment is a straight road/ramp
  {
    double incline_angle = Segment->inclination;
    double s = Segment->length;
    double u = Car->get_velocity();
    Car->set_orientation(incline_angle);
    double net_force_x = Car->get_net_force_x();
    double a = net_force_x / Car->get_mass();
    double v = v_uas(u, a, s);
    double t = t_usa(u, s, a);
    Car->travel(s);
    Car->set_velocity(v);
    Car->climb(s*sin(incline_angle));
    return t;
  } else { // if the segment is a turn
    double v = Car->get_velocity();
    double s = Segment->length;
    double t = s/v;
    return t;
  }
}

double track::time_to_run(car* Car)
{
    double time = 0.0;
    for (int i=0; i<m_num_segs; i++)
    {
        time += time_to_run_one_segment(Car, get_segment(i));
    }
    return time;
}

void track::reset_segments()
{
    for (int i=0; i<m_num_segs; i++)
    {
        m_segments.pop_back();
    }
    m_num_segs = 0;
}



