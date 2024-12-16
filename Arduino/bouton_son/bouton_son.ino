#include "IRremote.h"

const int receiver = 11; // Pin où est connecté le récepteur IR
const int son = 7; // Pin où est connecté le buzzer

IRrecv irrecv(receiver); // Créer une instance de 'irrecv'
decode_results results; // Créer une instance de 'decode_results'

void setup() {
  Serial.begin(9600);
  pinMode(son, OUTPUT); // Définir la pin du buzzer comme sortie
  irrecv.enableIRIn(); // Initialiser le récepteur IR
}

void loop() {
  if (irrecv.decode(&results)) { // A-t-on reçu un signal IR ?
    Serial.println("Signal IR reçu"); // Afficher un message pour indiquer qu'un signal a été reçu
    digitalWrite(son, HIGH); // Activer le buzzer
    delay(500); // Jouer le son pendant 500 ms
    digitalWrite(son, LOW); // Désactiver le buzzer
    irrecv.resume(); // Recevoir la prochaine valeur
  } else {
    digitalWrite(son, LOW); // Assurer que le buzzer est éteint si aucun signal n'est reçu
  }
}
