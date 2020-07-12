#include "car.h"
#include "track.h"
#include <math.h>

const double estimate_weight = 73.0;

double down_ramp(car* Car, track* Track)
{
	double angle = Track.get_inclination();
	double distance = Track.get_length();
	Car.set_inclination(angle);
	double net_force = Car.get_net_force(); //maybe will need to change
	double a = net_force / Car.get_mass();
	double vf = sqrt(2*a*distance);
	double t = sqrt(2*distance/a);
	Car.travel(distance);
	Car.set_speed(vf);
	return t;
}

int main()
{
    
}
