//Fichero de include comun a USB y W5100
#ifndef Riego_h
#define Riego_h
#include "platform.h"
#include <Arduino.h>

#ifdef W5100GATEWAY
  #include "W5100_Sensors.h"
#else
  #include "USB_Sensors.h"
#endif

#include <core/MyMessage.h>

//Globales para los diferentes tipos de sensores. Mirar más adelante para ver si soporta varios

//Estructura de reles
struct sRELE {
  int id;
  int  pin;
  char desc[50];
  bool ON;
  bool OFF;
  int initState;
  bool enabled;
};

struct sSENSOR {
  int id;
  int pin;
  int MSpresentType;
  int MSmessageType;
  int HWtype;
  char desc[50];
  MyMessage *msg;
  bool enabled;
};

//Definicion de initStates
#define SETOFF  0
#define SETON   1
#define KEEP    2

//defines de comportamiento
#define POLL_TIME 10000 //msec para chequear los sensores

//Defines de sensor para procesar
#define DALLAS_18B20  0
#define DDHHTT        1

//Opciones de depuracion
//#define MY_DEBUG
#define EXTRADEBUG
#define DEBUG

//Funciones
void process_sensor_DHT11(sSENSOR);
void setup_sensor_DHT11(sSENSOR);
void process_sensor_18B20(sSENSOR);

#endif
