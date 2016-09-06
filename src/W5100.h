//Defines de configuracion
#define MY_NODE_ID 5
#define SKETCH_NAME "Gateway Ethernet"
#define SKETCH_VERSION "1.0"

//Defines del gateway
#define MY_GATEWAY_W5100
#define MY_IP_ADDRESS 192,168,100,61   // If this is disabled, DHCP is used to retrieve address
#define MY_PORT 5003
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC

#define MY_INCLUSION_MODE_FEATURE
#define MY_INCLUSION_BUTTON_FEATURE
#define MY_INCLUSION_MODE_DURATION 60
#define MY_INCLUSION_MODE_BUTTON_PIN  3

#include "Riego.h"

//Variables de actuadores
#define NUMBEROFRELAYS 4

struct sRELE Rele [] = {  {13 , "LED", HIGH, LOW, KEEP},
                          {31 , "RELE GOTEROS ALTOS", LOW, HIGH, SETOFF},
                          {33 , "RELE ASPERSOR FONDO", LOW, HIGH, SETOFF},
                          {35 , "LUZ DEL PORCHE", LOW, HIGH, KEEP}
                       };



//Includes especificos de la plataforma
#include <Ethernet.h>










//void loop() {
//}
