#include "SerialCommunication.h"

#define arduino Serial
#define esp Serial2

SerialCommunication::SerialCommunication() {};

StaticJsonDocument<100> SerialCommunication::getMsg() const 
{
  return this->msg;
}

void SerialCommunication::waitHandshake(String topic, String data)
{
  while (msg["ESP"] != "Hello")
  {
    arduino.println(msg.as<String>());
    this->receive();
  }
  
  this->send(topic, data);
  
  Serial.println("Recebido um handshake: " + msg["ESP"].as<String>() + "from ESP");
  delay(1000);
}

void SerialCommunication::receive()
{
  if (esp.available() > 2)
  {
    StaticJsonDocument<100> data;
    DeserializationError err = deserializeJson(data, esp);
    
    if (err == DeserializationError::Ok)
    {
      this->msg = data;
    }
  }
}

void SerialCommunication::send(String topic, String data)
{
  StaticJsonDocument<100> doc;

  doc[topic] = data;

  serializeJson(doc, esp);
}

SerialCommunication::~SerialCommunication() {};
