// Programme JouerUnMorceau
// Ce programme joue une suite de notes

int PIN_BUZZER = 8;

//super mario mushroom power up
int DUREE = 34;
int notes[]= { 523, 392, 523, 659, 784, 1047, 784, 415, 523, 622, 
               831, 622, 831, 1046, 1244, 1661, 1244, 466, 587, 698, 
               932, 1195, 1397, 1865, 1397 };
int NB_NOTES = 22;


// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  int hauteur;
  for (int i=0; i<NB_NOTES; i++) {
    hauteur = notes[i];
    jouerUneNote(hauteur, DUREE);
  }
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino
void loop () {
}


void jouerUneNote(int hauteur, long duree) {
  tone(PIN_BUZZER, hauteur, duree);
  delay(duree * 1.4);
  noTone(PIN_BUZZER);
}
