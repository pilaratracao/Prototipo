#include "Wifi.h"
#include "SerialCommunication.h"
#include "Websocket.h"

Wifi wifi;
Websocket ws;
SerialCommunication serial;

const char * address = "192.169.137.145";
const int port = 8080;

void setup() {
  Serial.begin(9600);
  
  serial.waitHandshake("{\"Id\": \"ESP\", \"Data\": \"Ok\"}");
  ws.setId(serial.getReceivedMsg()["Id"]);
  
  wifi.start();
  ws.start(address, port);

  delay(1000);
}

void loop() {
  serial.receive();
  
  ws.loop();

  if (serial.getLastSentMsg() != ws.getMsg()) {
      serial.send(ws.getMsg());
  }
}
