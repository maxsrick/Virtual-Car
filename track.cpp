#include "track.h"
#include "car.h"
#include "physics.h"
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

track::track()
{
    m_c_static_friction = 0.7; //change to typical value for asphalt
    m_c_dynamic_friction = 0.6; //change to typical value for asphalt
    m_fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
    m_total_length = 0.0;

    ifstream raw_data("sonoma.csv"); //reading in all the coordinates

    while(true)
    {
        string s;
        raw_data >> s;
        if(s=="") break;
        string delimiter = ",";
        vector<double> temp;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            temp.push_back(stod(token));
            s.erase(0, pos + delimiter.length());
        }
        temp.push_back(stod(s));

        m_coordinates.push_back(temp);
        
        if(raw_data.eof()) break;
    }

    for (int i=0; i < m_coordinates.size()-1; i++) //calculating total length
    {
        double d = distance_between_coordinates(&m_coordinates[i], &m_coordinates[i+1]);
        m_total_length += d;
    }
    
}

  //accessor methods
double track::get_c_static_friction() {return m_c_static_friction;}
double track::get_c_dynamic_friction() {return m_c_dynamic_friction;}
double track::get_fluid_density() {return m_fluid_density;}
double track::get_total_length() {return m_total_length;}

  //mutator methods - note: adjust angles and density for gravity, etc.

void track::set_c_static_friction(double csf) {m_c_static_friction = csf;}
void track::set_c_dynamic_friction(double cdf) {m_c_dynamic_friction = cdf;}
void track::set_fluid_density(double fd) {m_fluid_density = fd;}

double track::time_to_run(car* Car)
{
    double time = 0.0;
    for (int i=0; i < m_coordinates.size()-1; i++) //go over each coordinate
    {
        double s = distance_between_coordinates(&m_coordinates[i], &m_coordinates[i+1]);
        double incline_angle = angle_between_coordinates(&m_coordinates[i], &m_coordinates[i+1]);
        Car->set_orientation(incline_angle);
        double u = Car->get_velocity();
        double old_nf = Car->get_net_force_x(); //get net force acting on car at current coordinate
        // TODO: remove this function, change method of running
        Car->set_engine_force(-1.0*old_nf); //set engine force to stay constant velocity
        double net_force_x = Car->get_net_force_x(); //will always be zero in this case
        double a = net_force_x / Car->get_mass(); 
        double v = v_uas(u, a, s); 
        double t = t_usa(u, s, a);
        Car->travel(s); //set car's new distance traveled, velocity, altitude
        Car->set_velocity(v);
        Car->climb(s*sin(incline_angle));
        // TODO: remove this
        Car->set_engine_force(0); //reset engine force 
        time += t;
    }
    return time;
}

double track::distance_between_coordinates(vector<double>* c1, vector<double>* c2)
{
    double x1 = (*c1)[0];
    double y1 = (*c1)[1];
    double z1 = (*c1)[2];

    double x2 = (*c2)[0];
    double y2 = (*c2)[1];
    double z2 = (*c2)[2];

    double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y2) + (z2-z1)*(z2-z1));
    return dist;
}

double track::angle_between_coordinates(vector<double>* c1, vector<double>* c2)
{
    double delta_z = (*c1)[2] - (*c2)[2];
    double dist = distance_between_coordinates(c1, c2);
    double angle = (-1.0)*asin(delta_z/dist); //retaining sign conventions
    return angle;
}


