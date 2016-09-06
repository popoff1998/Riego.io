//Seleccionar la tarjeta W5100 o USB
#define W5100GATEWAY
//#define USBGATEWAY

#include "Riego.h"

#ifdef W5100GATEWAY
  #include "W5100.h"
#else
  #include "USB.h"
#endif

#include <MySensors.h>

void initRelays(const sRELE Rele[], int NUMBER_OF_RELAYS)
{
  for (int rele=0 ; rele<NUMBER_OF_RELAYS;rele++) {
    // Poner el rele en output mode
    pinMode(Rele[rele].pin, OUTPUT);
    //Poner initState
    switch(Rele[rele].initState) {
      case SETON:
        digitalWrite(Rele[rele].pin, Rele[rele].ON);
        break;
      case SETOFF:
        digitalWrite(Rele[rele].pin, Rele[rele].OFF);
        break;
      case KEEP:
        digitalWrite(Rele[rele].pin, loadState(rele)?Rele[rele].ON:Rele[rele].OFF);
      default:
        //Por defecto y por seguridad lo ponemos a OFF si está mal definido en la estructura
        digitalWrite(Rele[rele].pin, Rele[rele].OFF);
        break;
    }
  }
}

void presentRelays(const sRELE Rele[], int NUMBER_OF_RELAYS)
{
  //Presentar los reles
  for (int rele=0; rele<NUMBER_OF_RELAYS;rele++) {
    // Registrar todos los reles al gw
    present(rele, S_LIGHT,Rele[rele].desc);
  }
}

void receive(const MyMessage &message) {
  // Solo esperamos mensajes V_LIGTH de momento, pero lo chequeamos por si acaso.
  if (message.type==V_LIGHT) {
     // Cambiar estado del rele
     digitalWrite(Rele[message.sensor].pin, message.getBool()?Rele[message.sensor].ON:Rele[message.sensor].OFF);
     // Almacenar estado en la eeprom independientemente de initState (por si acaso)
     saveState(message.sensor, message.getBool());
     // Escribir informacion de debug
     Serial.print("Cambio entrante para sensor:");
     Serial.print(message.sensor);
     Serial.print(", Nuevo status: ");
     Serial.println(message.getBool());
   }
}

void presentation()
{
  // Presentar los sensores y actuadores locales
  Serial.println("start call presentation");
  // Mandar la info del sketch
  sendSketchInfo(SKETCH_NAME, SKETCH_VERSION);
  presentRelays(Rele,NUMBEROFRELAYS);
  Serial.println("End call presentation");
}

void setup()
{
  //Para los reles
   Serial.println("start call SETUP");
   initRelays(Rele,NUMBEROFRELAYS);
   Serial.println("End call Setup");
}

void loop() {
  // Send locally attached sensor data here
#ifdef TEMP
  Serial.print("Solicitando temperaturas...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  float temperatura = sensors.getTempCByIndex(0);
  send(msg.setSensor(9).set(temperatura,1));
  Serial.println("DONE");
  sleep(2000);
#endif
}
