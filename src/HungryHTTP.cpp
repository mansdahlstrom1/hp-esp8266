#include "HungryHTTP.h"

String PROTOCOL = "http";
String SERVER = "ubuntu.mansdahlstrom.se";
int PORT = 3000;

String BASE_URL = PROTOCOL + "://" + SERVER + ":" + PORT;

String PostMeasurement(String plantId, int data)
{
  HTTPClient http;
  String response;

  http.begin(BASE_URL + "/postMessurement");
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.POST("{\"plant_id\":\"" + plantId + "\",\"data\":" + data + "}");

  if (httpResponseCode > 0)
  {
    response = http.getString();
    return response;
  }
  else
  {
    Serial.print("Error on sending POST Request: ");
    Serial.println(httpResponseCode);
    response = "server responded with" + httpResponseCode;
  }

  http.end();
  return response;
}
