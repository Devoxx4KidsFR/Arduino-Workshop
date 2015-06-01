// Programme JouerUneNote
// Ce programme joue une note

int PIN_BUZZER = 8;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {                
  int hauteur = 440;
  tone(PIN_BUZZER, hauteur, 1000L);
  delay(1000);               
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino
void loop () {
}

