
const byte ANTENNA = 9;

unsigned long A = calcDelayTimeForFreq(440);
unsigned long B = calcDelayTimeForFreq(494);
unsigned long C = calcDelayTimeForFreq(523);
unsigned long D = calcDelayTimeForFreq(587);
unsigned long E = calcDelayTimeForFreq(659);
unsigned long F = calcDelayTimeForFreq(699);
unsigned long G = calcDelayTimeForFreq(784);
unsigned long _A2 = calcDelayTimeForFreq(880);
unsigned long rest = 1;

unsigned long q = 652;
unsigned long e = q/2;
unsigned long s = e/2;
unsigned long t = s/2;
unsigned long h = q*2;
unsigned long f = q*4;

void setup() {
  // set up Timer 1
  TCCR1A = _BV (COM1A0);  // toggle OC1A on Compare Match
  TCCR1B = _BV(WGM12) | _BV(CS10);   // CTC, no prescaler
  OCR1A =  9;       // compare A register value to 10 (zero relative)
}  // end of setup

void tone(unsigned long dTime, unsigned long playTime) {
  unsigned long end = millis() + playTime;
 
  while (end > millis()) {
    pinMode (ANTENNA, OUTPUT);
    delayMicroseconds(dTime);
    pinMode (ANTENNA, INPUT);
    delayMicroseconds(dTime);   
  }
}

void note(unsigned long dTime, unsigned long playTime) {
  tone(dTime,playTime-50);
  tone(rest,50);
}

unsigned long calcDelayTimeForFreq(unsigned long freq) {
  return 500000/freq;
}


void twinkleTwinkle() {
  note(C,q);
  note(C,q);
  note(G,q);
  note(G,q);
  note(_A2,q);
  note(_A2,q);
  note(G,h);
 
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,q);
  note(D,q);
  note(C,h);
 
  note(G,q);
  note(G,q);
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,h);
 
  note(G,q);
  note(G,q);
  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,h);
 
  note(C,q);
  note(C,q);
  note(G,q);
  note(G,q);
  note(_A2,q);
  note(_A2,q);
  note(G,h);

  note(F,q);
  note(F,q);
  note(E,q);
  note(E,q);
  note(D,q);
  note(D,q);
  note(C,h);
}

void locateTone() {
  note(A,t);
  note(B,t);
  note(C,t);
  note(D,t);
  note(E,f);
  note(D,t);
  note(C,t);
  note(B,t);
}

void loop() {
  twinkleTwinkle();
}
