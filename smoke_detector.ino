//#include <Simpletimer.h>
//
//#include <SimpleTimer.h>

//#include <Simpletimer.h>

#include <SimpleTimer.h>



#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

 
#define BLYNK_TEMPLATE_ID "TMPLYavPbr4M"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gO972g9igJhqEvKL4D5D3ID3jrYZgVso"
char auth[] = BLYNK_AUTH_TOKEN ; //Enter Authentication code sent by Blynk
char ssid[] = "Lucky"; //Enter WIFI Name
char pass[] = "@lucky123@"; //Enter WIFI Password
 
SimpleTimer timer;
 
int mq2 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
void getSendData()
{
data = analogRead(mq2); 
  Blynk.virtualWrite(V0, data);
 
  if (data > 700 )
  {
    Blynk.notify("Smoke Detected!"); 
  }
 
}
