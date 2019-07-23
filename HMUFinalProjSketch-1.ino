//I pledge my honor that I have abided by the Stevens Honor System

//variables will change
int noteVal = 60; //initialize with a C, just 'cause
int velocity = 127; //note playing
int noteVals[13] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72}; //  AKA C, C  sharp, D, etc. Up to C again.
int buttonState[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // initialize at 0
int lastButtonState[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // "   "

void setup() {
  // initialize the pushbutton pins as inputs:
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 13; i++)//loops through and checks the status of the pins. Sends data to Serial Output which is picked up by MAX according to this status.
  {
    // read the state of the pushbutton value:
    buttonState[i] = digitalRead(i+1);

    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:

    if (buttonState[i] != lastButtonState[i]) //either a note was pressed or released 
    {
      
      if (buttonState[i] == LOW)
      {
        Serial.print(noteVals[i-1]); //i-1 because pinsstart at 1 but array at 0. Sends data for the note that corresponds to that pin.
        Serial.print(" ");
        Serial.println(0); //the velocity  - indicates there should be no sound playing / the sound should be cut off.

      } else {
        Serial.print(noteVals[i-1]); 
        Serial.print(" ");
        Serial.println(velocity); //127, indicating a sound should be playing / articulated.
      }
      delay(25);
    }
    lastButtonState[i] = buttonState[i]; //since it is looping, keep track of what the last state was we know if there is a change
  }
}
