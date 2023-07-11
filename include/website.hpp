#ifndef WEBSITE_HPP
#define WEBSITE_HPP

#include <ESP8266WebServer.h>
#include "config.hpp"

class website {
    ESP8266WebServer server;
    public:
    website(int port = 80): server(80) {
    }
};

#endif
