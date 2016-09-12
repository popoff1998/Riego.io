//Fichero de include comun a USB y W5100
#ifndef Riego_h
#define Riego_h

#include <Arduino.h>
#include "Sensors_types.h"

#ifdef W5100GATEWAY
  #include "W5100_Sensors.h"
#else
  #include "USB_Sensors.h"
#endif

//Por probar
#include <core/MyMessage.h>

//Globales para los diferentes tipos de sensores. Mirar más adelante para ver si soporta varios
#ifdef TEMP
  #include <DallasTemperature.h>
  #include <OneWire.h>
#endif

#ifdef SENSOR_DHT11
  #include <Adafruit_Sensor.h>
  #include <DHT.h>
  #include <DHT_U.h>
#endif

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

//Variables Globales
bool Presented = false;

#endif
