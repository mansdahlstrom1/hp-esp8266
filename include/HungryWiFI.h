#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

#ifndef HUNGRY_WIFI_H
#define HUNGRY_WIFI_H

bool pair(char *ssid, char *passphrase);
void apMode();
bool connect();

#endif