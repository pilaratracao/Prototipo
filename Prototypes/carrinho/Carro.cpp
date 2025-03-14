#include "Carro.h"

Carro::Carro(String id_) : id(id_), LMotor1(1), LMotor2(2), RMotor3(3), RMotor4(4){};

String Carro::getId() const
{
  return this->id;
}

void Carro::run() 
{
  LMotor1.run();
  LMotor2.run();

  RMotor3.run();
  RMotor4.run();
};

Carro::~Carro() {};
