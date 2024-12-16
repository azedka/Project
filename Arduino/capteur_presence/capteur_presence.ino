#include <SR04.h>

#define LED 3
#define TRIG_PIN 12
#define ECHO_PIN 11
#define BUZZER 8

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

void setup() {
   Serial.begin(9600); // Démarre la communication série pour débogage
   delay(1000); // Attends 1 seconde
   pinMode(LED, OUTPUT); // Définit la pin LED comme sortie
   pinMode(BUZZER, OUTPUT); // Définit la pin buzzer comme sortie
}

void loop() {
   distance = sr04.Distance(); // Mesure la distance
   Serial.print("Distance: ");
   Serial.println(distance); // Affiche la distance dans le moniteur série

   if (distance < 130 && distance > 70) {
      digitalWrite(LED, HIGH); // Allume la LED
      tone(BUZZER, 1000); // Émet un son à 1000 Hz
      delay(1000); // Attend 3 secondes
      noTone(BUZZER); // Arrête le son
      digitalWrite(LED, LOW); // Éteint la LED
      delay(1500);
   }
   else if (distance < 70 && distance > 30) {
      digitalWrite(LED, HIGH); // Allume la LED
      tone(BUZZER, 3000); // Émet un son à 2000 Hz
      delay(500); // Attend 1 seconde
      noTone(BUZZER); // Arrête le son
      digitalWrite(LED, LOW); // Éteint la LED
      delay(500);
   }
   else if (distance < 30) {
      digitalWrite(LED, HIGH); // Allume la LED
      tone(BUZZER, 2000); // Émet un son à 3000 Hz
      delay(300); // Attend 0,5 seconde
      noTone(BUZZER); // Arrête le son
      digitalWrite(LED, LOW); // Éteint la LED
   }

   delay(100); // Petite pause pour éviter une boucle trop rapide
}
