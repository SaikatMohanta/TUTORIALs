#include <Adafruit_Sensor.h>
#include <DHT.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include<LCD.h>

#include <RTClib.h>

#define type DHT22
#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here
#define BACKLIGHT_PIN 3 
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

const int dhtpin=2;
int humidity,temp;


#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here

#define BACKLIGHT_PIN 3 
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
DHT dht(dhtpin,type);
DateTime now;
RTC_DS3231 rtc;


void showDate(void);
void showTime(void);
void showDay(void);


void setup() 
{
pinMode(dhtpin,INPUT);
 Serial.begin(9600);
 dht.begin();
 

  if (! rtc.begin()) 
  {
    Serial.println("Couldn't find RTC Module");
    while (1);
  }

  if (rtc.lostPower()) 
  {
    Serial.println("RTC lost power, lets set the time!");
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 
 lcd.begin (20,4);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); 
  lcd.home ();
 lcd.setCursor(0,0);
  lcd.print("Digital Clock");
  lcd.setCursor(0,1);
  lcd.print("By SAIKAT MOHANTA");
   lcd.setCursor(0,2);
  lcd.print("16/01/2020");
  lcd.setCursor(0,3);
  lcd.print("Bongaon");
  
  delay(8000);
  
}


void loop() 
{
  humidity=dht.readHumidity();
  temp=dht.readTemperature();
  /*Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("   Humidity = ");
  Serial.print(humidity);
  Serial.println();
*/
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:> ");
  lcd.print(temp);

  
  lcd.setCursor(16, 0);
  lcd.print("`C ");

  
  lcd.setCursor(0, 1);
  lcd.print("Humidity:> ");
  lcd.print(humidity);

  
  lcd.setCursor(14, 1);
  lcd.print("%");

  now = rtc.now();
  showDate();
  showTime();

  delay(60000);
}

void showDate()
 {
  lcd.setCursor(0,2);
  lcd.print("Date:> ");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
 }

 void showTime()
 {
  lcd.setCursor(0,3);
  lcd.print("Time:> ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  //lcd.print(':');
  //lcd.print(now.second());
  //lcd.print("    ");
} 
