/*
 * made by technvation
 * uses open source blynk app to send data over the interent
 * This example code is in public domain.
 * feel free to modify, change, improve
 */
#define BLYNK_PRINT Serial
//#include <Ultrasonic.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6925a55bc9ad4c2196cc1ed3740fd602";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Deskto";
char pass[] = "123456789";

const int trigPin = D0;
const int echoPin = D1;

long duration;
int distance;

BlynkTimer timer;
//int distance = 0;
int thresh[3] = {25, 50, 75};
//Ultrasonic ultrasonic(12, 13);

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3);



void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{

   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);
  Serial.println(distance);
 // distance = ultrasonic.distanceRead();
  Serial.println(distance);
  Blynk.run();

  if(distance<thresh[0]){   //25
    green.on();
    }
  else if(distance<thresh[1]){    //50
    green.on();
    orange.on();
  }
  else if(distance<thresh[2]){ //75
    green.on();
    orange.on();
    red.on();
  }
  else {
    green.off();
    orange.off();
    red.off();
  }
  delay(1000);
}
