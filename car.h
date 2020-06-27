class car
{
  public:
    car(double weight, double maxspeed, double power, double crr = 0, double cda = 0);
  private:
    double weight;
    double maxspeed;
    double power;
    double crr; //coefficient of rolling resistance
    double cda; //drag area
};
