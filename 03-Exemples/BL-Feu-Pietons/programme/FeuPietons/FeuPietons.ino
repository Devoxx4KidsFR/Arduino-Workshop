/*
  fait clignoter une LED
 */


// Cette fonction est utilisee quand on demarre l'Arduino
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// cette fonction est appellee en boucle
void loop() {
  digitalWrite(13, HIGH);   // allume la LED   
  delay(1000); // attends 1 seconde  
  digitalWrite(13, LOW);  // eteint la LED
  delay(1000); // attends 1 seconde  
}


