// Programme Guirlande
// Allume les LEDs 
// S en sequence
// A aleatroirement
// P avec un pattern

int iMode = 0;
char MODES[] = { 'S', 'A', 'C', 'P' };
char mode = 'S';
byte octet = 1;
unsigned long lastSwitch = millis();

byte NOMBRE_DE_LEDS = 10;
byte PIN_BASE = 14 - NOMBRE_DE_LEDS;
byte IN1 = 2;

// mode Sequence
byte decalage = 0;

// mode Aleatoire
long LIMITE = 2 << NOMBRE_DE_LEDS; 

// mode Chenille

// mode Pattern
byte pos = 0;
int SEQUENCE[] = { 1+(2<<8), (2<<0)+(2<<7),  (2<<1)+(2<<6), (2<<2)+(2<<5), 
     (2<<3)+(2<<4), (2<<3)+(2<<4), (2<<2)+(2<<5),  (2<<1)+(2<<6), 
     (2<<0)+(2<<7), 1+(2<<8),  0, 1+(2<<8), 0, 1+(2<<8), 0};
/*
int SEQUENCE[] = { 1, (2<<0),  (2<<1), (2<<2), 
     (2<<3), (2<<4), (2<<5), (2<<6), 
     (2<<7), (2<<8), 0 };
*/
byte longueurSequence = sizeof(SEQUENCE)/sizeof(int);


// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {    
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    pinMode (PIN_BASE + i, OUTPUT);     
  }
  Serial.begin(9600);
  Serial.print("Longueur sequence:");
  Serial.println(longueurSequence);
  pinMode(IN1, INPUT);    // declare pushbutton as input
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino

void loop() {
  checkMode();
  checkPush();
  if (mode == 'S') {
    digitalWrite(PIN_BASE + decalage,  LOW); // eteint
    decalage = ((decalage + 1) % NOMBRE_DE_LEDS);
    digitalWrite(PIN_BASE + decalage,  HIGH); // allume
    delay(100);
  } else if (mode == 'A') {
    long nombre = random(LIMITE );
    afficheUnNombre(nombre);
    delay(500);
  } else if (mode == 'C') {
    decalage = ((decalage + 1) % NOMBRE_DE_LEDS);
    long nombre = calculeChenille(decalage);
    afficheUnNombre(nombre);  
    delay(100);
  } else {
    //Serial.print("Sequence Pos=");
    //Serial.print(pos);
    //Serial.print(" , Val=");
    //Serial.println(SEQUENCE[pos]);
    afficheUnNombre(SEQUENCE[pos]);  
    delay(100);
    pos = ((pos + 1) % longueurSequence);
  }
}


void afficheUnNombre(int unNombre) {
  //Serial.print(unNombre, DEC);
  //Serial.print("->");
  for (int i=0; i<NOMBRE_DE_LEDS; i++) {
    byte bit = bitRead(unNombre, i);
    //Serial.print(bit);
    digitalWrite(PIN_BASE + i, bit * HIGH);
  }  
  //Serial.print('\n'); // avoir une nouvelle ligne
}

void checkMode() {
    // send data only when you receive data:
    if (Serial.available() > 0) {
            // read the incoming byte:
            octet = Serial.read();

            // say what you got:
            Serial.print("Entree: ");
            Serial.println(octet, DEC);
            mode = octet;
     }
}

void checkPush() {
  unsigned long time = millis();
  int val1 = digitalRead(IN1);  // read input value
  if (val1 == HIGH) {  
    if (time - lastSwitch > 2000) {
      lastSwitch = time;
      iMode = ((iMode + 1) % 4);
      Serial.print("iMode: ");
      Serial.println(iMode, DEC);
      mode = MODES[iMode];
    } 
  } 
}


long calculeChenille(int depart) {
    int rang = depart;
    long nombre = 0;
    for (int i=0; i<3; i++) {
      nombre += (2 << rang);
      rang = ((rang + 1) % NOMBRE_DE_LEDS);
    }
    //Serial.print("Nombre: ");
    //Serial.println(nombre, DEC);
    return nombre;
}

