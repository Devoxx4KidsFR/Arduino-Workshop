// Programme Univac
// Compte en base 2 et allume les LED correspondantes
 

byte NOMBRE_DE_LEDS = 4;
byte PIN_BASE = 10;
byte octet = 1;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  for (byte i=0; i<NOMBRE_DE_LEDS; i++) {
    pinMode (PIN_BASE + i, OUTPUT);     
  }
  Serial.begin(9600);
  
  Serial.print("Demarrage: ");
  Serial.println(octet, DEC);
  afficheUnNombre(octet); // indique un nombre entre 0 et 15
} 

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {

    // send data only when you receive data:
    if (Serial.available() > 0) {
            // read the incoming byte:
            octet = Serial.read();

            // say what you got:
            Serial.print("Entree: ");
            Serial.println(octet, DEC);
            afficheUnNombre(octet); 
    }
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

