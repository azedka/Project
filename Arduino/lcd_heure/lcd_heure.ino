#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

// Initialisation du module DS3231
DS3231 clock;
RTCDateTime dt;

// Initialisation de l'écran LCD (les broches peuvent varier selon le modèle)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600); // Initialise la communication série
  lcd.begin(16, 2);   // Initialise l'écran LCD avec 16 colonnes et 2 rangées

  Serial.println("Initializing DS3231...");

  // Initialise le module DS3231
  clock.begin();

  // Si vous avez besoin de définir la date et l'heure, décommentez la ligne ci-dessous et mettez la date et l'heure actuelles
  // clock.setDateTime(2024, 7, 27, 15, 30, 0);

  // Définir la date et l'heure à la date et l'heure de compilation du sketch
  clock.setDateTime(__DATE__, __TIME__);  

  // Afficher un message de confirmation sur le LCD
  lcd.setCursor(0, 0);
  lcd.print("DS3231 Initialized");
  delay(2000); // Attendre 2 secondes pour lire le message
}

void loop() {
  // Lire l'heure actuelle du module DS3231
  dt = clock.getDateTime();

  // Effacer l'écran LCD
  lcd.clear();

  // Afficher la date et l'heure sur l'écran LCD
  lcd.setCursor(0, 0); // Positionne le curseur en haut à gauche
  lcd.print(dt.month);
  lcd.print("-");
  lcd.print(dt.day);
  
  lcd.setCursor(0, 1); // Positionne le curseur en bas à gauche
  lcd.print(dt.hour);
  lcd.print(":");
  lcd.print(dt.minute);
  lcd.print(":");
  lcd.print(dt.second);

  // Afficher l'heure sur le moniteur série pour vérification
  Serial.print(dt.month);  
  Serial.print("-");
  Serial.print(dt.day);    
  Serial.print(" ");
  Serial.print(dt.hour);   
  Serial.print(":");
  Serial.print(dt.minute); 
  Serial.print(":");
  Serial.print(dt.second); 
  Serial.println("");

  // Attendre 1 seconde avant de mettre à jour l'affichage
  delay(1000);
}
 
