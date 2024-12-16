#include <Servo.h>

Servo monservo;  // Création de l'objet Servo

const int potPin = A0; // Broche analogique utilisée pour lire la valeur du potentiomètre

void setup() {
  monservo.attach(9); // Attache le servo à la broche numérique 9
}

void loop() {
  int potValue = analogRead(potPin); // Lire la valeur du potentiomètre (0-1023)
  int angle = map(potValue, 0, 1023, 0, 180); // Convertir la valeur du potentiomètre en une plage de 0 à 180 degrés
  monservo.write(0); // Déplacer le servo à l'angle calculé
  delay(15); // Petit délai pour assurer la stabilité du mouvement du servo
}
