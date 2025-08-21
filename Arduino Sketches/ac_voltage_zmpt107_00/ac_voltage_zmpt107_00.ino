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
uint16_t a0;
float v;
float mainvolt;
void setup()
{
  pinMode(A0,INPUT); 
Serial.begin(9600);

lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight
  lcd.home ();
}

void loop()
{
  a0= analogRead(A0);
  Serial.println(a0);
  v=a0*(4.9/1023.0);
  //v=v-0.49;
  //v=v/sqrt(2.0);
  lcd.setCursor(0,0);
  lcd.print(v);
  mainvolt = v*(217000/3300);
  lcd.setCursor(0,1);
  lcd.print(mainvolt);
  delay(500);
}
