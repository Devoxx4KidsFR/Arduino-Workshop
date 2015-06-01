// Programme Clignote
// Allume la LED pendant 1 seconde, puis l'eteint 1 seconde, et recommence.
// Ce qui commence par // est un commentaire, l'Arduino ne l'execute pas
 
// Cette partie n'est faite qu'une fois quand on appuie sur le bouton RESET de l'Arduino
void setup () {                
  prepareLED ();
}

// Cette partie est faite en boucle tant que l'on n'arrete pas l'arduino
void loop () {
  allumeLED ();
  attend (4);               
  eteintLED ();   
  attend (4);              
}

