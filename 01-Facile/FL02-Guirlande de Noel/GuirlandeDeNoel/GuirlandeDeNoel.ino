// Programme GuirlandeDeNoel
// Allume les LED  tour de role.
 

int NOMBRE_DE_LEDS = 4;
int PIN_BASE = 10;
int decalage = 0;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    pinMode (PIN_BASE + i, OUTPUT);     
  }
  Serial.begin(9600);
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {
  digitalWrite(PIN_BASE + decalage,  LOW); // eteint
  
  decalage = ((decalage + 1) % NOMBRE_DE_LEDS);
  Serial.println("Decalage");
  Serial.println(decalage);
  
  digitalWrite(PIN_BASE + decalage,  HIGH); // allume
  
  delay(100);
}

