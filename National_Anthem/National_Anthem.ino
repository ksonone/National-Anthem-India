/*
 *          Independance Day Special (15-August-2020) 
 *            National Antheme - Jana ~ Gana ~ Mann
 *                  Author : Kapil H. Sonone
 *                    Date : 07-08-2020
 */

int speakerPin = 6;  //Buzzer(+ve) on this PIN

int length = 148; // the number of notes

char notes[] = "cdeeeeeeeeedef eeedddkdc cggggggggfag fffeeedfe eeeeedgggff eeeddddkdc cdeeeedef efgggfedfe eeddddkdc ccggggggggfagffffeeedfe CbC bab aga cdeeeedef ";
int beats[] = {
  1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
  2, 1, 1, 2, 1, 1, 1, 1, 2, 1,
  2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 1, 1,
  2, 1, 1, 2, 1, 1, 1, 1, 2, 1,
  2, 1, 1, 2, 1, 1, 1, 1, 2, 2, 1, 1,
  2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
  1, 1, 1, 1, 2, 2, 1, 1, 2, 1,
  1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1,
  2, 2, 1, 1, 1, 1, 1, 1, 2, 1,
  1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
  2, 1, 1, 2, 1, 1, 1, 1, 2, 1,
  1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 4, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 4, 1
};
int tempo = 295;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'k', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1948, 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  for (int i = 0; i < 9; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    // pause between notes
    delay(tempo / 4);
  }
  delay(5000);
}
