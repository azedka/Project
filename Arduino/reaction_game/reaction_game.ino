/* les paramètres qui peuvent être modifiés */
int d1 = 1000;   // d1 et d2 sont la plage en mlsec de l'allumage de LED
int d2 = 2000;
int d3 = 3000;   // après combien de mlsec l'erreur sera effacée
byte tarrgr = 10; // nombre de tentatives
byte knp = 3;    // nombre de paires LED / bouton
/* les paramètres qui peuvent être modifiés */
 
byte pinD = 4 + knp;
byte pinA = 14 + knp;
byte ext = 9;
byte hit;
byte err;
byte tarrgn;
boolean finich = true;

unsigned long timing;
unsigned long setreakt;
unsigned long bestreakt = 99999;
unsigned long medreakt;

void setup() {
   Serial.begin(9600);
   for (byte i = 4; i < pinD; i++) { pinMode(i, OUTPUT); digitalWrite(i, HIGH); }
   delay(500); 
   for (byte i = 4; i < pinD; i++) { digitalWrite(i, LOW); }
   for (byte i = 14; i < pinA; i++) { pinMode(i, INPUT); }
   for (byte i = 14; i < pinA; i++) { analogWrite(i, LOW); }
}

void loop() {
   while (tarrgn < tarrgr) {
    
      int LED = random(4, 4 + knp);
      int BTN = LED + 10;

      int DEL = random(d1, d2);
      delay(DEL);
      digitalWrite(LED, HIGH);
      timing = millis();

      ext = 9;

      while (ext < 10 && tarrgn < tarrgr) {

         if (digitalRead(BTN) == HIGH) {
            digitalWrite(LED, LOW);
            setreakt = millis() - timing;
            delay(300); hit++; tarrgn++; ext = 11;
         }

         if (millis() - timing > d3) {
            digitalWrite(LED, LOW);
            delay(300); setreakt = 0; err++; tarrgn++; ext = 11;
         }
      }

    if (setreakt < bestreakt && setreakt > 100) { bestreakt = setreakt; }
    medreakt = medreakt + setreakt;
  }

    if (tarrgn == tarrgr && finich == true) {
       medreakt = medreakt / hit;
       if (medreakt > 99998) { medreakt = 0; }
       if (bestreakt > 99998) { bestreakt = 0; }

       Serial.println();
       Serial.println("--- End of Raund ---");
       Serial.println();
       Serial.println("Coups - " + String(hit));
       Serial.println("Erreurs - " + String(err));
       Serial.println("La meilleure reaction - " + String(bestreakt));
       Serial.println("Le moyenne reaction - " + String(medreakt));
       Serial.println();
       Serial.println("Please reboot for restart");
       finich = false;
  }
}
