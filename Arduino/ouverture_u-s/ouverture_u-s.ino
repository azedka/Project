#include <Servo.h>
#include <SR04.h>

#define TRIG_PIN 12
#define ECHO_PIN 11

Servo servo;
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

int servoPos = 180; // Position initiale du servo
int stepDelay = 5; // Délai entre les pas pour contrôler la vitesse

void setup() {
  servo.attach(10);
  servo.write(servoPos); // Mettre initialement le servo en position 180
  Serial.begin(9600);
}

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
  servoPos = targetPos;
}

void loop() {
  distance = sr04.Distance(); // Obtenir la distance mesurée par le capteur à ultrasons
  Serial.print("Distance: ");  // Afficher la distance pour debug
  Serial.println(distance);

  if (distance < 10) { // Si un objet est détecté à moins de 10 cm
    moveServoTo(70, stepDelay); // Déplacer le servo à 70 degrés avec une certaine vitesse
    delay(5000); // Attendre 5 secondes
    moveServoTo(180, stepDelay); // Remettre le servo en position 180 avec une certaine vitesse
    delay(1000); // Petite pause pour éviter les changements rapides
  }
  delay(200); // Délai pour éviter de lire trop fréquemment
}
