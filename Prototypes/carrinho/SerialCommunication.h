#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <Arduino.h>
#include <ArduinoJson.h>

class SerialCommunication {
   private:
     String destiny;

     StaticJsonDocument<100> msg;
     
   public:
     SerialCommunication();

     StaticJsonDocument<100> getMsg() const;
     
     void waitHandshake(String topic, String data);
    
     void receive();
     void send(String topic, String data);
     
     ~SerialCommunication();
};

#endif
