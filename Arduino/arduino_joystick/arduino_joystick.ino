
const int X_pin = A0; // Broche analogique connectée à la sortie X du joystick
#define led 3


void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int x_value = analogRead(X_pin); // Lire la valeur du capteur sur la broche A0

  int a = map(x_value, 0, 1023, 0, 255);
  analogWrite(led, a);
  
 192.168.4.1,
}
