// Programme GuirlandeFolle
// Allume les LEDs aleatroirement
 

byte NOMBRE_DE_LEDS = 4;
byte PIN_BASE = 14 - NOMBRE_DE_LEDS;
byte SEQUENCE[] = { 3, 0, 12, 0 };
byte longueurSequence = sizeof(SEQUENCE)/sizeof(byte);
byte pos = 0;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    pinMode (PIN_BASE + i, OUTPUT);     
  }
  Serial.begin(9600);
  Serial.print("Longueur spquence:");
  Serial.println(longueurSequence);
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {
  afficheUnNombre(SEQUENCE[pos]);  
  delay(500);
  pos = ((pos + 1) % longueurSequence);
  Serial.println(pos);
}


void afficheUnNombre(int unNombre) {
  Serial.print(unNombre, DEC);
  Serial.print("->");
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    byte bit = bitRead(unNombre, i);
    Serial.print(bit);
    digitalWrite(PIN_BASE + i, bit * HIGH);
  }  
  Serial.print('\n'); // avoir une nouvelle ligne
}
