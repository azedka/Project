//--------Program developed by R.Girish---------//
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000;
float R2 = 10000;
int value = 0;
void setup()
{
pinMode(analogInput, INPUT);
lcd.begin(16, 2);
lcd.print("DC VOLTMETER");
Serial.begin(9600);
}
void loop()
{
value = analogRead(analogInput);
vout = (value * 5.0) / 1024;
vin = vout / (R2/(R1+R2));
if (vin<0.10) {
vin=0.0;
}
lcd.setCursor(0, 1);
lcd.print("INPUT V= ");
lcd.print(vin);
delay(500);
}
//--------Program developed by R.Girish---------//
