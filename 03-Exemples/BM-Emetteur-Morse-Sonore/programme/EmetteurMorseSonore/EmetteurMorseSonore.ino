// Ce programme code un emetteur morse sonore
// Le buzzer joue lorsqu'on appuie sur le bouton

int PIN_BOUTON = 2;
int PIN_BUZZER = 8;
int PIN_LED = 13;
int LA = 440;
int DUREE = 200; // 0,5 seconde

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  int etatBouton = digitalRead(PIN_BOUTON);
  digitalWrite(PIN_LED, !etatBouton);    
  if (etatBouton == LOW) {
    tone(PIN_BUZZER, LA, DUREE);
    delay(DUREE);               
  }
    
}
