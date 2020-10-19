#include <Arduino.h>
#include <ESP8266WebServer.h>
#include "MoistureSensor.h"
#include "HungryWiFi.h"

#ifndef HUNGRY_WEBSERVER_H
#define HUNGRY_WEBSERVER_H

void handleRoot();
void handleWifiCredentials();
void takeMeasurement();
void apModeWebserver();
void connectedWebserver();
void runServer();

#endif