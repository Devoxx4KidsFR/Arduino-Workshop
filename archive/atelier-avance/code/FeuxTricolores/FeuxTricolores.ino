// Programme Clignote
// Allume la LED pendant 1 seconde, puis l'eteint 1 seconde, et recommence.
// Ce qui commence par // est un commentaire, l'Arduino ne l'execute pas
 
int ROUGE = 11;
int ORANGE= 12;
int VERT = 13;

long dernierTemps = 0;
long periode = 1000;
int ledOn = 0;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  pinMode (ROUGE, OUTPUT);     
  pinMode (ORANGE, OUTPUT);     
  pinMode (VERT, OUTPUT);     
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {
  
 

  //unsigned long maintenant = millis();
  //if(maintenant - dernierTemps > periode) {
  //  dernierTemps = maintenant;   
  //  ledOn = (ledOn + 1) % 3;
    digitalWrite(ROUGE,  LOW); // 0==ledOn);
    digitalWrite(ORANGE, LOW); // 1==ledOn);
    digitalWrite(VERT, HIGH); //2==ledOn);
  //}
  
  delay(1000);

    digitalWrite(ROUGE,  LOW); // 0==ledOn);
    digitalWrite(VERT, LOW); //2==ledOn);
    digitalWrite(ORANGE, HIGH); // 1==ledOn);
  
  delay(1000);

    digitalWrite(ORANGE, LOW); // 1==ledOn);
    digitalWrite(VERT, LOW); //2==ledOn);
    digitalWrite(ROUGE,  HIGH); // 0==ledOn);
    
  delay(1000);

}
