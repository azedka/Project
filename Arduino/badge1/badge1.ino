#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Initialisation du bus SPI
  rfid.PCD_Init(); // Initialisation du module RFID
  Serial.println("RFID Reader Initialized");
}

void loop() {
  // Rechercher une nouvelle carte RFID
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Sélectionner une carte RFID
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Afficher l'UID de la carte RFID
  Serial.print("UID tag: ");
  String content = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  Serial.println(content);
  
  // Délai avant de lire une nouvelle carte
  delay(1000);
}
