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

int melody2[] = {
  NOTE_C3, NOTE_E3, NOTE_C3, NOTE_E3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_G3, NOTE_A3, NOTE_E3,
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_D3, NOTE_E3, NOTE_C3   
};

int noteDurations[] = {
  8, 8, 8, 4, 4, 8, 8, 8, 4, 8, 8, 8, 4, 
  8, 8, 4, 4, 8, 4, 4, 8, 4, 4
};

int noteDurations2[] = {
  4, 4, 4, 4, 4, 8, 8, 4, 4, 8, 8, 
  8, 8, 8, 16, 16, 16, 8, 8, 8, 8, 8, 4
};

int melodyNumber = 0;
bool previousState = 1, presentState = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(melodyNumber == 0) {
    for (int thisNote = 0; thisNote < 23; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8); // stop the tone playing:
      presentState = digitalRead(6);
      if(presentState == 0 &&  previousState == 1) {
        melodyNumber = melodyNumber + 1;
        thisNote = 23;
      }
      previousState = presentState;
    }
  }
  if(melodyNumber == 1) {
    for (int thisNote = 0; thisNote < 23; thisNote++) {
      int noteDuration = 1000 / noteDurations2[thisNote];
      tone(8, melody2[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8); // stop the tone playing:
      presentState = digitalRead(6);
      if(presentState == 0 &&  previousState == 1)
      {
        melodyNumber = melodyNumber - 1;
        thisNote = 23;
      }
      previousState = presentState;
    }
  }
}
