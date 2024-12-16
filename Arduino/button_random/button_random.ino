#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define button 10
int a;

void setup() {
  //Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(button, INPUT_PULLUP); // Utilisation d'une résistance interne pull-up pour éviter les flottements
  
}

void func() {
  // Éteindre toutes les LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  
  a = random(1, 7); // On crée un nombre aléatoire entre 1 et 6
  /*Serial.print(a);
  Serial.print("\n");*/


  // Activer les LEDs en fonction de la valeur de 'a'
  if (a == 1) {
    digitalWrite(led1, HIGH);
  }
  else if (a == 2) {
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if (a == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led5, HIGH);
  }
  else if (a == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (a == 5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  else if (a == 6) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  
  delay(1000); // Attendre 2 secondes avant d'éteindre ou de changer
  
}

void loop() {
  int buttonState = digitalRead(button); // Lire l'état du bouton
  
  if (buttonState == LOW) { // Si le bouton est appuyé (LOW)
    func(); // Appeler la fonction func()
  }
}
