#ifndef MOTOR_H
#define MOTOR_H

#include <AFMotor.h>

class Motor 
{
  private:
    AF_DCMotor motor;

    int speed;

  public:
    Motor(uint8_t pin);

    void move(uint8_t direction);
    void setSpeed(int speed);

    ~Motor();
};

#endif
