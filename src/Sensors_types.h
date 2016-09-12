#ifndef Sensors_types_h
#define Sensors_types_h
    	#define SENSOR_DOOR					0	//!< Door sensor, V_TRIPPED, V_ARMED
    	#define SENSOR_MOTION				1 	//!< Motion sensor, V_TRIPPED, V_ARMED
    	#define SENSOR_SMOKE					2	//!< Smoke sensor, V_TRIPPED, V_ARMED
    	#define SENSOR_BINARY				3	//!< Binary light or relay, V_STATUS, V_WATT
    	#define SENSOR_LIGHT					3	//!< \deprecated Same as #define SENSOR_BINARY, **** DEPRECATED, DO NOT USE ****
    	#define SENSOR_DIMMER				4	//!< Dimmable light or fan device, V_STATUS (on/off), V_PERCENTAGE (dimmer level 0-100), V_WATT
    	#define SENSOR_COVER					5	//!< Blinds or window cover, V_UP, V_DOWN, V_STOP, V_PERCENTAGE (open/close to a percentage)
    	#define SENSOR_TEMP					6	//!< Temperature sensor, V_TEMP
    	#define SENSOR_HUM					7	//!< Humidity sensor, V_HUM
    	#define SENSOR_BARO					8	//!< Barometer sensor, V_PRESSURE, V_FORECAST
    	#define SENSOR_WIND					9	//!< Wind sensor, V_WIND, V_GUST
    	#define SENSOR_RAIN					10	//!< Rain sensor, V_RAIN, V_RAINRATE
    	#define SENSOR_UV					11	//!< Uv sensor, V_UV
    	#define SENSOR_WEIGHT				12	//!< Personal scale sensor, V_WEIGHT, V_IMPEDANCE
    	#define SENSOR_POWER					13	//!< Power meter, V_WATT, V_KWH, V_VAR, V_VA, V_POWER_FACTOR
    	#define SENSOR_HEATER				14	//!< Header device, V_HVAC_SETPOINT_HEAT, V_HVAC_FLOW_STATE, V_TEMP
    	#define SENSOR_DISTANCE				15	//!< Distance sensor, V_DISTANCE
    	#define SENSOR_LIGHT_LEVEL			16	//!< Light level sensor, V_LIGHT_LEVEL (uncalibrated in percentage),  V_LEVEL (light level in lux)
    	#define SENSOR_ARDUINO_NODE			17	//!< Used (internally) for presenting a non-repeating Arduino node
    	#define SENSOR_ARDUINO_REPEATER_NODE	18	//!< Used (internally) for presenting a repeating Arduino node
    	#define SENSOR_LOCK					19	//!< Lock device, V_LOCK_STATUS
    	#define SENSOR_IR					20	//!< IR device, V_IR_SEND, V_IR_RECEIVE
    	#define SENSOR_WATER					21	//!< Water meter, V_FLOW, V_VOLUME
    	#define SENSOR_AIR_QUALITY			22	//!< Air quality sensor, V_LEVEL
    	#define SENSOR_CUSTOM				23	//!< Custom sensor
    	#define SENSOR_DUST					24	//!< Dust sensor, V_LEVEL
    	#define SENSOR_SCENE_CONTROLLER		25	//!< Scene controller device, V_SCENE_ON, V_SCENE_OFF.
    	#define SENSOR_RGB_LIGHT				26	//!< RGB light. Send color component data using V_RGB. Also supports V_WATT
    	#define SENSOR_RGBW_LIGHT			27	//!< RGB light with an additional White component. Send data using V_RGBW. Also supports V_WATT
    	#define SENSOR_COLOR_SENSOR			28	//!< Color sensor, send color information using V_RGB
    	#define SENSOR_HVAC					29	//!< Thermostat/HVAC device. V_HVAC_SETPOINT_HEAT, V_HVAC_SETPOINT_COLD, V_HVAC_FLOW_STATE, V_HVAC_FLOW_MODE, V_TEMP
    	#define SENSOR_MULTIMETER			30	//!< Multimeter device, V_VOLTAGE, V_CURRENT, V_IMPEDANCE
    	#define SENSOR_SPRINKLER				31	//!< Sprinkler, V_STATUS (turn on/off), V_TRIPPED (if fire detecting device)
    	#define SENSOR_WATER_LEAK			32	//!< Water leak sensor, V_TRIPPED, V_ARMED
    	#define SENSOR_SOUND					33	//!< Sound sensor, V_TRIPPED, V_ARMED, V_LEVEL (sound level in dB)
    	#define SENSOR_VIBRATION				34	//!< Vibration sensor, V_TRIPPED, V_ARMED, V_LEVEL (vibration in Hz)
    	#define SENSOR_MOISTURE				35	//!< Moisture sensor, V_TRIPPED, V_ARMED, V_LEVEL (water content or moisture in percentage?)
    	#define SENSOR_INFO					36	//!< LCD text device / Simple information device on controller, V_TEXT
    	#define SENSOR_GAS					37	//!< Gas meter, V_FLOW, V_VOLUME
    	#define SENSOR_GPS					38	//!< GPS Sensor, V_POSITION
    	#define SENSOR_WATER_QUALITY			39	//!< V_TEMP, V_PH, V_ORP, V_EC, V_STATUS
#endif
