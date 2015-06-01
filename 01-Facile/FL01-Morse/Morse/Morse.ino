/*
  Morse
  send SOS over oand over. wait 20s btween each SOS.
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  signalS();          
  signalO();          
  signalS();          
  attend(20);
}

void signalS() {
  signalCourt();
  signalCourt();
  signalCourt();
}

void signalO() {
  signalLong();
  signalLong();
  signalLong();
}

void signalCourt() {
  allumeLED();
  attend(1);
  eteintLED(); 
  attend(1);
}

void signalLong() {
  allumeLED();
  attend(3);
  eteintLED(); 
  attend(1);
}

void allumeLED() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void eteintLED() {
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
}

void attend(int tempsEnSecondes) {
  delay(tempsEnSecondes * 1000);    // attends le nombre de secondes demandees
}

