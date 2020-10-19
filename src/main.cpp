#include "../include/MoistureSensor.h"
#include "../include/HungryHTTP.h"
#include "../include/HungryWebserver.h"
#include "../include/HungryWiFI.h"

bool isConnected = false;
int currentValue = -1;
const int led = 13;

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  setupSensorPins();

  // Check if we are connected to WiFi
  isConnected = connect();

  if (isConnected)
  {
    Serial.println("Device is not connected to WiFi");
    connectedWebserver();
  } else
  {
    Serial.println("Device is connected to WiFi");
    apModeWebserver();
  }
}

void loop()
{
  runServer();
}