#include "HungryWebserver.h"

ESP8266WebServer server(80);

void handleRoot()
{
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void handleWifiCredentials()
{
  Serial.print("URI: ");
  Serial.println(server.uri());
  Serial.print("\nMethod: ");
  Serial.println((server.method() == HTTP_GET) ? "GET" : "POST");
  Serial.print("\nArguments: ");
  Serial.println(server.args());

  String ssid = "";
  String passphrase = "";

  for (int i = 0; i < server.args(); i++)
  {
    String key = server.argName(i);
    String value = server.arg(i);
    Serial.println(key + " = " + value);

    if (key == "ssid")
    {
      ssid = value;
    }

    if (key == "pass")
    {
      passphrase = value;
    }
  }

  char ssidBuf[ssid.length() + 1];
  ssid.toCharArray(ssidBuf, ssid.length() + 1);
  char *set = ssidBuf;

  char passBuf[passphrase.length() + 1];
  passphrase.toCharArray(passBuf, passphrase.length() + 1);
  char *tes = passBuf;
  // can ssid or passphare be empty string in a real world senario? in case of null check
  bool isConnected = pair(set, tes);

  if (isConnected)
  {
    server.send(200, "application/json", "{\"status\": 200, \"message\": \"U did it\" }");
  }
  else
  {
    server.send(200, "application/json", "{\"status\": 200, \"message\": \"U didn't it\" }");
  }
}

void takeMeasurement()
{
  int measurement = measure();

  String response = "{";
  response += "\"status\": 200,";
  response += "\"measurement\":" + String(measurement);
  response += "}";

  server.send(200, "application/json", response);
}

void apModeWebserver()
{
  Serial.println("Starting Ap Mode Webserver");
  server.on("/", handleRoot);
  server.on("/wifi", HTTP_GET, handleWifiCredentials);
  server.begin();
}

void connectedWebserver()
{
  Serial.println("Starting connected Webserver");
  server.on("/", takeMeasurement);
  server.begin();
}

void runServer()
{
  server.handleClient();
}
