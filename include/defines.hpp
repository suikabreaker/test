#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <Arduino.h>

#ifndef FILE_SYSTEM
#define FILE_SYSTEM LittleFS
#endif

#ifndef ERROR_PRINTLN
#define Serial.println
#endif

#ifndef ERROR_PRINT
#define Serial.print
#endif

#ifndef BYTE_RATE
#define BYTE_RATE 115200
#endif

#if FILE_SYSTEM == LittleFS
#include <LittleFS.h>
#elif FILE_SYSTEM == FILE_SYSTEM
#include <FS.h>
#elif FILE_SYSTEM == SDFS
#include <SDFS.h> // SDFS is declared
#endif

#ifndef CONFIG_PATH
#define CONFIG_PATH "/config"
#endif

#endif