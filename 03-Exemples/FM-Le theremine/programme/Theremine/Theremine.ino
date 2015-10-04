// Ce programme code un theremine
// Le son change lorsque l'on déplace sa main pour cacher le capteur de lumiere

int PIN_BUZZER = 8;
int dureeNote = 10;

void setup() {
  // Initialise la communication. Indique la vitesse de l'echange
  Serial.begin(9600);
}

void loop() {
  // Lit la valeur sur le connecteur AO
  int lumiere = analogRead(A0);
  // on peut lire la valeur sur l'ordinateur
  Serial.println(lumiere);
  // La valeur de lumiere change selon l'endroit,  peu pres entre 400 et 1000. 
  // Nous voulons que l'instrument joue une frequence entre 132 Hz (Do2) et 990 Hz Si4) 
  // map converti les valeurs 400-1000 en valeurs 132-990
  int frequenceNote = map(lumiere, 400, 1000, 120, 990);
  // joue la note
  tone(PIN_BUZZER, frequenceNote, dureeNote);
  // une très courte pause donne un meilleur résultat
  delay(1);        
}
