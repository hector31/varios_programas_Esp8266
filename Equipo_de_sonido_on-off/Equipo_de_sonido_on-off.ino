// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "SEES.ING-FLIA NARVAEZ PANTO";
char wifiPassword[] = "27534498GLADYS";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "f6468fe0-eba9-11e8-8e60-53d8c8eabc71";
char password[] = "5c6cee12abda3970d58f33ee22dfe64a01a01cb0";
char clientID[] = "42032f70-20e7-11e9-a056-c5cffe7f75f9";


unsigned long lastMillis = 0;
const int equipo=0;
float Prueba_fun= 0;

void setup() {

  pinMode(equipo,OUTPUT);
  
	Serial.begin(9600);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  
}

void loop() {
	Cayenne.loop();

	//Publish data every 10 seconds (10000 milliseconds). Change this value to publish at a different interval.
	if (millis() - lastMillis > 10000) {
		lastMillis = millis();
		//Write data to Cayenne here. This example just sends the current uptime in milliseconds.
		Cayenne.virtualWrite(0, Prueba_fun);
		Prueba_fun= Prueba_fun+1;
   if(Prueba_fun>100){Prueba_fun=0;}
	}
}
 CAYENNE_IN(1)
 {
  int Valor_Canal_01= getValue.asInt();
  digitalWrite(equipo,Valor_Canal_01);  
 }


//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}
