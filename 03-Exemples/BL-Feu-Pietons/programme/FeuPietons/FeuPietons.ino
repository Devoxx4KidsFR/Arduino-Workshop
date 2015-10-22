/*
  Feu pietons
  Allume alernativement la LED rouge et la LED verte
 */

int LED_ROUGE = 13;
int LED_VERTE = 12;
int DUREE = 3000; // 3 secondes

// Cette fonction est utilisee quand on demarre l'Arduino
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_VERTE, OUTPUT);
}

// cette fonction est appellee en boucle
void loop() {
  digitalWrite(LED_ROUGE, HIGH);   // allume la LED rouge 
  digitalWrite(LED_VERTE, LOW);   // eteint la LED verte  
  delay(DUREE); // attends     
  digitalWrite(LED_ROUGE, LOW);   // eteint la LED rouge 
  digitalWrite(LED_VERTE, HIGH);   // allume la LED verte  
  delay(DUREE); // attends 1 seconde  
}


