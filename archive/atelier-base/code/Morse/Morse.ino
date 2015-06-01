// Programme Morse
// Ce programme emet OK en morse
 
// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
// OK se dit --- -.-
void setup () {                
  prepareLED ();
  trait();
  trait();
  trait();
  attend (3); 
  trait();
  point();
  trait();
}

void point() {
  allumeLED ();
  attend (1);               
  eteintLED ();   
  attend (1);    
}

void trait() {
  allumeLED ();
  attend (3);               
  eteintLED ();   
  attend (1);    
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino
void loop () {
}

