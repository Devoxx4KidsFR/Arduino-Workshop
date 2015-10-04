// Programme GuirlandeFolle
// Allume les LEDs aleatroirement
 

int NOMBRE_DE_LEDS = 4;
int LIMITE = 2 << NOMBRE_DE_LEDS; 
int PIN_BASE = 14 - NOMBRE_DE_LEDS;

// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    pinMode (PIN_BASE + i, OUTPUT);     
  }
  Serial.begin(9600);
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {
  int nombre = random(LIMITE );
  
  Serial.println("N");
  Serial.println(nombre);

  afficheUnNombre(nombre);

  delay(100);
}


void afficheUnNombre(int nombre) {
  int val = nombre;
  int reste = 0;
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    reste = val % 2;
    Serial.println(reste);
    val = val >> 1;  // divise par 2
    digitalWrite(PIN_BASE + i, reste * HIGH);
  }  
}

