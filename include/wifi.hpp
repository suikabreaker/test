#include <ESP8266WiFiType.h>
#include <ESP8266WiFi.h>

MDNSResponder mdns;

inline int wifi_led(int) {
}

inline int init_wifi() {
  WiFi.mode(wifi_mode);
  WiFi.begin(ssid, password);


  ERROR_PRINTLN("Connecting to "); ERROR_PRINT(ssid);
  digitalWrite(led0,HIGH);
  wifi_led(1);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  ERROR_PRINTLN("Connected.");
  ERROR_PRINT("IP address: "); ERROR_PRINTLN(WiFi.localIP());

  if (mdns.begin(hostname, WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  return 0;
}

inline void wifi_update() {
  if(WiFi.status() != WL_CONNECTED){
    digitalWrite(led0, LOW);
    ERROR_PRINTLN("Wifi is disconnected!");
  }
}
