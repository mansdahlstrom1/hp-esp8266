#include <Arduino.h>
#include "ESP8266HTTPClient.h"

#ifndef HUNGRY_HTTP_H
#define HUNGRY_HTTP_H

String PostMeasurement(String plantId, int data);

#endif
