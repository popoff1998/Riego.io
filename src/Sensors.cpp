//Debemos procesar independientemente el de humedad y temperatura
#include "platform.h"
#include "Riego.h"

#ifdef W5100GATEWAY
  #include "W5100_Sensors.h"
#else
  #include "USB_Sensors.h"
#endif

//#include <MySensors.h>


#include <core/MySensorsCore.h>

//SENSOR_DALLAS_18B20
  #include <DallasTemperature.h>
  #include <OneWire.h>

// SENSOR_DHT11
  #include <Adafruit_Sensor.h>
  #include <DHT.h>
  #include <DHT_U.h>

//OJO: Mirar donde pongo esto despues ....
DHT_Unified dht(3, DHT11);
sensors_event_t event;

void setup_sensor_DHT11(sSENSOR _Sensor)
{
  dht.begin();
}

void process_sensor_DHT11(sSENSOR _Sensor)
{
  switch(_Sensor.MSpresentType) {
    case S_TEMP:
    {
      dht.temperature().getEvent(&event);
      #ifdef DEBUG
        Serial.print("Temperatura DHT11: ");
        Serial.println(event.temperature);
      #endif
      send(_Sensor.msg->set(event.temperature,1));
    } break;
    case S_HUM:
    {
      dht.humidity().getEvent(&event);
      #ifdef DEBUG
        Serial.print("Humedad DHT11: ");
        Serial.println(event.relative_humidity);
      #endif
      send(_Sensor.msg->set(event.relative_humidity,1));
    } break;
  }
}

void process_sensor_18B20(sSENSOR _Sensor)
{
  OneWire oneWire(_Sensor.pin);
  DallasTemperature sensors(&oneWire);
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);
  #ifdef DEBUG
    Serial.print("Temperatura Dallas: ");
    Serial.print(temperatura);
    Serial.println(" grados");
  #endif
  send(_Sensor.msg->set(temperatura,1));
}
