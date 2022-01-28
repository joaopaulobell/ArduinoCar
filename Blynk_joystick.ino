/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  You can receive x and y coords for joystick movement within App.

  App project setup:
    Two Axis Joystick on V1 in MERGE output mode.
    MERGE mode means device will receive both x and y within 1 message
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
int frente = 0;
int atras = 2;
int dir = 5;
int esq = 4;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "87ac6149dae949d6b321457571f9a543";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Imperatus";
char pass[] = "Nescau15";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(dir,OUTPUT);
  pinMode(esq,OUTPUT);
  pinMode(frente,OUTPUT);
  pinMode(atras,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

BLYNK_WRITE(V1){
    int a=param.asInt();
    if (a>0){digitalWrite(esq,1);}
    else if (a<0){digitalWrite(dir,1);}
    else {digitalWrite(esq,0);digitalWrite(dir,0);}}
  
  BLYNK_WRITE(V2){
   int a=param.asInt();
    if (a>0){digitalWrite(frente,1);}
    else if (a<0){digitalWrite(atras,1);}
   else {digitalWrite(frente,0);digitalWrite(atras,0);}}

BLYNK_WRITE(V3){
   int a=param.asInt();
   if (a==1) {
    digitalWrite(frente,1);
    digitalWrite(dir,1);
    delay(3000);
    a=a+1;
   }}
BLYNK_WRITE(V4){
   int a=param.asInt();
   if (a==1) {
    digitalWrite(frente,1);
    delay(8000);
    digitalWrite(dir,1);
    delay(800);
    digitalWrite(esq,1);
    digitalWrite(atras,1);
   delay(300);
    a=a+1;
   }}
BLYNK_WRITE(V5){
   int a=param.asInt();
if (a==1) {
    digitalWrite(frente,1);
    delay(8000);}
}

BLYNK_WRITE(V6){
   int a=param.asInt();
if (a==1) {
    digitalWrite(atras,1);
    delay(8000);}
}

BLYNK_WRITE(V7){
   int a=param.asInt();
   if (a==1) {
    digitalWrite(frente,1);
    digitalWrite(esq,1);
    delay(3000);
    a=a+1;
   }}

   
BLYNK_WRITE(V8){
   int a=param.asInt();
   if (a==1) {
    digitalWrite(atras,1);
    digitalWrite(dir,1);
    delay(3000);
    a=a+1;
   }}

BLYNK_WRITE(V9){
   int a=param.asInt();
   if (a==1) {
    digitalWrite(atras,1);
    digitalWrite(esq,1);
    delay(3000);
    a=a+1;
   }}




void loop()
{
  Blynk.run();
}
