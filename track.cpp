#idndef TRACK_H
#def TRACK_H

track::track()
{
    c_static_friction = 1.0; //change to typical value for asphalt
    c_dynamic_friction = 1.0; //change to typical value for asphalt
    inclination = 0.0;
    banking = 0.0;
    fluid_density = 1.292; //typical value for air at room pressure and standard atm press.
}

//add typical accessor and mutator methods

#endif
