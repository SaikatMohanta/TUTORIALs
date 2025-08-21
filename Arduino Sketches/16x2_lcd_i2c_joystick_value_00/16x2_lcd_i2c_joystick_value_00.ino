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

#define xaxis A0
#define yaxis A1

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
void setup() 
{
  Serial.begin(9600); //Serial used
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight

  lcd.home ();
  //lcd.setCursor(0,0);
  lcd.print("JoyStick");

  delay(2000);

  lcd.clear();

}

void loop()
{
  long int x,y;
  int x1, y1;
  
  x=analogRead(xaxis);
  lcd.setCursor(0,0);
  lcd.print("X : ");
  lcd.setCursor(4,0);
  lcd.print(x);
  
  x1=map(x,0,1023,0,255);
  lcd.setCursor(8,0);
  lcd.print("Xm : ");
  lcd.setCursor(13,0);
  lcd.print(x1);
  
  y=analogRead(yaxis);
  lcd.setCursor(0,1);
  lcd.print("Y : ");
  lcd.setCursor(4,1);
  lcd.print(y);

  y1=map(y,0,1023,0,255);
  lcd.setCursor(8,1);
  lcd.print("Ym : ");
  lcd.setCursor(13,1);
  lcd.print(y1);
  
  delay(500);
  lcd.clear();
}
