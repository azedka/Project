#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>



#define SS_PIN 10
#define RST_PIN 9
#define LED1 3
#define LED2 2
#define son 4
MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo; 

void setup() {
  Serial.begin(9600);
  SPI.begin();      
  rfid.PCD_Init();  
  Serial.println("RFID Reader Initialized");
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(son, OUTPUT);
  servo.attach(6);
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  Serial.println("Card detected");

  // Check the UID of the card
  byte uid[] = {0xC1, 0xC1, 0xD7, 0x00};
  bool match = true;
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] != uid[i]) {
      match = false;
      break;
    }
  }

  if (match) {
    // If the UID matches, perform this action
    Serial.println("UID matched: C1 C1 D7 00");
      digitalWrite(LED1, HIGH); 
      digitalWrite(son, HIGH); 
      servo.write(90); 
      delay(500);              
      digitalWrite(LED1, LOW);  
      digitalWrite(son, LOW); 
      delay(500);
      servo.write(180);
  } else {
    // If the UID does not match, perform this action
    Serial.print("UID did not match: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();
      
      digitalWrite(LED2, HIGH);
      digitalWrite(son, HIGH);  
      delay(500);              
      digitalWrite(LED2, LOW); 
      digitalWrite(son, LOW);  
      delay(500);
  }

  // Halt PICC
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(1000); // Wait a bit before looking for a new card
}
