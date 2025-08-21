/* This code works with ZMPT101B AC voltage sensor module and 128x32 OLED display
 * It permits you to measure any AC voltage up to 250V, BE CAREFUL !!!
 * The functions from Filters library permits you to calculate the True RMS of a signal
 * Refer to www.surtrTech.com or SurtrTech YouTube channel for more details
 */

#include <Filters.h> //Easy library to do the calculations
#include <SPI.h>     //Libraries for the OLED display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 //

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

float testFrequency = 50;                     // test signal frequency (Hz)
float windowLength = 40.0/testFrequency;     // how long to average the signal, for statistist

int Sensor = 0; //Sensor analog input, here it's A0

float intercept = -0.04; // to be adjusted based on calibration testing
float slope = 0.0405; // to be adjusted based on calibration testing
float current_Volts; // Voltage

unsigned long printPeriod = 1000; //Refresh rate
unsigned long previousMillis = 0;


void setup() {
  Serial.begin( 9600 );    // start the serial port
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display 
  display.clearDisplay();
  display.setTextSize(2);                   
  display.setTextColor(WHITE);              
  display.setCursor(1,1);               
  display.print("SurtrTech");
  display.setCursor(1,20);
  display.setTextSize(1);
  display.print("AC Voltmeter");
  display.display();
  delay(5000);

}

void loop() {
  
  RunningStatistics inputStats;                //Easy life lines, actual calculation of the RMS requires a load of coding
  inputStats.setWindowSecs( windowLength );
   
  while( true ) {   
    Sensor = analogRead(A0);  // read the analog in value:
    inputStats.input(Sensor);  // log to Stats function
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) {
      previousMillis = millis();   // update time every second
            
      Serial.print( "\n" );
      
      current_Volts = intercept + slope * inputStats.sigma(); //Calibartions for offset and amplitude
      current_Volts= current_Volts*(40.3231);                //Further calibrations for the amplitude
      
      Serial.print( "\tVoltage: " );
      Serial.print( current_Volts ); //Calculation and Value display is done the rest is if you're using an OLED display
      
      
      display.clearDisplay();
      display.setTextSize(3);       //size of the text that will follow              
      display.setTextColor(WHITE);  //its color            
      display.setCursor(1,1);      //position from where you want to start writing           
      display.print(current_Volts,1);
      display.setCursor(115,00);
      display.setTextSize(2);
      display.print("V");
      display.setCursor(115,15);
      display.setTextSize(1);
      display.print("AC");
      display.display();
    }
  }

}
