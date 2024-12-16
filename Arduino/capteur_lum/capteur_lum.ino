int co = A0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int lum = analogRead(co);
  Serial.println(lum);
  delay(500);

}
