#include<Servo.h>
Servo myservo;
int pos=0;
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define Out 8
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int R=0;
int B=0;
int G=0;

void setup() 
{
  myservo.attach(9);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Out, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}
void loop() 
{
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(Out, LOW);
  Serial.print("R= ");
  Serial.println(redFrequency);
  R=redFrequency;
 /*if(R<90 & R>45 & G<185 & G>130)
  {
   Serial.print("  RED  ");
  myservo.write(20);
  }*/
  delay(2000);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(Out, LOW);
  Serial.print(" G = ");
  Serial.println(greenFrequency);
  G=greenFrequency;
  /*if(R<150 & R>110 & G<160 & G>140)
  {
   Serial.print(" GREEN ");
  myservo.write(90);
  }*/
  delay(2000);
    digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(Out, LOW);
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  B=blueFrequency;
  /*if(G<235 & G>165 & B<190 &B>110)
  {
   Serial.print(" BLUE ");
  myservo.write(180);
  }*/
  delay(2000);
 
}
