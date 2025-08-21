// Solar input pin
const int solarPin = A0;

// Battery output pin
const int batteryPin = 9;

// PWM duty cycle variables
int dutyCycle = 0;
int pwmFrequency = 1000;

void setup() {
  // Set battery pin as output
  pinMode(batteryPin, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read solar input voltage
  int solarValue = analogRead(solarPin);

  // Map the solar value to a duty cycle percentage (0-100)
  dutyCycle = map(solarValue, 0, 1023, 0, 100);

  // Print the solar voltage and duty cycle
  float solarVoltage = solarValue * (5.0 / 1023.0);
  Serial.print("Solar Voltage: ");
  Serial.print(solarVoltage);
  Serial.print("V\tDuty Cycle: ");
  Serial.print(dutyCycle);
  Serial.println("%");

  // Update the PWM signal
  analogWrite(batteryPin, (dutyCycle * 255) / 100);
  
  delay(1000);
}
