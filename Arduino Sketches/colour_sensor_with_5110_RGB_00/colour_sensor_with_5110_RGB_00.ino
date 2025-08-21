#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);//(clk,  din, dc, ce, rst)

#define S0 8
#define S1 9
#define S2 10
#define S3 11
#define sensorOut 12

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

const int R=A0, G=A1, B=A2;



void setup() 
{
  display.begin();
  display.setContrast(35);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Colour-Sensor");
  display.display();
  display.setCursor(0,8);
  display.println("with RGB LED");
  display.display();
  display.setCursor(0,16);
  display.println("indicator");
  display.display();
  display.setCursor(0,30);
  display.println("By 'Saikat'");
  display.display();
  delay(3000);
  display.clearDisplay();
  
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  digitalWrite(R,0);
  digitalWrite(G,0);
  digitalWrite(B,0);

  
  //to set the output frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  //Serial.begin(9600);
}
void loop() 
{
  display.clearDisplay();
  
  //select red filter
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("R = ");
  display.display();
  


  //select green filter
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,8);
  display.println("G = ");
  display.display();


  //select blue filter 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,16);
  display.println("B = ");
  display.display();
  
  
  display.setCursor(24,0);
  display.println(redFrequency);
  display.display();
  //delay(200);

  display.setCursor(24,8);
  display.println(greenFrequency);
  display.display();
  //delay(200);
  
  display.setCursor(24,16);
  display.println(blueFrequency);
  display.display();
  //delay(200);

  if(redFrequency < 80 && greenFrequency > 80 && blueFrequency > 80)
  { 
    digitalWrite(R, 1);

    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! RED !");
    display.display();
    
  }

  else if(redFrequency > 80 && greenFrequency < 80 && blueFrequency > 80)
  {
    digitalWrite(G, 1);

    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! GREEN !");
    display.display();
    //delay(500);
  }

  else if(redFrequency > 80 && greenFrequency > 80 && blueFrequency < 80)
  {
    digitalWrite(B, 1);

    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! BLUE !");
    display.display();
    //delay(500);
  }

  
  else if(redFrequency < 25 && redFrequency > 8 && greenFrequency < 25 && greenFrequency > 8 && blueFrequency < 25 && blueFrequency > 8)
  {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! WHITE !");
    display.display();

    //digitalWrite(R,1);
    //digitalWrite(G,1);
    //digitalWrite(B,1);
  }

  else if(redFrequency < 210 && redFrequency > 180 && greenFrequency < 210 && greenFrequency > 180 && blueFrequency < 170 && blueFrequency > 140)
  {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! BLACK !");
    display.display();
  }

  else if(redFrequency < 40 && greenFrequency < 50 && blueFrequency < 80)
  {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! YELLOW !");
    display.display();

    //digitalWrite(R,1);
    //digitalWrite(G,1);
    //digitalWrite(B,0);
  }


  else if(redFrequency < 80 && redFrequency > 30 && greenFrequency < 80 && greenFrequency > 30 && blueFrequency < 45 && blueFrequency > 15)
  {
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,40);
    display.println("! VIOLET !");
    display.display();

    digitalWrite(R,1);
    digitalWrite(G,0);
    digitalWrite(B,1);
  }
  
  else
  {
    digitalWrite(R, 0);
    digitalWrite(G, 0);
    digitalWrite(B, 0);
  }

  delay(1000);
}
