#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include <ESP8266WiFiType.h>
#include <MemStream.h>
#include <stdlib.h>
#include "defines.hpp"

typedef size_t (&const error_hdl_t) (const String &s);

class Config{
  private:
    WiFiMode wifi_mode;
    char ssid[32];
    char password[64];
    char hostname[32];
  public:
  Config() {}
  Config(Stream& source) {
    while (source.available()) {
      String line = source.readStringUntil('\n');
      line.trim();
      if (line.length() == 0) {
        continue;
      }
      if (line[0] == '#') {
        continue;
      }
      int pos = line.indexOf('=');
      if (pos < 0) {
        ERROR_PRINTLN("Invalid config line: " + line);
        continue;
      }
      String key = line.substring(0, pos);
      String value = line.substring(pos + 1);
      // TODO check lengths
      if (key == "ssid") {
        value.toCharArray(ssid, sizeof(ssid));
      } else if (key == "password") {
        value.toCharArray(password, sizeof(password));
      } else if (key == "wifi_mode") {
          if (value == "AP") {
              wifi_mode = WIFI_AP;
          } else if (value == "STA") {
              wifi_mode = WIFI_STA;
          } else if (value == "AP_STA") {
              wifi_mode = WIFI_AP_STA;
          } else {
              ERROR_PRINTLN("Invalid wifi_mode: " + value);
              wifi_mode = WIFI_STA;
          }
      } else if (key == "hostname") {
        value.toCharArray(hostname, sizeof(hostname));
      } else {
        ERROR_PRINTLN("Invalid config key: " + key);
      }
    }
  }
  
  
};

// global copy of config
extern std::unique_ptr<Config> config;

#endif // CONFIG_HPP