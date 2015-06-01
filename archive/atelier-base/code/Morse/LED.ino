
// Sur la plupart des Arduino il y une LED sur la carte connectée au Pin 13.
// On va donner un nom au pin, ça sera plus partique:
int led = 13;

void prepareLED () {
  // dit à la broche 13 qu'elle est un OUTPUT, une sortie
  pinMode (led, OUTPUT);     
}

void allumeLED () {
  digitalWrite (led, HIGH);   // allume la LED (HIGH est le voltage)
}

void eteintLED () {
  digitalWrite (led, LOW);   // eteinf la LED (LOW est le voltage)
}

void attend (int n ) { // n est en secondes
  delay (n * 1000);
}

