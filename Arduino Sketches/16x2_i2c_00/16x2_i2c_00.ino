

#include <Keypad.h>
#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

//LCD I2C Initialization
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

long int total,num1,num2 ;
char operation,button;
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','%','/'}
};
byte rowPins[ROWS] = {2,3,4,5};// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = {6,7,8,9}; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad


void setup() {
int status;

  // initialize LCD with number of columns and rows: 
  // hd44780 returns a status from begin() that can be used to determine if initalization failed.
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    status = -status; // convert negative status value to positive number

    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }

  // initalization was successful, the backlight should be on now
  
  // Print a message to the LCD
  lcd.print("Adi Ananat Shiv");
}

void loop()
{
  // Loops are convenient for reading key press from keypad
  while(1) // First loop. Composing first number. Until operator pressed
  {
    button = kpd.getKey(); // Button read
    if (button >='0' && button <='9') // If user pressed numeric value, 1 character at a time.
    {
      lcd.clear();
      num1 = num1*10 + (button -'0'); //First operand composing
      lcd.setCursor(0,0); // Select first row on lcd
      lcd.print(num1); // Print current number1
    }
    


while(1) // Second loop. Inputting second operand. Until '=' pressed
  {
    button = kpd.getKey(); // Button read
    if (button >='0' && button <='9') // Getting chars from keypad for second number
    {
      num2 = num2*10 + (button -'0'); //Second operand composing
      lcd.setCursor(1,1); // Select second row, second column on lcd
      lcd.print(num2); // Print current operand2
    }
  }

}

}
