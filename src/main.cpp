#include <Arduino.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include "config.hpp"
#include "defines.hpp"

static int init_fs() {
    return ;
}

std::unique_ptr<Config> config;

static bool init_config(const char* path){
  if (!FILE_SYSTEM.exists(path)) {
    config = std::make_unique<Config>();
    return true;
  }

  File configFile = FILE_SYSTEM.open(path, "r");
  if (!configFile) {
    ERROR_PRINTLN("Failed to open config file");
    // we can do nothing about it
    abort();
  }

  config = std::make_unique<Config>(configFile);
  return false;
}

void setup(void){    
  Serial.begin(BYTE_RATE);
  FILE_SYSTEM.begin();
  bool first_time = init_config(CONFIG_PATH);
  if(first_time) {

  }
  
}
 
void loop(void){
  wifi_update();
  server.handleClient();
} 

