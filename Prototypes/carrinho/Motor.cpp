#include "Motor.h"

Motor::Motor(uint8_t pin) : motor(pin)
{
  this->speed(255);
};

void Motor::move(uint8_t direction) 
{
  this->motor.run(direction);
};

void Motor::speed(int speed)
{
  this->motor.setSpeed(speed);
}

Motor::~Motor() {};
