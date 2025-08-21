#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here

#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


void setup() 
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
  //analogReference(INTERNAL);
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight
  lcd.home ();
  lcd.clear();
}

void loop() 
{
 char buf[10];
  // get amplitude (maximum - or peak value)
  uint32_t v = get_max();
  // get actual voltage (ADC voltage reference = 1.1V)
  v = v * 5.000/1023.0;
  Serial.println(v);
  // calculate the RMS value ( = peak/√2 )
  v /= sqrt(2);
 
  sprintf(buf, "%03u Volts", v);
  lcd.setCursor(2, 1);
  lcd.print(buf);
 
  delay(250);
 
}
 
 
   


uint16_t get_max()
{
  uint16_t max_v = 0;
  for(uint8_t i = 0; i < 100; i++) 
  {
    uint16_t r = analogRead(A0);  // read from analog channel 3 (A3)
    if(max_v < r) 
    max_v = r;
    delayMicroseconds(200);
  }
  return max_v;
}
