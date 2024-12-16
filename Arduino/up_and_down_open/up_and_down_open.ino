#include <Servo.h>
#include "IRremote.h"

const int receiver = 11; // Pin où est connecté le récepteur IR

Servo servo;
IRrecv irrecv(receiver);
decode_results results;

int servoPos = 180;
int stepDelay = 5; // Délai entre les pas pour contrôler la vitesse

void moveServoTo(int targetPos, int stepDelay) {
  if (targetPos > servoPos) {
    for (int pos = servoPos; pos <= targetPos; pos++) {
      servo.write(pos);
      delay(stepDelay);
    }
  } else {
    for (int pos = servoPos; pos >= targetPos; pos--) {
      servo.write(pos);
      delay(stepDelay);
    }
  }
  servoPos = targetPos; // Mettre à jour la position actuelle du servo
}

void opening1() {
  moveServoTo(70, stepDelay); // Déplacer le servo à 70 degrés avec une certaine vitesse
  delay(1000); // Petite pause pour éviter les changements rapides
}

void opening2() {
  moveServoTo(180, stepDelay); // Déplacer le servo à 180 degrés avec une certaine vitesse
  delay(1000); // Petite pause pour éviter les changements rapides
}

void setup() {
  servo.attach(10);
  servo.write(servoPos);
  irrecv.enableIRIn();
  Serial.begin(9600); // Initialiser la communication série pour le débogage
}

void loop() {
  if (irrecv.decode(&results)) { // Vérifier si un signal IR est reçu
    Serial.print("IR Code: "); // Déboguer le code IR reçu
    Serial.println(results.value, HEX); // Afficher le code IR en hexadécimal
    if (results.value == 0xFFA25D) { // Remplacer par le code IR spécifique pour la première fonction
      opening1();
    } else if (results.value == 0xFF629D) { // Remplacer par le code IR spécifique pour la deuxième fonction
      opening2();
    }
    irrecv.resume(); // Recevoir la prochaine valeur
  } else {
    servo.write(servoPos); // Garder le servo à la position actuelle
  }
  delay(100); // Délai pour éviter de lire trop fréquemment
}
