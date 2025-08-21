#define S0 2  //SO pin to arduino D2 pin
#define S1 3  //S1 pin to arduino D3 pin
#define S2 4  //S2 pin to arduino D4 pin
#define S3 5  //S3 pin to arduino D5 pin
#define OP 6  //Output pin to arduino D6 pin
 
/*Initialling the value of variable to 0*/
int R = 0; //Initial value of RED Color is 0
int B = 0; //Initial value of BLUE Color is 0
int G = 0; //Initial value of GREEN Color is 0
 
unsigned int frequency1 = 0; //Initial frequency for RED is 0
unsigned int frequency2 = 0; //Initial frequency for BLUE is 0
unsigned int frequency3 = 0; //Initial frequency for GREEN is 0
 
#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, 7, 8, 9, 10);//RS,EN,D4,D5,D6,D7
 
//Function setup starthere
void setup()
{
  lcd.begin(16, 2);
  pinMode(S0, OUTPUT); //Assigning arduino pin D2 as output
  pinMode(S1, OUTPUT); //Assigning arduino pin D3 as output
  pinMode(S2, OUTPUT); //Assigning arduino pin D4 as output
  pinMode(S3, OUTPUT); //Assigning arduino pin D5 as output
  pinMode(OP, INPUT);  //Assigning arduino pin D6 as input
  /*Frequency is set for 20% so according to truth table
  SO pin must be at high potential and S1 pin at low potential*/ 
  digitalWrite(S0,HIGH); //Making arduino pin D2 HIGH (+5V)
  digitalWrite(S1,LOW); //Making arduino pin D3 LOW (GND)
  Serial.begin(9600); //Baud rate for serial communication
  //use only when you use seraial monitor to see output
  lcd.setCursor(0,0);
  lcd.print("Arduino Color");
  lcd.setCursor(0,1);
  lcd.print("   Detector  ");
  delay(2000);
  lcd.clear();
}
//Function setup end here
 
//Function Loop Start here
void loop()
{ 
  /*checking for red color*/
  digitalWrite(S2,LOW); //Making arduino pin D4 LOW (GND)
  digitalWrite(S3,LOW); //Making arduino pin D5 LOW (GND)
  frequency1 = pulseIn(OP, LOW); //Reading frequency for RED using pulseIN function
  Serial.print("R=");
  Serial.println(frequency1); //Displaying frequency of RED on serial monitr
  R = frequency1; //assigning value of Red frequiency to R
  delay(50); // 50 milli seconds delay
 
  /*checking for blue color*/
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);// setting for BLUE color sensor
  frequency2 = pulseIn(OP, LOW);//Reading frequency for BLUE using pulseIN function
  Serial.print("B=");
  Serial.println(frequency2); //Displaying frequency of BLUE on serial monitr
  B = frequency2; //assigning value of BLUE frequiency to B
  delay(50); // 50 milli seconds delay
  
  /*checking for green color*/
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);// setting for GREEN color sensor
  frequency3 = pulseIn(OP, LOW); //Reading frequency for GREEN using pulseIN function
  Serial.print("G=");
  Serial.println(frequency3); //Displaying frequency of GREEN on serial monitr
  G = frequency3; //assigning value of GREEN frequiency to G
  delay(50);  // 50 milli seconds delay
 Serial.println("stop");
 
/*Change the value of R, B and G with the value you have measured */
 
  /*Checking for RED color if the value of R and G lies between below defined value
   LCD display RED color*/
  if(R<90 & R>45 & G<185 & G>130)
  {
    lcd.setCursor(0,0);
    lcd.print("  RED  ");
  }
 
  /*Checking for ORANGE color if the value of B and G lies between below defined value
   LCD display ORANGE color*/
  if(G<155 & G>120 & B<155 &B>115)
  {
    lcd.setCursor(0,0);
    lcd.print("ORANGE");
  }
 
  /*Checking for GREEN color if the value of R and G lies between below defined value
   LCD display GREEN color*/
  if(R<150 & R>110 & G<160 & G>140)
  {
    lcd.setCursor(0,0);
    lcd.print(" GREEN");
  }
 
  /*Checking for YELLOW color if the value of R and G lies between below defined value
   LCD display YELLOW color*/
  if(R<80 & R>40 & G<120 & G>80)
  {
    lcd.setCursor(0,0);
    lcd.print("YELLOW");
  }
 
  /*Checking for VOILET color if the value of R and G lies between below defined value
   LCD display VOILET color*/
  if(R<90 & R>60 & B<110 & B>75)
  {
    lcd.setCursor(0,0);
    lcd.print("VOILET");
  }
 
 
  /*Checking for MAGENTA color if the value of R and G lies between below defined value
   LCD display MAGENTA color*/
  if(G<115 & G>80 & B<100 & B>50)
  {
    lcd.setCursor(0,0);
    lcd.print("MAGENTA");
  }
 
  /*Checking for BLUE color if the value of B and G lies between below defined value
   LCD display BLUE color*/
  if (G<235 & G>165 & B<190 &B>110)
  {
    lcd.setCursor(0,0);
    lcd.print(" BLUE ");
  }
 
    /*Checking for BLACK color if the value of B and G lies between below defined value
   LCD display BLACK color*/
  if (R<200 & R>150 & G<270 &G>210)
  {
    lcd.setCursor(0,0);
    lcd.print(" BLACK ");
  }
  delay(2000); //2 second delay only for pause the screen
  lcd.clear(); // Clear the screen
}
