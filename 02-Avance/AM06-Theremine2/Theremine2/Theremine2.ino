// Ce programme code un theremine
// Le son change lorsque l'on déplace sa main pour cacher le capteur de lumiere

int PIN_BUZZER = 8;
int dureeNote = 10;

void setup() {
  // Initialise la communication. Indique la vitesse de l'echange
  Serial.begin(9600);
}

void loop() {
  int input = analogRead(A0); // photoresistance
  //int input = analogRead(A1); // potentionmetre
  int frequenceNote = map(input, 0, 1000, 0, 1000);
  Serial.write(frequenceNote);
  delay(1);        
}
