const int pwmPin = 9;  // Set the PWM pin number
float frequency = 1000000.0; // Set the frequency of the sinh(t)
float amplitude = 230; // Set the amplitude of the signal
unsigned long previousMillis = 0;
unsigned long interval = 2; // Interval between PWM updates

// Custom hyperbolic sine function
float customSinh(float x) {
  return (exp(x) - exp(-x)) / 2.0;
}

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Calculate the hyperbolic sine value at the current time
    float time = currentMillis / 1000.0; // Convert to seconds
    float sinhValue = amplitude * customSinh(frequency * time);

    // Map the sinh value to the PWM range (0-255) and write to the PWM pin
    analogWrite(pwmPin, map(sinhValue, -amplitude, amplitude, 0, 255));
  }
}
