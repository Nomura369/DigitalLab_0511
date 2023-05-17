#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262

//notes in the melody
int melody[] = {
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, 0, NOTE_D3, NOTE_E3, NOTE_F3, 0, NOTE_E3,
  NOTE_D3, NOTE_C3, NOTE_C3, NOTE_E3, NOTE_D3, NOTE_G3, NOTE_C3, NOTE_C3, NOTE_C3, NOTE_D3 
};

/*int melody2[] = {
  NOTE_C3, NOTE_E3, NOTE_C3, NOTE_E3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_G3, NOTE_A3, NOTE_E3,
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_D3, NOTE_E3, NOTE_C3   
};*/

int noteDurations[] = {
  8, 8, 8, 4, 4, 8, 8, 8, 4, 8, 8, 8, 4, 
  8, 8, 4, 4, 8, 4, 4, 8, 4, 4
};

/*int noteDurations2[] = {
  4, 4, 4, 4, 4, 8, 8, 4, 4, 8, 8, 
  8, 8, 8, 16, 16, 16, 8, 8, 8, 8, 8, 4
};*/

void setup() {
  // put your setup code here, to run once:
  //pinMode(6, INPUT_PULLUP);
  for(int i = 2; i <= 9; i++){
    pinMode(i, OUTPUT);
  } //NOTE_C3~NOTE_C4
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int thisNote = 0; thisNote < 23; thisNote++) {
     // to calculate the note duration, take one second divided by the note type.
     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(10, melody[thisNote], noteDuration);
      if(melody[thisNote] == NOTE_C3) digitalWrite(2, HIGH);
      else digitalWrite(2, LOW);
      if(melody[thisNote] == NOTE_D3) digitalWrite(3, HIGH);
      else digitalWrite(3, LOW);
      if(melody[thisNote] == NOTE_E3) digitalWrite(4, HIGH);
      else digitalWrite(4, LOW);
      if(melody[thisNote] == NOTE_F3) digitalWrite(5, HIGH);
      else digitalWrite(5, LOW);
      if(melody[thisNote] == NOTE_G3) digitalWrite(6, HIGH);
      else digitalWrite(6, LOW);
      if(melody[thisNote] == NOTE_A3) digitalWrite(7, HIGH);
      else digitalWrite(7, LOW);
      if(melody[thisNote] == NOTE_B3) digitalWrite(8, HIGH);
      else digitalWrite(8, LOW);
      if(melody[thisNote] == NOTE_C4) digitalWrite(9, HIGH);
      else digitalWrite(9, LOW);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(10);
    }
  
}
