/*************************************************************************
 * 
 * AC Voltmeter with Arduino.
 * This is a free software with NO WARRANTY.
 * USE AT YOUR OWN RISK!
 * https://simple-circuit.com/
 *
 ************************************************************************/
 
#include <LiquidCrystal.h>    // include Arduino LCD library
 
// LCD module connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 
void setup(void) {
  lcd.begin(16, 2);           // set up the LCD's number of columns and rows
  lcd.setCursor(0, 0);
  lcd.print("RMS Voltage:");
  analogReference(INTERNAL);  // set ADC positive reference voltage to 1.1V (internal)
}
 
// get maximum reading value
uint16_t get_max() {
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) {
    uint16_t r = analogRead(A3);  // read from analog channel 3 (A3)
    if(max_v < r) max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}
 
// main loop
void loop() {
 
  char buf[10];
  // get amplitude (maximum - or peak value)
  uint32_t v = get_max();
  // get actual voltage (ADC voltage reference = 1.1V)
  v = v * 1100/1023;
  // calculate the RMS value ( = peak/√2 )
  v /= sqrt(2);
 
  sprintf(buf, "%03u Volts", v);
  lcd.setCursor(0, 1);
  lcd.print(buf);
 
  delay(100);
 
}
 
// end of code.
