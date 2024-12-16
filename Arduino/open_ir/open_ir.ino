#include <Servo.h>
#include "IRremote.h"

const int receiver = 11;

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
  servoPos = targetPos;
}


void opening() {
  switch(results.value) {
    case 0xFFA25D: 
      moveServoTo(70, stepDelay); // Déplacer le servo à 70 degrés avec une certaine vitesse
    delay(5000); // Attendre 5 secondes
    moveServoTo(180, stepDelay); // Remettre le servo en position 180 avec une certaine vitesse
    delay(1000); // Petite pause pour éviter les changements rapide
      break;
    default:
      servo.write(servoPos);
      break;
  }
}

void setup() {
  servo.attach(10);
  servo.write(servoPos);
  irrecv.enableIRIn();

}

void loop() {
  if (irrecv.decode(&results)) {
    opening();
    irrecv.resume();
  } else {
    servo.write(servoPos);
  }
delay(100);
}
