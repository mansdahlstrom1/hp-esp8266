#include "HungryWiFI.h"

// Måns's
// const char* ssid = "Ahlman / Dahlstrom";
// const char* password = "EstaLockosPollosTacos";

// Otto's
// const char* ssid = "TheBlackPearl";
// const char* password = "AABBCCDDEE";

bool pair(char *ssid, char *passphrase)
{
  int maxTries = 10;
  int tries = 0;

  WiFi.printDiag(Serial);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, passphrase);
  WiFi.printDiag(Serial);

  while (WiFi.status() != WL_CONNECTED && tries < maxTries)
  {
    delay(1000);
    tries += 1;
    Serial.println("Connecting to WiFi..");
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("CONNECTED!!!!!!!");

    return true;
  }
  else
  {
    Serial.println("Failed to connect to wifi");
    return false;
  }
}

void apMode()
{
  // Enter AP Mode
  /* Set these to your desired credentials. */
  const char *ssid = "fixbug";
  const char *password = "yes";

  Serial.println("Starting ap mode");

  Serial.print("My ssid: ");
  Serial.println(ssid);

  Serial.print("My passphrase: ");
  Serial.println(password);

  WiFi.printDiag(Serial);

  // WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  // const bool apStatus = WiFi.softAP(ssid, password);
  const bool apStatus = WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Serial.print("AP status ");
  Serial.println(apStatus);

  WiFi.printDiag(Serial);
}

bool connect()
{
  int maxTries = 10;
  int tries = 0;

  WiFi.printDiag(Serial);
  WiFi.begin();
  WiFi.printDiag(Serial);

  while (WiFi.status() != WL_CONNECTED && tries < maxTries)
  {
    delay(1000);
    tries += 1;
    Serial.println("Connecting to WiFi...");
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    if (!MDNS.begin("hp-esp8266")) {             // Start the mDNS responder for esp8266.local
      Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
   
    Serial.println("CONNECTED!!!!!!!");
    return true;
  }
  else
  {
    // Start pair process
    Serial.println("Failed to connect to wifi");
    apMode();
    return false;
  }
}