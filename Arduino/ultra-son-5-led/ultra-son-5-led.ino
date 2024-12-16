//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6


SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   
}

void loop() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
   if (a <= 5){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      
   }
   if (a > 5 && a <= 10){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      
   }
   if (a > 10 && a <= 15){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      
   }
   if (a > 15 && a <= 20){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      
   }
   if (a > 20 && a <= 25){
      digitalWrite(led1, HIGH);
      
   }
   delay(1000);
}
