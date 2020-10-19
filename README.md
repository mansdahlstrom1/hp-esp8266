# hungry-plants-ESP8266

## Links / Resources

- [ESP8266 Breakboard config](https://www.behind-the-scenes.co.za/connecting-the-esp8266-to-a-breadboard-and-ftdi-programmer/)
- [Make HTTP Request from ESP8266](https://techtutorialsx.com/2019/01/30/esp8266-arduino-http-put-request)
- [PlatformIO](https://platformio.org/platformio-ide?utm_source=arduino-esp8266)
- [PlatformIO esp8266 config](https://docs.platformio.org/en/latest/platforms/espressif8266.html?utm_source=arduino-esp8266#)
- [Getting started Guide](https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html)

## Log

### 2020 - 10 - 17

- [x] Wifi setup works
- [ ] Hardware needs to be updated
  - [ ] https://components101.com/wireless/esp8266-pinout-configuration-features-datasheet.
  - [ ] https://www.electrokit.com/uploads/productfile/41015/41015738_-_Soil_Moisture_Sensor.pdf
  - [ ] Build breadboard for flashing the ESP8266
  - [ ] Build breadboard for running the ESP8266 with sensor connected
- [x] Webserver that start if the ESP8266 is connected to wifi, this page then reads a sensor value for GPIO2 and displays it when someone goes to ´<esp8266-IP>/´. WE currently do not get the correct value.

When powered on we get ´1023´. When powered off we get `0`
