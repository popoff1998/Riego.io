#include "platform.h"
#include "Riego.h"
#include "globals.h"

#ifdef W5100GATEWAY
  #include "W5100.h"
  #include "W5100_Sensors.h"
#else
  #include "USB.h"
  #include "USB_Sensors.h"
#endif

#include <MySensors.h>

void initRelays(const sRELE Rele[], int nRelays)
{
  for (int i=0 ; i<nRelays; i++) {
    if (Rele[i].enabled) {
      // Poner el rele en output mode
      pinMode(Rele[i].pin, OUTPUT);
      //Poner initState
      switch(Rele[i].initState) {
        case SETON:
          digitalWrite(Rele[i].pin, Rele[i].ON);
          break;
        case SETOFF:
          digitalWrite(Rele[i].pin, Rele[i].OFF);
          break;
        case KEEP:
            #ifdef EXTRADEBUG
              Serial.print("Rele ");
              Serial.print(i);
              Serial.print(" es en la eeprom ");
              Serial.println(loadState(i));
            #endif
          digitalWrite(Rele[i].pin, loadState(i)?Rele[i].ON:Rele[i].OFF);
          break;
        default:
          //Por defecto y por seguridad lo ponemos a OFF si está mal definido en la estructura
          digitalWrite(Rele[i].pin, Rele[i].OFF);
          break;
      }
    }
  }
}

void presentRelays(const sRELE Rele[], int nRelays)
{
  //Presentar los reles
  for (int i=0; i<nRelays; i++) {
    if (Rele[i].enabled) {
      // Registrar todos los reles al gw
      present(Rele[i].id, S_LIGHT,Rele[i].desc);
      // Le tenemos que mandar el estado que tiene.
      MyMessage relayMsg(Rele[i].id,S_LIGHT);
        #ifdef EXTRADEBUG
          Serial.print("El estado del rele ");
          Serial.print(Rele[i].desc);
          Serial.print(" es: ");
          Serial.println(digitalRead(Rele[i].pin));
        #endif
      send(relayMsg.set(digitalRead(Rele[i].pin)?Rele[i].ON:Rele[i].OFF));
    }
  }
}

void initSensors(sSENSOR Sensor[], int nSensors)
{
  for (int i=0; i<nSensors; i++) {
    if (Sensor[i].enabled) {
      //Instanciamos un nuevo msg para cada sensor
      Sensor[i].msg = new MyMessage(Sensor[i].id,Sensor[i].MSmessageType);
      switch(Sensor[i].HWtype) {
        case DDHHTT: {
          setup_sensor_DHT11(Sensor[i]);
        } break;
      }
    }
  }
}

void presentSensors(sSENSOR Sensor[], int nSensors)
{
  for (int i=0; i<nSensors; i++) {
    if (Sensor[i].enabled) {
      Serial.print("Presentando sensor: ");
      Serial.print(Sensor[i].id);
      Serial.print(" ");
      Serial.println(Sensor[i].desc);
      present(Sensor[i].id,Sensor[i].MSpresentType,Sensor[i].desc);
    }
  }
}

void receive(const MyMessage &message) {
  // Solo esperamos mensajes V_LIGTH de momento, pero lo chequeamos por si acaso.
  if (message.type==V_LIGHT) {
    // Cambiar estado del rele
    digitalWrite(Rele[message.sensor].pin, message.getBool()?Rele[message.sensor].ON:Rele[message.sensor].OFF);
    // Almacenar estado en la eeprom independientemente de initState (por si acaso)
    saveState(message.sensor, message.getBool());
    #ifdef DEBUG
     // Escribir informacion de debug
     Serial.print("Cambio entrante para sensor:");
     Serial.print(message.sensor);
     Serial.print(", Nuevo status: ");
     Serial.println(message.getBool());
    #endif
  }
}

void presentation()
{
  // Presentar los sensores y actuadores locales
  Serial.println("Comenzando presentacion");
  // Mandar la info del sketch
  sendSketchInfo(SKETCH_NAME, SKETCH_VERSION);
  presentRelays(Rele,NUMBER_OF_RELAYS);
  presentSensors(Sensor,NUMBER_OF_SENSORS);
  Presented = true;
  Serial.println("Finalizando presentacion");
}

void setup()
{
  //Para los reles
   Serial.println("start call SETUP");
   initRelays(Rele,NUMBER_OF_RELAYS);
   initSensors(Sensor,NUMBER_OF_SENSORS);
   Serial.println("End call Setup");
}

//MyMessage msg(0,0);

void loop() {
  if (!Presented)
  {
    #ifdef DEBUG
      Serial.println("Sensores aun no presentados, saliendo de loop");
    #endif
    wait(POLL_TIME);
    return;
  }

  //Bucle para procesar todos los sensores
  for (int i=0; i<NUMBER_OF_SENSORS; i++) {
    //Creamos el mensaje
    if(Sensor[i].enabled) {
      switch(Sensor[i].HWtype) {
        case DALLAS_18B20:
        {
          #ifdef DALLAS_18B20_TEMP
            process_sensor_18B20(Sensor[i]);
          #endif
        } break;

        case DDHHTT:
        {
          #ifdef SENSOR_DHT11
            process_sensor_DHT11(Sensor[i]);
          #endif
        } break;
      }
    }
  }
  wait(POLL_TIME);
}
