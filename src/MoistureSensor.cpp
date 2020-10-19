#include "../include/MoistureSensor.h"

int GPIO0 = 0;
int GPIO2 = 2;
int GPIO3 = 3;

int sensorValue = 0;

void setupSensorPins()
{
    pinMode(GPIO0, OUTPUT);
    pinMode(GPIO2, INPUT);
    digitalWrite(GPIO0, LOW);
}

int measure()
{
    digitalWrite(GPIO0, HIGH);       // power the sensor
    delay(100);                      //make sure the sensor is powered
    sensorValue = digitalRead(GPIO2); // read the value from the sensor:
    Serial.print("sensor = ");
    Serial.println(sensorValue);

    digitalWrite(GPIO0, LOW); //stop power
    delay(100);          //wait

    return sensorValue;
}