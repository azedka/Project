#define led 3

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // Augmenter la luminosité de 0 à 255
  for (int i = 0; i < 255; i++) {
    analogWrite(led, i);
    delay(20);
  }
  
  // Diminuer la luminosité de 255 à 0
  for (int i = 255; i >= 0; i--) {
    analogWrite(led, i);
    delay(20);
  }
}
