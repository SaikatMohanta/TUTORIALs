// Libraries
#include <PID_v1.h>
#include <LiquidCrystal.h>
#include <Encoder.h>

// Constants
const int lm35Pin = A0;
const int relayPin = 8;
const int backlightPin = 9;
const int buttonPin = 10;
const int backlightTimeout = 5000;
const double setpointDefault = 50.0;
const double kpDefault = 5.0;
const double kiDefault = 1.0;
const double kdDefault = 0.5;

// Variables
double setpoint = setpointDefault;
double kp = kpDefault;
double ki = kiDefault;
double kd = kdDefault;
int brightness = 100;
int backlight = LOW;
int backlightTimeoutCounter = 0;

// PID objects
double input, output;
PID pid(&input, &output, &setpoint, kp, ki, kd, DIRECT);

// LCD object
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Encoder object
Encoder knob(6, 7);
long position = 0;

// Setup function
void setup() {
  // Set pin modes
  pinMode(relayPin, OUTPUT);
  pinMode(backlightPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize LCD
  lcd.begin(16, 2);

  // Set up PID controller
  pid.SetMode(AUTOMATIC);
  pid.SetSampleTime(1000);

  // Display initial values on LCD
  updateDisplay();
}

// Main loop function
void loop() {
  // Read temperature from LM35 sensor
  input = analogRead(lm35Pin) * 0.48875;

  // Update PID controller
  pid.Compute();

  // Adjust relay based on PID output
  if (output > 0) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  // Handle encoder menu
  position += knob.read();
  position = constrain(position, 0, 4);

  switch (position) {
    case 0:
      // Setpoint menu
      setpoint = map(knob.read(), -4, 4, setpoint - 10, setpoint + 10);
      setpoint = constrain(setpoint, 0, 100);
      updateDisplay();
      break;

    case 1:
      // Kp menu
      kp += knob.read() / 10.0;
      kp = constrain(kp, 0, 10);
      updateDisplay();
      break;

    case 2:
      // Ki menu
      ki += knob.read() / 100.0;
      ki = constrain(ki, 0, 1);
      updateDisplay();
      break;

    case 3:
      // Kd menu
      kd += knob.read() / 10.0;
      kd = constrain(kd, 0, 1);
      updateDisplay();
      break;

    case 4:
      // Backlight menu
      if (digitalRead(buttonPin) == LOW) {
        backlight = !backlight;
        backlightTimeoutCounter = 0;
      }

      if (backlight == HIGH) {
        analogWrite(backlightPin, map(brightness, 0, 100, 0, 255));
        backlightTimeoutCounter = min(backlightTimeoutCounter + 1, backlightTimeout);
      } else
        {
    analogWrite(backlightPin, 0);
  }
  break;
}

// Handle backlight timeout
if (backlightTimeoutCounter >= backlightTimeout) {
backlight = LOW;
analogWrite(backlightPin, 0);
}

// Delay for loop cycle
delay(100);
}

// Update LCD display with current values
void updateDisplay() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SP: ");
    lcd.print(setpoint, 1);
    lcd.setCursor(0, 1);
    lcd.print("P:");
    lcd.print(kp, 1);
    lcd.print(" I:");
    lcd.print(ki, 2);
    lcd.print(" D:");
    lcd.print(kd, 1);
    lcd.print(" ");
    
    // Display backlight status
    lcd.setCursor(14, 0);
    if (backlight == HIGH) {
    lcd.print("*");
    } else {
    lcd.print(" ");
  } 
}
