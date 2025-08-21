//CIRCUIT DIAGRAM:-

//MOTOR DRIVER CONNECTIONS:
//MOTOR DRIVER -> ARDUINO
//ENA          -> D10
//IN1          -> D2
//IN2          -> D3
//ENA          -> D9
//IN3          -> D4
//IN4          -> D5
//+12V         -> 12V BATTERY PACK +(VE) TERMINAL
//GND          -> GND
//+5V          -> TO ARDUINO AND HC05 +(5V)PIN

//BLETOOTH MODULE CONNECTIONS:
//HC05         -> ARDUINO
//TXD          -> RX0
//RXD          -> TX1
//VCC          -> 5V
//GND          -> GND
//*PLEASE DISCONNECT THE TXD & RXD BEFORE UPLOADING THE CODE TO THE MCU.
//**OTHERWISE THE CODE WILL NOT UPLOAD.
//**AFTER UPLOADING CONNECT THE TXD & RXD TO THE HC05 MODULE. 
//LINK FOR THE ANDROID APP: https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en_IN&gl=US

char i;   //a character type global variable to store the incoming serial data from HC05 module.

//motor 1 control pins decleration
int enA=10;
const int inPut1=2;
const int inPut2=3;

//motor 2 control pins decleration
int enB=9;
const int inPut3=4;
const int inPut4=5;

//pinPut for buzzer
const int buzz=6;

//pin for front light
const int ledF=7;

//pin for front light
const int ledB=8;

//setup function which runs only once
void setup()
{           //Serial.begin(9600);
            
            //configure all the decleared pins as output
            pinMode(enA,OUTPUT);
            pinMode(enB,OUTPUT);
            pinMode(inPut1,OUTPUT);
            pinMode(inPut2,OUTPUT);
            pinMode(inPut3,OUTPUT);
            pinMode(inPut4,OUTPUT);
            pinMode(ledF, OUTPUT);
            pinMode(ledB, OUTPUT);
            pinMode(buzz, OUTPUT);
            //arduino built in library function to silence the buzzer
            noTone(buzz);
            
            //initially all the liights are in off state
            digitalWrite(ledF, LOW);
            digitalWrite(ledF, LOW);
           
}

//main function which runs over and over
void loop()
{         
          //The "Serial.available( )" function in Arduino gets the stored bytes from the serial port that are available for reading. 
          //It is the data, which is already stored and arrived in the serial buffer.
          if(Serial.available())     //If there is serial data available in the buffer
          {         i=Serial.read();    //Store the received serial data into the variable named "i"
                    //Serial.println(i);
                      
                    halt();   //stop firstly

                    //constructing a switch-case 
                    switch(i)
                    {       case 'F':
                                forward();    //go forward
                               
                                break;

                            case 'B':
                                back();       //go backward
                                
                                break;

                            case 'L':         //go left
                                left();
                                
                                break;

                            case 'R':
                                right();      //go right
                                
                                break;

                            case 'V':
                                tone(buzz,1500);    //make sound through buzzer with 1.5kHz tone
                                break;

                            case 'v':
                                noTone(buzz);       //silence the buzzer
                                
                                break;

                            case 'W':
                                digitalWrite(ledF, HIGH);      //front led on
                                
                                break;

                            case 'w':
                                digitalWrite(ledF, LOW);       //front led off
                                
                                break;

                            case 'U':
                                digitalWrite(ledB, HIGH);      //back led on
                                
                                break;

                            case 'u':
                                digitalWrite(ledB, LOW);      //back led off
                                
                                break;
                                
                            case 'G':
                               forwardleft();     //go forward left
                               
                               break;

                            case 'I':
                                forwardright();       //go forward right
                                
                                break;

                            case 'H':
                                backleft();       //go back left
                                
                                break;

                            case 'J':
                                backright();      //go back right
                                
                                break;
                            

                   }
                  
          }
          else
          {
              //do nothing
          }
          
          
}

//user defined function one named halt() to stop the bot
void halt()
{         
          analogWrite(enA,0);
          analogWrite(enB,0);

          digitalWrite(inPut1,LOW);
          digitalWrite(inPut2,LOW);

          digitalWrite(inPut3,LOW);
          digitalWrite(inPut4,LOW);
          
}

//user defined function four named left() to turn the bot to left direction
void left()
{         analogWrite(enA,180);
          digitalWrite(inPut1,LOW);
          digitalWrite(inPut2,HIGH);
          

          analogWrite(enB,180);
          digitalWrite(inPut3,HIGH);
          digitalWrite(inPut4,LOW);
          
}

//user defined function five named right() to turn the bot to right direction
void right()
{         analogWrite(enA,180);
          digitalWrite(inPut1,HIGH);
          digitalWrite(inPut2,LOW);
          

          
          analogWrite(enB,180);
          digitalWrite(inPut3,LOW);
          digitalWrite(inPut4,HIGH);
          
}

//user defined function three named back() to move the bot to backward direction
void back()
{         analogWrite(enA,250);
          digitalWrite(inPut1,LOW);
          digitalWrite(inPut2,HIGH);
          

          analogWrite(enB,250);
          digitalWrite(inPut3,LOW);
          digitalWrite(inPut4,HIGH);
          
}

void backleft()
{     analogWrite(enA,150);
      digitalWrite(inPut1,LOW);
      digitalWrite(inPut2,HIGH);

      analogWrite(enB,250);
      digitalWrite(inPut3,LOW);
      digitalWrite(inPut4,HIGH);
}

//user defined function five named backright() to turn the bot to backright direction
void backright()
{     analogWrite(enA,250);
      digitalWrite(inPut1,HIGH);
      digitalWrite(inPut2,LOW);

      analogWrite(enB,150);
      digitalWrite(inPut3,HIGH);
      digitalWrite(inPut4,LOW);
}
//user defined function two named forward() to move the bot to fornt direction
void forward()
{         analogWrite(enA,250);
          digitalWrite(inPut1,HIGH);
          digitalWrite(inPut2,LOW);
          

          analogWrite(enB,250);
          digitalWrite(inPut3,HIGH);
          digitalWrite(inPut4,LOW);
          
}

//user defined function five named backleft() to turn the bot to backleft direction


//user defined function five named forwardright() to turn the bot to forwardright direction
void forwardright()
{     analogWrite(enA,150);
      digitalWrite(inPut1,HIGH);
      digitalWrite(inPut2,LOW);

      analogWrite(enB,250);
      digitalWrite(inPut3,HIGH);
      digitalWrite(inPut4,LOW);
}

//user defined function five named forwardleft() to turn the bot to forwardleft direction
void forwardleft()
{     analogWrite(enA,250);
      digitalWrite(inPut1,LOW);
      digitalWrite(inPut2,HIGH);

      analogWrite(enB,150);
      digitalWrite(inPut3,LOW);
      digitalWrite(inPut4,HIGH);
}
