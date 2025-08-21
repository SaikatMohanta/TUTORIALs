#define xaxis A2    //defining the A2 pin as X Axis input
#define yaxis A1    //defining the A1 pin as Y Axis input

//defining the digital I/O pins
#define in1 2       
#define in2 3
#define in3 4
#define in4 5

#define X 520
#define Y 504

long int x,y;   //declaring tow long integer type variable to store X & Y axis value

void setup()
{
  //pinMode(xaxis, INPUT);
  //pinMode(yaxis, INPUT);

  //declaring the digital I/O pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //initially setting the output pins to LOW
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);

  Serial.begin(9600);
}

void loop()
{
   

  x=analogRead(xaxis);    //reading the xaxis and storing the value to x variable
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\t");
  
  y=analogRead(yaxis);    //reading the yaxis and storing the value to y variable
  Serial.print("Y: ");
  Serial.print(y);
  Serial.println(" ");

  //if xaxis value is greater than 520 & lesser than 1023, the going forward 
  if(x>(X+50) && x<=1024)  
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);

    digitalWrite(in3, 1);
    digitalWrite(in4, 0);

  }

   //if xaxis value is lesser than 520 & greater than 0, the going backward 
  else if(x<(X-50) && x>=0)
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);

    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }

   //if yaxis value is greater than 504 & lesser than 1023, the going rightward 
  else if(y>(Y+50) && y<=1024)
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);

    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
  }

   //if yaxis value is lesser than 504 & greater than 0, the going leftward
  else if(y<(Y-50) && y>=0)
  {
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);

    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
  }

  //if xaxis value is equal to 520 & yaxis value is equal to 504, then motion is stopped
  else
  {
    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 0);
  }
  delay(8);
}
