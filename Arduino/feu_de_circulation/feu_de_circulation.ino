
#define LED1 11
#define LED2 10
#define LED3 8

void setup() {  

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}
void loop() {
   digitalWrite(LED1, HIGH);
   delay(5000);
   digitalWrite(LED1, LOW);
   
   for (int i = 0; i < 3; i++) {
    digitalWrite(LED2, HIGH);
    delay(150);
    digitalWrite(LED2, LOW);
    delay(150);
  }
  
   digitalWrite(LED3, HIGH);
   delay(5000);
   digitalWrite(LED3, LOW);
 
   
}
