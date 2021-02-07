#ifndef RAMPING_H
#define RAMPING_H

const int NEUTRAL_THROTTLE = 100;
const int MAX_THROTTLE = 1023;
const byte MAX_SPD = 255;
const byte MIN_SPD = 0;

const bool rampingOption = true; // true for Linear, false for PD
const byte Kp = -1, Kd = -1; 
const byte RAMP_SPD = 1;

class Ramping{
public:
  Ramping();
  virtual byte newSpd(int throttle, long timeMillis) = 0;
protected:
  void setCurrentSpd(byte spd); 
  void setDesiredSpd(byte spd);
  byte getCurrentSpd() const;
  byte getDesiredSpd() const;

  bool isTimeToChangeSpd(long timeMillis);

  void spdUp(byte amount);
  void spdDown(byte amount);
private:
  byte m_currentSpd;
  byte m_desiredSpd;
  long m_time = 0;
  const long m_maxWaitTime = 100;
};

class Linear : public Ramping{
public:
  byte newSpd(int throttle, long timeMillis);
};

class PD : public Ramping{
public:
  PD();
  byte newSpd(int throttle, long timeMillis);
private:
  byte m_error, m_prevError, m_rateError;
};
#endif