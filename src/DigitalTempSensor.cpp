#include "DigitalTempSensor.h"

int DH_PIN = 2; // input/output pin
byte dat[5];

byte read_data() {
  byte data;
  for(int i = 0; i < 8; i++) {
    if(digitalRead(DH_PIN) == LOW) {
      while(digitalRead(DH_PIN) == LOW); // wait 50us;
      delayMicroseconds(30); // Duration of high level determine whether data is 0 or 1
      if(digitalRead(DH_PIN) == HIGH)
        data |= (1<<(7 - i)); //High in the former, low in the post;
      while(digitalRead(DH_PIN) == HIGH); //Data '1', waiting for next bit
    }
  }
  return data;
}

void start_test() {
  digitalWrite(DH_PIN, LOW); //Pull down the bus to send the start signal;
  delay(30); //The delay is greater than 18 ms so that DHT 11 can detect the start signal;
  digitalWrite(DH_PIN, HIGH);
  delayMicroseconds(40); //Wait for DHT11 to respond;
  pinMode(DH_PIN, INPUT);
  
  while(digitalRead(DH_PIN) == HIGH);
    delayMicroseconds(80); //The DHT11 responds by pulling the bus low for 80us;
  
  if(digitalRead(DH_PIN) == LOW) {
    delayMicroseconds(80); //DHT11 pulled up after the bus 80us to start sending data;
  }
  
  for(int i = 0; i < 4; i++) //Receiving data, check bits are not considered;
    dat[i] = read_data();
  
  pinMode(DH_PIN, OUTPUT);
  digitalWrite(DH_PIN, HIGH); //After release of bus, wait for host to start next signal
}
