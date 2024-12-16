// Broche où le buzzer est connecté
const int buzzerPin = 8;

// Mélodie simplifiée de "Mission: Impossible" (fréquences des notes en Hz)
int melody[] = {
  330, 330, 392, 392, 415, 415, 370, 370, // Riff principal (da-da, da-da)
  330, 330, 392, 392, 415, 415, 370, 370, // Riff principal répété
  370, 370, 415, 370, 392, 330, // Variation descendante
  370, 370, 415, 370, 392, 330  // Variation descendante répétée
};

// Durées des notes (en millisecondes)
int noteDurations[] = {
  150, 150, 150, 150, 150, 150, 150, 150, // Riff principal
  150, 150, 150, 150, 150, 150, 150, 150, // Riff principal répété
  150, 150, 150, 150, 300, 300,           // Variation descendante
  150, 150, 150, 150, 300, 300            // Variation descendante répétée
};

void setup() {
  // Aucun setup nécessaire pour le buzzer
}

void loop() {
  // Jouer la mélodie de "Mission: Impossible"
  int melodyLength = sizeof(melody) / sizeof(melody[0]); // Nombre total de notes

  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    // Calculer la durée de la note
    int noteDuration = noteDurations[thisNote];
    // Jouer la note
    tone(buzzerPin, melody[thisNote], noteDuration);
    
    // Attendre la fin de la note + une courte pause entre les notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Arrêter la note (silence entre les notes)
    noTone(buzzerPin);
  }
  
  // Pause avant de rejouer la mélodie
  delay(2000);
}
