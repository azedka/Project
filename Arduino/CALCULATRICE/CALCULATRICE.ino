#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); // Initialisation de l'écran LCD
// Variable pour récupérer les deux chiffres et le calcul fait
long premier_chiffre = 0; 
long second_chiffre = 0;
double calcul_total = 0;
// On indique la taille du digicode
char digicode_modifie;
const byte Lignes = 4;
const byte Colonnes = 4;
// On initialise le nombre de touche disponible sur le digicode
char Touches[Lignes][Colonnes] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte Ligne_pins[Lignes] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte Colonne_pins[Colonnes] = {3,2,1,0}; //connect to the column pinouts of the keypad


Keypad customKeypad= Keypad( makeKeymap(Touches), Ligne_pins, Colonne_pins, Lignes, Colonnes); 

void setup()
{
lcd.begin(16, 2);               //On démarre l'écran LCD
for(int i=0;i<=3;i++);
lcd.setCursor(0,0);            // On déplace le curseur au début de l'écran
  lcd.print("Calculatrice");
  lcd.setCursor(0,1);
  lcd.print("Arduino Factory");
delay(4000);
lcd.clear(); // On efface l'écran LCD
lcd.setCursor(0, 0);
}


void loop()
{

  digicode_modifie = customKeypad.getKey();
  switch(digicode_modifie) 
  {
  case '0' ... '9': //  Ceci permet de garder le premier chiffre tant que vous n'avez pas appuyez sur "+-*/"
    lcd.setCursor(0,0);
    premier_chiffre = premier_chiffre * 10 + (digicode_modifie - '0');
    lcd.print(premier_chiffre);
    break;

  case '+': // Pour calculer les additions 
    premier_chiffre = (calcul_total != 0 ? calcul_total : premier_chiffre);
    lcd.setCursor(0,1);
    lcd.print("+");
    second_chiffre = second_chiffre_nombre(); // On récupère le deuxième chiffre 
    calcul_total = premier_chiffre + second_chiffre;
    lcd.setCursor(0,3);
    lcd.print(calcul_total);
    premier_chiffre = 0, second_chiffre = 0; // On reintialise les valeurs à 0 pour une prochaine utilisation
    break;

  case '-': // Pour calculer les soustractions
    premier_chiffre = (calcul_total != 0 ? calcul_total : premier_chiffre);
    lcd.setCursor(0,1);
    lcd.print("-");
    second_chiffre = second_chiffre_nombre();// On récupère le deuxième chiffre 
    calcul_total = premier_chiffre - second_chiffre;
    lcd.setCursor(0,3);
    lcd.print(calcul_total);
    premier_chiffre = 0, second_chiffre = 0; // On reintialise les valeurs à 0 pour une prochaine utilisation
    break;

  case '*': // Pour calculer les multiplications
    premier_chiffre = (calcul_total != 0 ? calcul_total : premier_chiffre);
    lcd.setCursor(0,1);
    lcd.print("*");
    second_chiffre = second_chiffre_nombre();// On récupère le deuxième chiffre 
    calcul_total = premier_chiffre * second_chiffre;
    lcd.setCursor(0,3);
    lcd.print(calcul_total);
    premier_chiffre = 0, second_chiffre = 0; // On reintialise les valeurs à 0 pour une prochaine utilisation
    break;

  case '/': // Pour calculer les divisions
    premier_chiffre = (calcul_total != 0 ? calcul_total : premier_chiffre);
    lcd.setCursor(0,1);
    lcd.print("/");
    second_chiffre = second_chiffre_nombre();// On récupère le deuxième chiffre 
    lcd.setCursor(0,3);

    second_chiffre == 0 ? lcd.print("Invalid") : calcul_total = (float)premier_chiffre / (float)second_chiffre;

    lcd.print(calcul_total);
    premier_chiffre = 0, second_chiffre = 0; // On reintialise les valeurs à 0 pour une prochaine utilisation
    break;

  case 'C': // Permet de réintialiser la calulatrice
    calcul_total = 0;
    lcd.clear();
    break;
  }
}

long second_chiffre_nombre() // Permet de garder le second chiffre en mémoire 
{
  while( 1 )
  {
    digicode_modifie = customKeypad.getKey();
    if(digicode_modifie >= '0' && digicode_modifie <= '9')
    {
      second_chiffre = second_chiffre * 10 + (digicode_modifie - '0');
      lcd.setCursor(0,2);
      lcd.print(second_chiffre);
    }

    if(digicode_modifie == '=') break;  //return second_chiffre;
  }
 return second_chiffre; 
}
