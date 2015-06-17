/*
Open Pure Data
Open the "SimpleExample.pd" file in Pure Data
Click on the "devices" message box: This will list any available serial ports in a numbered list.
On my Mac, the usb port connected to the microcontroller was on port 2; (it may be different on your computer)
Find the correct port number and change the "open" message from "open 2" to "open (your port # here)".

    To do that, enter Edit mode under the Edit menu.
    Now you can type directly into the message boxes.
    After you change the "open" message, leave edit mode and do the following:
        1. Select "compute audio" in the main Pd window (Checkmark DSP)
        2. Click on the "open" message to open the serial connection

You should see output of the comport changing, and should hear a rising and falling tone. 
*/

void setup() {
 Serial.begin(9600);
}

void loop() {
 for (int i=0; i<255; i++) {
   Serial.write(i);
   delay(100);
 }
 for (int i=255; i>0; i--) {
   Serial.write(i);
   delay(100);
 }
}
