#ifndef W5100_h
#define W5100_H
//Defines de configuracion
#define MY_NODE_ID 5
#define SKETCH_NAME "Gateway Ethernet"
#define SKETCH_VERSION "1.0"

//Defines del gateway
#define MY_GATEWAY_W5100
#define MY_IP_ADDRESS 192,168,100,61   // If this is disabled, DHCP is used to retrieve address
#define MY_PORT 5003
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC

//#define MY_INCLUSION_MODE_FEATURE
//#define MY_INCLUSION_BUTTON_FEATURE
//#define MY_INCLUSION_MODE_DURATION 60
//#define MY_INCLUSION_MODE_BUTTON_PIN  3

#include "Riego.h"

//Variables de actuadores
#define NUMBER_OF_RELAYS 4

struct sRELE Rele [] = {  {0, 13 , "LED", HIGH, LOW, KEEP, true},
                          {1, 31 , "RELE GOTEROS ALTOS", LOW, HIGH, SETOFF, true},
                          {2, 33 , "RELE ASPERSOR FONDO", LOW, HIGH, SETOFF, true},
                          {3, 35 , "LUZ DEL PORCHE", LOW, HIGH, KEEP, true}
                       };

//Variables de los sensores
int NUMBER_OF_SENSORS=6;

struct sSENSOR Sensor [] = {  {7, 3, S_HUM, V_HUM, DDHHTT, NONE, "HUMEDAD DHT11", 0, ENABLED},
                              {8, 3, S_TEMP, V_TEMP, DDHHTT, NONE, "TEMPERATURA DHT11", 0, ENABLED},
                              {9, 2, S_TEMP, V_TEMP, DALLAS_18B20, NONE, "TEMPERATURA DALLAS", 0, ENABLED},
                              {10, A0, S_LIGHT_LEVEL, V_LEVEL, S_PHOTORESISTOR, NONE, "PHOTORESISTOR", 0, ENABLED},
//                              {11, A0, S_TEMP, V_TEMP, S_ARDUINO_TEMP, NONE, "W5100 TEMP", 0, ENABLED},
//Aquí vienen los pseudosensores para informacion
                              {20, 0, S_INFO, V_TEXT, INFO, S_POLL_TIME, "POLL TIME", 0, ENABLED | REQUESTABLE},
                              {21, 0, S_INFO, V_TEXT, INFO, S_MEMORY_FREE, "MEMORY FREE", 0, ENABLED}
                           };


//Includes especificos de la plataforma
#include <Ethernet.h>

#endif
