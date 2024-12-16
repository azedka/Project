const int potPin = A0; // Broche du potentiomètre
const int motorPin = 9; // Broche du moteur

void setup() {
  pinMode(motorPin, OUTPUT); // Définir la broche du moteur comme sortie
}

void loop() {
  int potValue = analogRead(potPin); // Lire la valeur du potentiomètre (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 0, 255); // Convertir en valeur PWM (0-255)

  analogWrite(motorPin, motorSpeed); // Contrôler la vitesse du moteur
}
