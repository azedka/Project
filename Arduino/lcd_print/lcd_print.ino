#include <LiquidCrystal.h>

// Initialisation de la bibliothèque avec les numéros de broches corrects
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Configurer l'écran LCD avec 16 colonnes et 2 lignes
  lcd.begin(16, 2);

  // Afficher le texte complet
  lcd.print("bonjour tout le monde");
}

void loop() {
  // Faire défiler le texte vers la gauche
  lcd.scrollDisplayLeft();
  delay(300); // Attendre 300 millisecondes entre chaque défilement
}
