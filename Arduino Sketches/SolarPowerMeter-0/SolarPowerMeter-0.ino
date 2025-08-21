#include <LiquidCrystal_I2C.h>

// LCD module connections

#define I2C_ADDR 0x27 //I2C adress, you should use the code to scan the adress first (0x27) here

#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


// Solar input and battery output pin definitions
const int solarVoltagePin = A0;
const int solarCurrentPin = A1;
const int batteryVoltagePin = A2;
const int batteryCurrentPin = A3;

// Energy calculation variables
unsigned long startTime;
float totalEnergy;

void setup() {
  // Initialize LCD
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight

  // Print initial messages
  lcd.setCursor(0, 0);
  lcd.print("Solar Charge Ctrl");
  lcd.setCursor(0, 1);
  lcd.print("by Saikat");
  delay(2000);

  // Clear LCD and set cursor positions
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Solar(V, I, W):");
  lcd.setCursor(0, 2);
  lcd.print("Battery(V, I, W):");

  // Initialize energy calculation variables
  startTime = millis();
  totalEnergy = 0;
}

void loop() {
  // Read analog values from pins
  float solarVoltage = analogRead(solarVoltagePin) * 0.0048828125;  // Conversion factor for 5V reference
  float solarCurrent = analogRead(solarCurrentPin) * 0.0048828125;  // Conversion factor for 5V reference
  float batteryVoltage = analogRead(batteryVoltagePin) * 0.0048828125;  // Conversion factor for 5V reference
  float batteryCurrent = analogRead(batteryCurrentPin) * 0.0048828125;  // Conversion factor for 5V reference

  // Calculate solar and battery power
  float solarPower = solarVoltage * solarCurrent;
  float batteryPower = batteryVoltage * batteryCurrent;

  // Calculate time since last energy calculation
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - startTime;
  float hours = elapsedTime / 3600000.0;  // Convert milliseconds to hours

  // Calculate energy and add to total
  float energy = batteryPower * hours;
  totalEnergy += energy;

  // Update LCD display
  lcd.setCursor(12, 0);
  lcd.print(solarVoltage, 2);
  lcd.print("V ");
  lcd.print(solarCurrent, 2);
  lcd.print("A ");
  lcd.print(solarPower, 2);
  lcd.print("W ");

  lcd.setCursor(12, 2);
  lcd.print(batteryVoltage, 2);
  lcd.print("V ");
  lcd.print(batteryCurrent, 2);
  lcd.print("A ");
  lcd.print(batteryPower, 2);
  lcd.print("W ");

  lcd.setCursor(0, 3);
  lcd.print("Total Energy: ");
  lcd.print(totalEnergy, 2);
  lcd.print(" Wh");

  // Reset start time for energy calculation
  startTime = currentTime;

  delay(1000);
}
