# UCLA SMV Special Projects Virtual Car

motor.cpp
- Used to simulate motor ramping, throttle, rpm, and force
- motor class acts as a member variable of the car
- Contains currently used data metrics of phsyical motor

## motor::get_time()

- Calculates the current time (in milliseconds) from the start of the program

## motor::get_voltage(int throttle) (Need to get this checked by Jacob or Marcus)

- Throttle based on input (value of 0 through 1023)
- Max motor speed is returned and converted to battery voltage
- Current battery voltage is returned

## motor::rungeKuttaRPM(double timeStart, double timeEnd, double step, double voltage)

- Approximates an integral to determine the new rpm and torque
- New rpm is returned

## motor::get_force()

- Uses most recent torque calculation to provide current motor force

## motor::hold15MPH()

- Calls member functions to maintain 15 MPH speed
- Returns new motor output force


