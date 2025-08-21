//Clayton Ford 
//With assistance from Mark Tortorich
//Texting old-school style with a Hitachi-compatible 16x2 LCD and a 4x4 keypad
//with added text storage and serial return of typed text.
//This code and hardware setup, without much additional effort, could actually 
//send text messages upon the addition of a cellular shield and relatively 
//minor changes to this code.

#include <LiquidCrystal.h> //include the lcd library
const byte row1=3; //keypad row pins, shared with the lcd data lines
const byte row2=4;
const byte row3=5;
const byte row4=6;
const byte col1=7; //keypad column lines
const byte col2=8;
const byte col3=9;
const byte col4=10;
LiquidCrystal lcd(12, 11, row4, row3, row2, row1); //lcd object
byte numpressed; //latest number pressed on the keypad
byte timespressed; //times the number has been pressed
byte cursorx=0; //cursor x position
byte cursory=0; //cursor y position
char letter; //stores letter that needs to be printed to the lcd
const int wait=1000; //time to wait for additional presses to same number
const int preventholddelay=150; //time to wait to prevent cycling through things too quickly
unsigned long basetime; //base time for while loop
unsigned long elapsed=0; //elapsed time in while loop
byte lastnumpressed; //the initial number pressed on the keypad
bool disablespacedelay=false; //disables the delay in the space function in the case that a different number is pressed while in while loop
const byte maxtimespressed[16]={
  1,3,4,4,4,4,4,4,4,4,1,7,1,1,1,1}; //stores maximum number of times any given key can be pressed before looping back to its first letter (used by incrementtimespressed function)
char typedtext[140]; //stores typed text for printout to the serial console
int positionintypedtext=0; //position in typedtext character array
int charremaining; //remaining characters in message
bool promptkeypress=false; //used for waiting for, and keypress detection, at the end-of composition prompt

void setup(){
  Serial.begin(115200); //start serial communication so that we can print the typed text to the serial console
  lcd.begin(16,2); //initialize the lcd
  lcd.setCursor(cursorx,cursory); //set the lcd cursor
  lcd.noCursor(); //turn off the cursor
  pinMode(row1,OUTPUT); //set the rows as outputs
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(row4,OUTPUT);
  pinMode(col1,INPUT); //set the  columns as inputs
  pinMode(col2,INPUT);
  pinMode(col3,INPUT);
  pinMode(col4,INPUT);
  delay(wait);
  lcd.cursor(); //turn the cursor on again after a delay equivalent to wait
  rowshigh(); //sets all rows high
}

void loop(){
  numpressed=16; //reset "numpressed" (16 doesn't refer to any button on the pad)
  if (findpress()){ //look for presses, if one has occurred, identify it and continue
    timespressed=0; //reset "timespressed"
    if (numpressed==0){ //if zero on the pad was pressed,
      dozero(); //print zero
      letter='0'; //manually seed a zero as the character for the text storage
      textstorage(1); //regular character storage
    }
    if (numpressed==10){ //if shift on the pad was pressed,
      textstorage(2); //perform a space in storage
      dospace(); //do a space
    }
    if (numpressed==14){ //if the arrows on the pad were pressed,
      textstorage(3); //perform a backspace in storage
      dobackspace(); //do a backspace
    }
    if (numpressed==15){ //if enter on the pad was pressed,
      outputserial(); //output message and display remaining characters to serial console
    }
    if ((numpressed<10&&numpressed>0)||numpressed==11){ //if 1,2,3,4,5,6,7,8,9, or 11 was pressed (any one of the keys with multiple characters assigned),
      lastnumpressed=numpressed; //record which number was pressed,
      basetime=millis(); //and take a base time for the while loop
      while (elapsed<wait){ //while below the time to wait,
        if(findpress()){ //look for presses, if one has occurred, identify it and continue
          if (numpressed==lastnumpressed){ //if it was the same as before,
            incrementtimespressed(); //increment "timespressed"
            basetime=basetime+(wait-(wait-elapsed)); //roll up the base time, to allow another wait period until next press of the same button
            definepress(); //use "numpressed" and "timespressed" to define "letter"
            lcd.print(letter); //print the letter that was defined
            lcd.setCursor(cursorx,cursory); //maintain cursor position
            rowshigh(); //return all rows high
            delay(preventholddelay); //delay a little to prevent continuous cycling through "timespressed" during a single press
          }
          else{ //if the number that was pressed was different than before,
            disablespacedelay=true; //disable the delay in the space function to allow the press to be detected a second time, at the beginning of void loop
            break; //break out of the while loop
          }
        }
        elapsed=millis()-basetime; //refresh the elapsed time for the while loop
      }
      elapsed=0; //reset the elapsed time for the while loop
      textstorage(1); //store character
      dospace(); //do a space
    }
  }
  if (positionintypedtext==139){ //if the end of the stored text has been reached,
    promptkeypress=false; //reset keypress detection
    cursorx=0; //set cursor to the beginning of first row
    cursory=0;
    lcd.setCursor(cursorx,cursory);
    lcd.print("Msg end. <>=back"); //print this out to the lcd
    cursorx=0; //set cursor to the beginning of second row
    cursory=1;
    lcd.setCursor(cursorx,cursory);
    lcd.print("enter=serial out"); //print this out to the lcd
    rowshigh(); //sets all rows high
    numpressed=16; //reset "numpressed" (16 doesn't refer to any button on the pad)
    while(!promptkeypress){ //while no relevant keypresses have occurred, 
      if (findpress()){ //look for presses, if one has occurred, identify it and continue
        timespressed=0; //reset "timespressed"
        if (numpressed==14){ //if the arrows on the pad were pressed,
          promptkeypress=true; //take note so that the while loop can be broken
          textstorage(3); //perform a backspace in storage
          for (int i=0;i<16;i++){ //print out to the first line on the lcd from the stored text
            cursorx=i;
            cursory=0;
            lcd.setCursor(cursorx,cursory);
            lcd.print(typedtext[108+i]);
          }
          for (int j=0;j<16;j++){ //print out to the second line on the lcd from the stored text
            cursorx=j;
            cursory=1;
            lcd.setCursor(cursorx,cursory);
            lcd.print(typedtext[123+j]);
          }
          cursorx=15; //set cursor to the beginning of second row
          cursory=1;
          lcd.setCursor(cursorx,cursory);
          rowshigh(); //sets all rows high
        }
        if (numpressed==15){ //if enter on the pad was pressed,
          promptkeypress=true; //take note so that the while loop can be broken
          Serial.print("Final message: "); //print this to the serial console
          Serial.println(typedtext); //print out all the text typed so far to the serial console
          Serial.println(); //print a blank line
          for (int i=0;i<140;i++){ //write all positions in the stored text to be blank
            typedtext[i]=' ';
          }
          positionintypedtext=0; //reset the position in the stored text to the beginning
          doclear();
          rowshigh(); //sets all rows high
        }
      }
    }
    delay(preventholddelay); //delay a little to prevent continuous cycling
  }
}

void rowshigh(){ //sets all rows high
  digitalWrite(row1,HIGH); //write all the rows high
  digitalWrite(row2,HIGH); 
  digitalWrite(row3,HIGH);
  digitalWrite(row4,HIGH);
}

bool findpress(){ //finds a press to define "numpressed", if any press occurs, returns true
  bool pressfound=false; //variable for any press detection, is returned by this function

  digitalWrite(row1,LOW); //write all rows low
  digitalWrite(row2,LOW);
  digitalWrite(row3,LOW);
  digitalWrite(row4,LOW);

  digitalWrite(row1,HIGH); //write first row high
  if (digitalRead(col1)==HIGH){ //if the first column is now high, "1" has been pressed
    numpressed = 1;
    pressfound=true;
  }
  if (digitalRead(col2)==HIGH){ //if the second column is now high, "2" has been pressed
    numpressed = 2;
    pressfound=true;
  }
  if (digitalRead(col3)==HIGH){ //if the third column is now high, "3" has been pressed
    numpressed = 3;
    pressfound=true;
  }
  if (digitalRead(col4)==HIGH){ //if the fourth column is now high, "reset" has been pressed
    numpressed = 12;
    pressfound=true;
  }
  digitalWrite(row1,LOW); //return first row low

  digitalWrite(row2,HIGH); //write second row high
  if (digitalRead(col1)==HIGH){ //if the first column is now high, "4" has been pressed
    numpressed = 4;
    pressfound=true;
  }
  if (digitalRead(col2)==HIGH){ //if the second column is now high, "5" has been pressed
    numpressed = 5;
    pressfound=true;
  }
  if (digitalRead(col3)==HIGH){ //if the third column is now high, "6" has been pressed
    numpressed = 6;
    pressfound=true;
  }
  if (digitalRead(col4)==HIGH){ //if the fourth column is now high, "dial" has been pressed
    numpressed = 13;
    pressfound=true;
  }
  digitalWrite(row2,LOW); //return second row low

  digitalWrite(row3,HIGH); //write third row high
  if (digitalRead(col1)==HIGH){ //if the first column is now high, "7" has been pressed
    numpressed = 7;
    pressfound=true;
  }
  if (digitalRead(col2)==HIGH){ //if the second column is now high, "8" has been pressed
    numpressed = 8;
    pressfound=true;
  }
  if (digitalRead(col3)==HIGH){ //if the third column is now high, "9" has been pressed
    numpressed = 9;
    pressfound=true;
  }
  if (digitalRead(col4)==HIGH){ //if the fourth column is now high, the arrows have been pressed
    numpressed = 14;
    pressfound=true;
  }
  digitalWrite(row3,LOW); //return third row low

  digitalWrite(row4,HIGH); //write fourth row high
  if (digitalRead(col1)==HIGH){ //if the first column is now high, "shift" has been pressed
    numpressed = 10;
    pressfound=true;
  }
  if (digitalRead(col2)==HIGH){ //if the second column is now high, "0" has been pressed
    numpressed = 0;
    pressfound=true;
  }
  if (digitalRead(col3)==HIGH){ //if the third column is now high, "." has been pressed
    numpressed = 11;
    pressfound=true;
  }
  if (digitalRead(col4)==HIGH){ //if the fourth column is now high, "enter" has been pressed
    numpressed = 15;
    pressfound=true;
  }
  digitalWrite(row4,LOW); //return fourth row low

  rowshigh(); //write all rows high

    return pressfound; //function returns true if any press found, otherwise returns false
}

void definepress(){ //uses "lastnumpressed" and "timespressed" to define "letter"
  if (lastnumpressed==1){
    if (timespressed==1){
      letter='Q';
    }
    if (timespressed==2){
      letter='Z';
    }
    if (timespressed==3){
      letter='1';
    }
  }
  if (lastnumpressed==2){
    if (timespressed==1){
      letter='A';
    }
    if (timespressed==2){
      letter='B';
    }
    if (timespressed==3){
      letter='C';
    }
    if (timespressed==4){
      letter='2';
    }
  }
  if (lastnumpressed==3){
    if (timespressed==1){
      letter='D';
    }
    if (timespressed==2){
      letter='E';
    }
    if (timespressed==3){
      letter='F';
    }
    if (timespressed==4){
      letter='3';
    }
  }
  if (lastnumpressed==4){
    if (timespressed==1){
      letter='G';
    }
    if (timespressed==2){
      letter='H';
    }
    if (timespressed==3){
      letter='I';
    }
    if (timespressed==4){
      letter='4';
    }
  }
  if (lastnumpressed==5){
    if (timespressed==1){
      letter='J';
    }
    if (timespressed==2){
      letter='K';
    }
    if (timespressed==3){
      letter='L';
    }
    if (timespressed==4){
      letter='5';
    }
  }
  if (lastnumpressed==6){
    if (timespressed==1){
      letter='M';
    }
    if (timespressed==2){
      letter='N';
    }
    if (timespressed==3){
      letter='O';
    }
    if (timespressed==4){
      letter='6';
    }
  }
  if (lastnumpressed==7){
    if (timespressed==1){
      letter='P';
    }
    if (timespressed==2){
      letter='R';
    }
    if (timespressed==3){
      letter='S';
    }
    if (timespressed==4){
      letter='7';
    }
  }
  if (lastnumpressed==8){
    if (timespressed==1){
      letter='T';
    }
    if (timespressed==2){
      letter='U';
    }
    if (timespressed==3){
      letter='V';
    }
    if (timespressed==4){
      letter='8';
    }
  }
  if (lastnumpressed==9){
    if (timespressed==1){
      letter='W';
    }
    if (timespressed==2){
      letter='X';
    }
    if (timespressed==3){
      letter='Y';
    }
    if (timespressed==4){
      letter='9';
    }
  }
  if (lastnumpressed==11){
    if (timespressed==1){
      letter='.';
    }
    if (timespressed==2){
      letter='?';
    }
    if (timespressed==3){
      letter='!';
    }
    if (timespressed==4){
      letter=',';
    }
    if (timespressed==5){
      letter='\'';
    }
    if (timespressed==6){
      letter='"';
    }
    if (timespressed==7){
      letter='-';
    }
  }
}

void incrementtimespressed(){ //increment "timespressed" until at max value stored in maxtimespressed for that lastnumpressed, then roll over to 1
  if (timespressed==maxtimespressed[lastnumpressed]){ //if at the maximum,
    timespressed=1; //roll over timespressed to one
  }
  else{ //otherwise,
    timespressed++; //increment timespressed
  }
}

void dozero(){ //prints zero
  lcd.print('0'); //print 0
  lcd.setCursor(cursorx,cursory); //maintain cursor position
  dospace(); //space
}

void dospace(){ //moves cursor forward once, wraps to next line if necessary, clears and returns to top of display if at bottom
  if (cursory==1){ //if on the bottom row,
    if (cursorx==15){ //if at the end of the row,
      cursorx=0; //define new cursor position as the upper-left corner
      cursory=0;
      lcd.clear(); //clear the lcd
    }
    else{ //otherwise,
      cursorx++; //increment the cursor to the right
    }
  }
  else{ //if on the top row,
    if (cursorx==15){ //if at the end of the row,
      cursorx=0; //define new cursor position as the bottom-left corner
      cursory=1;
    }
    else{ //otherwise,
      cursorx++; //increment the cursor to the right
    }
  }
  lcd.setCursor(cursorx,cursory); //set cursor to defined location
  rowshigh(); //sets all rows high
  if (disablespacedelay){ //if the delay has been disabled,
    disablespacedelay=false; //reset its being disabled
  }
  else{ //otherwise,
    delay(preventholddelay); //delay a bit
  }
}

void doclear(){ //clears and returns to top-left of display
  cursorx=0;
  cursory=0;
  lcd.clear();
  lcd.setCursor(cursorx,cursory);
  rowshigh(); //sets all rows high
  delay(preventholddelay);
}

void dobackspace(){ //does a backspace, essentially the opposite of dospace
  if (cursory==1){
    if (cursorx==0){
      cursorx=15;
      cursory=0;
    }
    else{
      cursorx--;
    }
  }
  else{
    if (cursorx==0){
      cursorx=0;
      cursory=0;
    }
    else{
      cursorx--;
    }
  }
  lcd.setCursor(cursorx,cursory);
  lcd.print(" ");
  lcd.setCursor(cursorx,cursory);
  rowshigh(); //sets all rows high
  delay(preventholddelay);
}

void textstorage(byte mode){ //contains functions for text storage
  if (mode==1){ //regular character storage
    typedtext[positionintypedtext]=letter; //store letter that was printed to LCD in typedtext
    positionintypedtext++; //increment position in typedtext
  }
  if (mode==2){ //do a space in stored text
    typedtext[positionintypedtext]=' '; //set current position in typedtext to a space
    positionintypedtext++; //increment position in typedtext
  }
  if (mode==3){ //does a backspace in the stored text
    positionintypedtext--; //decrement position in typedtext
    typedtext[positionintypedtext]=' '; //set current position in typedtext to a space
  }
}

void outputserial(){ //output message and display remaining characters to serial console
  Serial.print("Message: ");
  Serial.println(typedtext); //print out all the text typed so far to the serial console
  charremaining=(139-(positionintypedtext)); //calculate remaining characters
  Serial.print(charremaining); //display remaining characters
  if (charremaining==1){ //making sure that the plural is only used correctly
    Serial.println(" character remaining");
  }
  else{
    Serial.println(" characters remaining");
  }
  Serial.println(); //print a blank line
  delay(preventholddelay); //delay a little to prevent continuous cycling
}
