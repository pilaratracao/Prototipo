#include "SerialCommunication.h"
#include "Carro.h"

#define arduino Serial
#define esp Serial2

SerialCommunication serial;
Carro carro("CR001");

String topic = "Id";
String data = carro.getId();

void setup() 
{
  arduino.begin(9600);
  esp.begin(9600);

  serial.waitHandshake(topic, data);

  delay(1000);
}

void loop() 
{
   serial.receive();
   arduino.println(serial.getMsg().as<String>()); // {"acceleration": 0, "speed-left": 0, "speed-right": 0}

   carro.run();
}
