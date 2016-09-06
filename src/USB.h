//Defines de configuracion
#define MY_NODE_ID 4
#define SKETCH_NAME "Gateway Usb"
#define SKETCH_VERSION "1.0"

//Defines del gateway
#define MY_GATEWAY_SERIAL

#define MY_INCLUSION_MODE_FEATURE
#define MY_INCLUSION_BUTTON_FEATURE
#define MY_INCLUSION_MODE_DURATION 60
#define MY_INCLUSION_MODE_BUTTON_PIN  3

#include "Riego.h"
//Variables de actuadores
#define NUMBEROFRELAYS 4

const sRELE Rele [] = { {13 , "LED", HIGH, LOW},
                        {31 , "RELE ASPERSOR PORCHE", LOW, HIGH},
                        {33 , "RELE TURBINAS", LOW, HIGH},
                        {35 , "RELE GOTEROS BAJOS", LOW, HIGH}
                      };
