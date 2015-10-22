/*
  Feu de circulation
  Allume le feux pietons et le feu tricolore comme un feu de circulation
 */

// ce sont des contantes du programme. La valeur ne changera pas
const byte PIETON_ROUGE = 13;
const byte PIETON_VERT = 12;
const byte VOITURE_ROUGE = 11;
const byte VOITURE_ORANGE = 10;
const byte VOITURE_VERT = 9;

const byte VOITURE = 1;
const byte TRANSITION = 2;
const byte PIETON = 3;
const byte phases[] =  { VOITURE, VOITURE, VOITURE, TRANSITION, 
                          PIETON, PIETON, PIETON };

const int DUREE = 3000; // 3 secondes
const long interval = 500; // 0,5 seconde


// ce sont des variables. Leur valeur va changer au cours du programme
unsigned long dernierTemps = 0;
int etat = LOW;
int phase = 0;

// Cette fonction est utilisee quand on demarre l'Arduino
void setup() {
  // initialise tous les pins
  for (int l=VOITURE_VERT; l<=PIETON_ROUGE; l++) {
    pinMode(l, OUTPUT);
  }
  Serial.begin(SERIAL_8N1);
}

// cette fonction est appellee en boucle
void loop() {
  // Etape 1 : Allume tout 

  changeEtatTout(HIGH);


  // Etape2 : Clignote tout
/*
  unsigned long maintenant = millis();

  if (maintenant - dernierTemps >= interval) {
    // releve le temps pour le prochain passage
    dernierTemps = maintenant;

    inverseEtat();
    changeEtatTout(etat);
  }
*/
  
  // Etape3 : 3 phases
/*
  unsigned long maintenant = millis();
  int t = round(maintenant / 1000 % 7);
  Serial.println(t, DEC);
  int phase =  phases[t];
  changeEtatTout(LOW);
  switch (phase) {
      case VOITURE: 
         digitalWrite(VOITURE_VERT, HIGH);  
         digitalWrite(PIETON_ROUGE, HIGH);  
         break;
      case TRANSITION: 
         digitalWrite(VOITURE_ORANGE, HIGH);  
         digitalWrite(PIETON_ROUGE, HIGH);  
         break;
      case PIETON: 
         digitalWrite(VOITURE_ROUGE, HIGH);  
         digitalWrite(PIETON_VERT, HIGH);  
         break;
      default: 
         changeEtatTout(HIGH); // debug
         break;
  }
*/
}

void changeEtatTout(int nouvelEtat) {
  for (int l=VOITURE_VERT; l<=PIETON_ROUGE; l++) {
    digitalWrite(l, nouvelEtat);  
  }  
}

void inverseEtat() {
    // retourne l'etat. si c'est allume, on eteint et vice-versa
    if (etat == LOW) {
      etat = HIGH;
    } else {
      etat = LOW;
    } 
}

