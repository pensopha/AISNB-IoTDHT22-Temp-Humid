#include "Magellan.h"
Magellan magel;
#include <DHT.h>;

//Constants
#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
String Humidity;  //Stores humidity value
String Temperature; //Stores temperature value


char auth[]=""; 		//Token Key you can get from magellan platform

String payload;

void setup() {
  Serial.begin(9600);
  magel.begin(auth);           //init Magellan LIB
}

void loop() {

  /*
  	Example send random temperature and humidity to Magellan IoT platform
  */
   delay(2000);
    //Read data and store it to variables hum and temp
    Humidity = dht.readHumidity();
    Temperature = dht.readTemperature();
 // String Temperature=String(random(0,100));
  //String Humidity=String(random(0,100));

  payload="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+"}";       //please provide payload with json format

  magel.post(payload);                            							   //post payload data to Magellan IoT platform

  delay(10000); //Delay 2 sec.
}
