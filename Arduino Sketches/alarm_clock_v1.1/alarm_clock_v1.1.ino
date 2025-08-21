/* ----- C Program for Arduino based Alarm Clock ---- */

#include <Wire.h>
#include<EEPROM.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include "DHT.h"

#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here

#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

#define DHTTYPE DHT11
float temperature;
const int DHTPIN =2;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); 
RTC_DS3231 RTC;

int temp,inc,hours1,minut,add=11;

int next=6;    
int INC=7;
int set_mad=8;

#define buzzer 13

int HOUR,MINUT,SECOND;

 
void setup()
{
 dht.begin();
 Wire.begin();
 RTC.begin();
 lcd.begin(16,2);
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH); //Lighting backlight
 lcd.home ();
 lcd.clear();

 pinMode(INC, INPUT);
 pinMode(next, INPUT);
 pinMode(set_mad, INPUT);
 pinMode(buzzer, OUTPUT);
 digitalWrite(next, HIGH);
 digitalWrite(set_mad, HIGH);
 digitalWrite(INC, HIGH);
 
   lcd.setCursor(0,0);
   lcd.print("ALARM Clock");
   lcd.setCursor(0,1);
   lcd.print("Saikat Mohanta");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("16-06-2020");
   lcd.setCursor(0,1);
   lcd.print("Tuesday");
   delay(1500);
   lcd.clear();
    
 if(!RTC.begin())
 {
 RTC.adjust(DateTime(__DATE__,__TIME__));
 }

 //RTC.adjust(DateTime(__DATE__,__TIME__));
}
 
void loop()
{
   int temp=0,val=1,temp4;
   int humidity;
   int temperature; 
  
   humidity = dht.readHumidity();
   temperature=dht.readTemperature();
   DateTime now = RTC.now();
   if(digitalRead(set_mad) == 0)      //set Alarm time
   { 
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("  Set Alarm  ");
    delay(2000);
    
    defualt();
    time();
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Alarm time ");
    lcd.setCursor(0,1);
    lcd.print(" has been set  ");
    delay(2000);
    lcd.clear();
 }
 lcd.clear();
 
 lcd.setCursor(0,0);
 lcd.print(HOUR=now.hour(),DEC); 
 lcd.print(":");
 lcd.print(MINUT=now.minute(),DEC);
 lcd.print(":");
 lcd.print(SECOND=now.second(),DEC);
 lcd.setCursor(10, 1);
 lcd.print("T:");
 lcd.setCursor(12, 1);
 lcd.print(temperature);
 lcd.setCursor(14,1);
 lcd.print((char)223);
 lcd.setCursor(15,1);
 lcd.print("C");
 lcd.setCursor(10, 0);
 lcd.print("H:");
 lcd.setCursor(12, 0);
 lcd.print(humidity);
 lcd.setCursor(15, 0);
 lcd.print("%");
 
 lcd.setCursor(0,1);
 lcd.print(now.day(),DEC);
 lcd.print("/");
 lcd.print(now.month(),DEC);
 lcd.print("/");
 lcd.print(now.year(),DEC);
 match();
 delay(400);
}

void defualt()
{
  lcd.setCursor(0,1);
  lcd.print(HOUR);
  lcd.print(":");
  lcd.print(MINUT);
  lcd.print(":");
  lcd.print(SECOND);
}

/*Function to set alarm time and feed time into Internal eeprom*/

void time()                             
{
  int temp=1,minuts=0,hours=0,seconds=0;
    while(temp==1)
    {
     if(digitalRead(INC)==0)
     {
      HOUR++;
      if(HOUR==24)
      {
       HOUR=0;
      }
      while(digitalRead(INC)==0);
     }
     lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("Set Alarm Time ");
   //lcd.print(x); 
    lcd.setCursor(0,1);
    lcd.print(HOUR);
    lcd.print(":");
    lcd.print(MINUT);
    lcd.print(":");
    lcd.print(SECOND);
    delay(100);
    if(digitalRead(next)==0)
    {
      hours1=HOUR;
      EEPROM.write(add++,hours1);
     temp=2;
     while(digitalRead(next)==0);
    }
    }
    
    while(temp==2)
    {
     if(digitalRead(INC)==0)
     {
      MINUT++;
      if(MINUT==60)
      {MINUT=0;}
      while(digitalRead(INC)==0);
     }
     // lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(HOUR);
    lcd.print(":");
    lcd.print(MINUT);
    lcd.print(":");
    lcd.print(SECOND);
    delay(100);
      if(digitalRead(next)==0)
      {
       minut=MINUT;
       EEPROM.write(add++, minut);
       temp=0;
       while(digitalRead(next)==0);
      }
    }
    delay(1000);
}

/* Function to chack medication time */

void match()
{
  int tem[17];
  for(int i=11;i<17;i++)
  {
    tem[i]=EEPROM.read(i);
  }
  if(HOUR == tem[11] && MINUT == tem[12]) 
  {
   beep();
   beep();
   beep();
   beep();
   lcd.clear();
   lcd.print("Wake Up........");
   lcd.setCursor(0,1);
   lcd.print("Wake Up.......");
   beep();
   beep();
   beep();
   beep();
  }

}

/* function to buzzer indication */

void beep()
{
   digitalWrite(buzzer,HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(100);
   digitalWrite(buzzer,HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(100);
   digitalWrite(buzzer,HIGH);
   delay(500);
   digitalWrite(buzzer, LOW);
   delay(500);
}
