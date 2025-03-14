#ifndef CARRO_H
#define CARRO_H

#include <Arduino.h>
#include "Motor.h"

class Carro 
{
  private:
    String id;
  
    Motor LMotor1;
    Motor LMotor2;
    Motor RMotor3;
    Motor RMotor4;

  public:
    Carro(String id_);

    String getId() const;
    
    void run();

    ~Carro();

};

#endif
