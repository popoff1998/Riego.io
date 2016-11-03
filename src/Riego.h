//Fichero de include comun a USB y W5100
#ifndef Riego_h
#define Riego_h
#include "platform.h"
#include <Arduino.h>
#include <Time.h>

#ifdef W5100GATEWAY
  #include "W5100_Sensors.h"
#else
  #include "USB_Sensors.h"
#endif

#include <core/MyMessage.h>

//Globales para los diferentes tipos de sensores. Mirar más adelante para ver si soporta varios
//Defines y estructura para flags
enum {
  ENABLED = 0x01,
  REQUESTABLE = 0x02,
};

typedef union
{
  uint8_t all_flags;
  struct
  {
    uint8_t enabled :     1,
            requestable : 1,
            spare5 :      1,
            spare4 :      1,
            spare3 :      1,
            spare2 :      1,
            spare1 :      1,
            spare0 :      1;
  };
} S_FLAGS;

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
  int HWsubtype;
  char desc[50];
  MyMessage *msg;
  S_FLAGS flags;
};

struct sCOUNTER {
  int id;
  int pin;
  char unitDesc[20];
  char desc[50];
  MyMessage *msgVolume;
  MyMessage *msgFlow;
  int mode;
            unsigned  long        MAXFLOW;
            unsigned  long        MILLISZEROFLOW;
            unsigned  long        DEBOUNCEMICROSECS;
                      long        PULSESFORLITER;
  volatile  unsigned  long        lastBlink;
  volatile  unsigned  long        newBlink;
                      double      volume;
                      double      oldVolume;
  volatile            double      flow;
                      double      oldFlow;
            unsigned  long        lastSend;
            unsigned  long        lastPulse;
  volatile  unsigned  long        pulseCount;
            unsigned  long        oldPulseCount;
};

//Defines varios
#define NOTFOUND 255

//Definicion de initStates
#define SETOFF  0
#define SETON   1
#define KEEP    2

//defines de comportamiento
#define POLL_TIME 10000 //msec para chequear los sensores

//ID de childs para conseguir informacion del controller
#define CHILD_ID_POLL_TIME 64

//Defines de tipos HWtype
#define DALLAS_18B20  0
#define DDHHTT        1
#define S_PHOTORESISTOR 3
#define INFO 4
#define S_ARDUINO_TEMP 5

//Defines de tios HWsubtype
#define NONE 0
#define S_POLL_TIME 1
#define S_MEMORY_FREE 2

//Opciones de depuracion
#define MY_DEBUG
#define EXTRADEBUG
//#define DEBUG
#define COUNTERDEBUG
//#define COUNTEREXTRADEBUG

//Funciones
void setup_sensor_DHT11(sSENSOR);
void setup_sensor_INFO(sSENSOR);

void process_sensor_DHT11(sSENSOR);
void process_sensor_18B20(sSENSOR);
void process_sensor_PHOTORESISTOR(sSENSOR);
void process_sensor_INFO(sSENSOR);
void process_sensor_arduino_temp(sSENSOR);


void receive_sensor_INFO(MyMessage);

void setup_counter();
void process_counter();

#endif
