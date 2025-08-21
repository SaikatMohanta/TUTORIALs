#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define redLED 9
#define greenLED 10
#define blueLED 11
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
byte redMin;
byte redMax;
byte greenMin;
byte greenMax;
byte blueMin;
byte blueMax;
int color = 0;



void setup()
{
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 pinMode(redLED, OUTPUT);
 pinMode(greenLED, OUTPUT);
 pinMode(blueLED, OUTPUT);
 pinMode(13, OUTPUT);
 pinMode(sensorOut, INPUT);
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);
 Serial.begin(9600);
 calibrate();
}


void loop() 
{
 readColor();
 decideColor();
 printColor();
}

void decideColor() 
{

 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);
 int maxVal = max(redColor, blueColor);
 maxVal = max(maxVal, greenColor);
 redColor = map(redColor, 0, maxVal, 0, 255);
 greenColor = map(greenColor, 0, maxVal, 0, 255);
 blueColor = map(blueColor, 0, maxVal, 0, 255);
 redColor = constrain(redColor, 0, 255);
 greenColor = constrain(greenColor, 0, 255);
 blueColor = constrain(blueColor, 0, 255);
 analogWrite(redLED, redColor);
 analogWrite(greenLED, greenColor);
 analogWrite(blueLED, blueColor);

 if (redColor > 250 && greenColor > 250 && blueColor > 250)
 {
   color = 1;
 }
 else if (redColor < 25 && greenColor < 25 && blueColor < 25) 
 {
   color = 2;
 }
 else if (redColor > 200 &&  greenColor > 200 && blueColor < 100)
 {
   color = 4;
 }
 else if (redColor > 200 &&  greenColor > 25 /*&& blueColor < 100*/) 
 {
   color = 3;
 }
 else if (redColor > 200 &&  greenColor < 100 && blueColor > 200) 
 {
   color = 5;
 }
 else if (redColor > 250 && greenColor < 200 && blueColor < 200)
 {
   color = 6;
 }
 else if (redColor < 200 && greenColor > 250 && blueColor < 200) 
 {
   color = 7;
 }
 else if (redColor < 200 /*&& greenColor < 200*/ && blueColor > 250) 
 {
   color = 8;
 }
 else 
 {
   color = 0;
 }
}


void calibrate() 
{
 Serial.println("Calibrating...");
 Serial.println("White");
 digitalWrite(13, HIGH);
 delay(2000);
 
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMin = pulseIn(sensorOut, LOW);
 delay(100);
 
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMin = pulseIn(sensorOut, LOW);
 delay(100);
 
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMin = pulseIn(sensorOut, LOW);
 delay(100);
 
 Serial.println("next...");
 digitalWrite(13, LOW);
 delay(2000);
 
 Serial.println("Black");
 digitalWrite(13, HIGH);
 delay(2000);
 
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redMax = pulseIn(sensorOut, LOW);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenMax = pulseIn(sensorOut, LOW);
 delay(100);
 
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueMax = pulseIn(sensorOut, LOW);
 delay(100);
 
 Serial.println("Done calibrating.");
 digitalWrite(13, LOW);
}


void printColor() 
{
 Serial.print("R = ");
 Serial.print(redColor);
 Serial.print(" G = ");
 Serial.print(greenColor);
 Serial.print(" B = ");
 Serial.print(blueColor);
 Serial.print(" Color: ");
 switch (color) {
   case 1: Serial.println("WHITE"); break;
   case 2: Serial.println("BLACK"); break;
   case 3: Serial.println("ORANGE"); break;
   case 4: Serial.println("YELLOW"); break;
   case 5: Serial.println("PURPLE"); break;
   case 6: Serial.println("RED"); break;
   case 7: Serial.println("GREEN"); break;
   case 8: Serial.println("BLUE"); break;
   default: Serial.println("unknown"); break;
 }
}


void readColor() 
{
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 redFrequency = pulseIn(sensorOut, LOW);
 redColor = map(redFrequency, redMin, redMax, 255, 0);
 delay(100);
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 greenFrequency = pulseIn(sensorOut, LOW);
 greenColor = map(greenFrequency, greenMin, greenMax, 255, 0);
 delay(100);
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 blueFrequency = pulseIn(sensorOut, LOW);
 blueColor = map(blueFrequency, blueMin, blueMax, 255, 0);
 delay(100);
}
