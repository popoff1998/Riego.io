//Fichero de include comun a USB y W5100
#ifndef Riego_h
#define Riego_h

#include <Arduino.h>

//Estructura de reles
struct sRELE {
  int  pin;
  char desc[50];
  bool ON;
  bool OFF;
  int initState;
};

//Definicion de initStates
#define SETOFF  0
#define SETON   1
#define KEEP    2

#endif
