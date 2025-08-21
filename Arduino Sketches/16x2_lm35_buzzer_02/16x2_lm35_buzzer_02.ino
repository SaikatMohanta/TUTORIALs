#include<LiquidCrystal.h>
#define sensor A0
#define rs 2
#define en 3
#define d4 4
#define d5 5
#define d6 6
#define d7 7

#define buzzer 9

float temp;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Thermometer");
  lcd.setCursor(0,1);
  lcd.print("By Saikat");
  delay(3000);

  pinMode(buzzer,OUTPUT);
}

void loop()
{
  temp = analogRead(sensor);
  temp = temp*0.48828125;

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" ");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature : ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.setCursor(4,1);
  lcd.print("`C");

  if(temp<20.0)
  {
    tone(buzzer,1000,500);
    
  }

  else if(temp<15.0)
  {
    tone(buzzer,1000,250);
    delay(500);
  }

  else if(temp<10.0)
  {
   tone(buzzer,1000,125);
  }
  else if(temp>20.0)
  {
    noTone(buzzer);
  }
  delay(1200);
  
}
