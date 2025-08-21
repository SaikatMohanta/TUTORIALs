#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int clearFrequency = 0;

void setup() 
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  //to set the output frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(115200);
}
void loop() 
{
  
  //select red filter
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(2000);


  //select green filter
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(2000);


  //select blue filter 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(2000);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  clearFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" C = ");
  Serial.println(clearFrequency);
  delay(2000);
}
