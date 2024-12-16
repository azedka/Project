#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();      
  rfid.PCD_Init();  
  Serial.println("RFID Reader Initialized");

  // Prepare the key (this is the default key for MIFARE)
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  Serial.println("Card detected");

  // Authenticate with the card
  byte block = 4; // Block to write to
  byte data1[] = {0xA4, 0x8E, 0xA3, 0x22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Data to write (fill the rest with 0s)
  byte data2[] = {164, 142, 163, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Data to write (fill the rest with 0s)

  MFRC522::StatusCode status;

  // Authenticate using key A
  status = rfid.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rfid.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Authentication failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  // Write data1 to the block
  status = rfid.MIFARE_Write(block, data1, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Write failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }
  Serial.println("Data1 written to block 4");

  // (Optional) Write data2 to a different block if required
  block = 5;
  status = rfid.MIFARE_Write(block, data2, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Write failed: ");
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }
  Serial.println("Data2 written to block 5");

  // Halt PICC
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(1000); // Wait a bit before looking for a new card
}
