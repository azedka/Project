int latchPin = 5; // Broche de bascule du 74HC595
int clockPin = 6; // Broche d'horloge du 74HC595
int dataPin = 7;  // Broche Data du 74HC595

byte leds = 0;    

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0; // initialise l'état des led à 0 donc éteinte
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++) // allume les led une par une
  {
    bitSet(leds, i);    // initialise le bit qui controle la led
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
