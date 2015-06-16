// Programme JukeBox
// ce programme joue plusieurs morceaux de musique

#include <string.h>

int PIN_BUZZER = 8;

int currentTune = 0;
const int NB_TUNES = 7;
char* tunes[NB_TUNES];              
char* playbooks[NB_TUNES];   

char delimiters[] = " ";

void setup() {
  Serial.begin(9600);
  setupTunes();
}

void loop() {
    playTune(currentTune);
    delay(3000);  
    currentTune = (currentTune + 1) % NB_TUNES;
}

void setupTunes() {
  // format: Grub init tune
  
  tunes[0] = "Super Mario";
  playbooks[0]= "1000 334 1 334 1 0 1 334 1 0 1 261 1 334 1 0 1 392 2 0 4 196 2"; 

  tunes[1] = "Close Encounters";
  playbooks[1]= "220 900 2 1000 2 800 2 400 2 600 3"; 

  tunes[2] = "Fur Elise";
  playbooks[2]= "480 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 262 1 "
    "315 1 335 3 213 1 420 1 400 1 420 1 400 1 420 1 315 1 370 1 335 1 282 3 180 1 215 1 282 1 315 3 213 1 330 1 315 1 282 3"; 

  tunes[3] = "Star Wars: Imperial March";
  playbooks[3]= "480 440 4 440 4 440 4 349 3 523 1 440 4 349 3 523 1 440 8 659 4 659 4 659 4 698 3 523 1 415 4 349 3 523 1 440 8"; 

  tunes[4] = "Wolfenstein 3D";
  playbooks[4]= "300 131 1 196 1 196 1 196 1 294 1 196 1 294 1 196 1 131 1";

  tunes[5] = "arpegio";
  playbooks[5]= "480 220 1 277 1 330 1 440 1 185 1 220 1 277 1 370 1 294 1 370 1 440 1 587 1 330 1 415 1 494 1 659 1";  

  tunes[6] = "super mario mushroom power up";
  playbooks[6]= "1750 523 1 392 1 523 1 659 1 784 1 1047 1 784 1 415 1 523 1 622 1 831 1 622 1 831 1 1046 1 1244 1 "
    "1661 1 1244 1 466 1 587 1 698 1 932 1 1195 1 1397 1 1865 1 1397 1";
}

void playTune(int position) {
   Serial.print("Debut du morceau");
   Serial.println(tunes[position]);
   
   char* playbook = strdup(playbooks[position]);
   
   char* element;
   element = strtok(playbook, delimiters);
   float beat = readBeat(element);
   
   while ( (element = strtok(NULL, delimiters)) != NULL ) {
      int pitch = readPitch(element);
      element = strtok(NULL, delimiters);
      int duration = readDuration(element, beat);
      playNote(pitch, duration);    
   }
   Serial.println("Morceau termine");
   free(playbook);
}

float readBeat(char* element) {
    int tempo = atoi(element);
    Serial.print("Beat:");
    Serial.println(tempo);
    float beat = tempo / 60;   
    return beat;
}

int readPitch(char* element) {
    int pitch = atoi(element);
    Serial.print("Pitch:");
    Serial.println(pitch);
    return pitch;  
} 

int readDuration(char* element, float beat) {
    int len = atoi(element);
    Serial.print("Duration:");
    Serial.println(len);
    double duration = len * 1000 / beat;
    return duration;
}

void playNote(int pitch, double duration) {
  tone(PIN_BUZZER, pitch, duration);
  delay(duration * 1.4);
  noTone(PIN_BUZZER);
}

