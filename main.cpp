#include "car.h"
#include "track.h"
#include "motor.h"
#include <iostream>
#include <math.h>

using namespace std;

void check_input()
{
    if(!cin)
    {
        cout << "Invalid Input" << endl;
        exit(1);
    }
}

int main()
{
    track* t = new track;
    motor* m = new motor(t); // not sure why motor needs track, ask Satva
    car* c = new car(t, m);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Choose a car:" << endl << "Press 1 for 2019 Car" << endl << "Press 0 for car information" << endl; //include other options later
    int car_choice;
    cin >> car_choice;
    check_input();
    while(car_choice==0){
        cout << "2019 Car:" << endl;
        cout << "Weight: 73 pounds" << endl << endl;
        //add other specs when we get them, like crr, drag coeff, wheel radius perhaps
        cout << "Choose a car:" << endl << "Press 1 for 2019 Car" << endl << "Press 0 for car information" << endl;
        cin >> car_choice;
        check_input();
    }
    if(car_choice==1){
        c->set_mass(33.11);
    }else{
        cout << "Invalid choice" << endl;
        exit(1);
    }
    cout << "Enter speed in miles per hour (15 mph suggested):" << endl;
    double speed_choice;
    cin >> speed_choice;
    check_input();
    speed_choice = speed_choice/2.237; //convert to m/s

    cout << "Enter number of laps:" << endl;
    int lap_choice;
    cin >> lap_choice;
    check_input();
    if (lap_choice<0)
    {
        cout << "Invalid choice" << endl;
        exit(1);
    }
    c->set_velocity(speed_choice);
    double time = 0; 
    for(int i=0;i<lap_choice;i++)
        time += t->time_to_run(c);

    double l = 0.0;
    for(int j=0;j<lap_choice;j++)
        l += t->get_total_length();
    double ms = l/time;
    cout << endl << endl << "time: " << time << " s"<< endl;
    cout << "average velocity: " << ms << " m/s" << endl;
    cout << "distance traveled: " << l << " m" << endl;
    delete c;
    delete t;
}