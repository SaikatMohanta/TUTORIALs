//16*2 LCD Display from serial monitor

//Modified from "YourDuino.com"

//SurtrTech channel (LEBOUIHA)

//Code for displaying a message from the serial monitor

#include <Wire.h> //Libraries needed

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

void setup() {

  Serial.begin(9600); //Serial used

  lcd.begin (16,2);

  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);

  lcd.setBacklight(HIGH); //Lighting backlight

  lcd.home ();

  lcd.print("Hello");

  delay(2000);

  lcd.clear();

}

void loop()

  {

    // when characters arrive over the serial port...

    if (Serial.available()) {

      // wait a bit for the entire message to arrive

      delay(100);

      // clear the screen

      lcd.clear();

      // read all the available characters

      while (Serial.available() > 0) {

        // display each character to the LCD
     
        lcd.write(Serial.read());

      }

    }

  }
