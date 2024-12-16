#define pin1 5
#define pin2 6
#define pin3 7



void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

}

void loop() {
  digitalWrite(pin1, HIGH);
  delay(3000);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(300);
  digitalWrite(pin2, LOW);
  delay(300);
  digitalWrite(pin2, HIGH);
  delay(300);
  digitalWrite(pin2, LOW);
  delay(300);
  digitalWrite(pin2, HIGH);
  delay(300);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  delay(3000);
  digitalWrite(pin3, LOW);
  
  

}
