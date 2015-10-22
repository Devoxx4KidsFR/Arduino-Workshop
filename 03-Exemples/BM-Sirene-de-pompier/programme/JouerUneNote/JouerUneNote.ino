// Programme JouerUneNote
// Ce programme joue une note

int PIN_BUZZER = 8;
const int DUREE = 500;
const int DUREE_PAUSE = 0;

const float DO = 261.625;
const float RE = 293.664;
const float MI = 329.627;
const float FA = 349.228;
const float SOL = 391.995;
const float LA = 440.000;
const float SI = 493.883;

const float samu[] = { LA, FA };
const float police[] = { LA, RE };
const float pompiers[] = { LA, SI };
const float ambulance[] = { LA, SOL, LA, 0 };


// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {                
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino
void loop () {
  /*
  // 
  tone(PIN_BUZZER, LA, DUREE);
  delay(DUREE);               
  tone(PIN_BUZZER, SI, DUREE);
  delay(DUREE);               
  */
  
  // meme code en tableau
  for (int i=0; i<2; i++) {
    tone(PIN_BUZZER, pompiers[i], DUREE);
    delay(DUREE);               
  }
}

