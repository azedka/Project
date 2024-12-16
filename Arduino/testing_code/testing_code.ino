void setup() {
  Serial.begin(9600); // On initalise le moniteur série
}

void func(){
  
  }

void loop() {
  int a;
  a=random(1,6); // On créer un nmbre aléaoire entre 1 et 100
  if (a==1){
    
    Serial.println("*");
    
    }

else if (a==2){
  
  Serial.println("*");
  Serial.println("");
  Serial.println("    *");
  }

else if (a==3){
  
  Serial.println("*");
  Serial.println("  *");
  Serial.println("     *");
  }
else if (a==4){
  
  Serial.println("*    *");
  Serial.println("");
  Serial.println("*    *");
  }
else if (a==5){
  
  Serial.println("*    *");
  Serial.println("  *");
  Serial.println("*    *");
  }
else if (a==6){
  
  Serial.println("*    *");
  Serial.println("*    *");
  Serial.println("*    *");
  }
  delay(10000);
}
