int x;// initialise variable x
float y;//initialise variable y
void setup()
{
pinMode(A0,INPUT); // set pin a0 as input pin
Serial.begin(9600);// begin serial communication between arduino and pc
}
void loop()
{
x=analogRead(A0);// read analog values from pin A0 across capacitor
y=(x*.380156);// converts analog value(x) into input ac supply value using this formula ( explained in woeking section)
Serial.print(" analaog input " ) ; // specify name to the corresponding value to be printed
Serial.print(x) ; // print input analog value on serial monitor
Serial.print(" ac voltage ") ; // specify name to the corresponding value to be printed
Serial.print(y) ; // prints the ac value on Serial monitor
Serial.println();
}
