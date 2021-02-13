#ifndef RAMPING_H
#define RAMPING_H

const int NEUTRAL_THROTTLE = 100;
const int MAX_THROTTLE = 1023;
const int MAX_SPD = 255;
const int MIN_SPD = 0;

const bool rampingOption = true; // true for Linear, false for PD
const int Kp = -1, Kd = -1; 
const int RAMP_SPD = 1;

class Ramping{
public:
  Ramping();
  virtual int newSpd(int throttle, long timeMillis) = 0;
protected:
  void setCurrentSpd(int spd); 
  void setDesiredSpd(int spd);
  int getCurrentSpd() const;
  int getDesiredSpd() const;

  bool isTimeToChangeSpd(long timeMillis);

  void spdUp(int amount);
  void spdDown(int amount);
private:
  int m_currentSpd;
  int m_desiredSpd;
  long m_time = 0;
  const long m_maxWaitTime = 100;
};

class Linear : public Ramping{
public:
  int newSpd(int throttle, long timeMillis);
};

class PD : public Ramping{
public:
  PD();
  int newSpd(int throttle, long timeMillis);
private:
  int m_error, m_prevError, m_rateError;
};

template<typename T>
inline
T map(T input, T lower_input, T upper_input, T lower_output, T upper_output)
{
    // Find decimal mapping of input between bounds
    double mapping = (1.0*input - lower_input)/(upper_input - lower_input);

    // Find output value based on linear mapping
    T output = ((upper_output - lower_output) * mapping) + lower_output;
    return output;
}
#endif