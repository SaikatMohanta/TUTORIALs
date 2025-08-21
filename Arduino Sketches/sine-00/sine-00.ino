const int outputPin = 9;    // The analog output pin (e.g., PWM pin)
const int amplitude = 127;  // Amplitude of the sinusoidal waveform (0-255)
const float frequency = 1.0; // Frequency of the sinusoidal waveform in Hz

void setup() {
  pinMode(outputPin, OUTPUT);
}

void loop() {
  float period = 1.0 / frequency;   // Calculate the period of the waveform
  float omega = 2.0 * PI / period;  // Calculate the angular frequency
  
  // Generate the sinusoidal waveform
  for (float t = 0.0; t < period; t += 1.0 / (frequency * 100)) {
    int outputValue = amplitude * sin(omega * t) + 128;  // Calculate the output value
    analogWrite(outputPin, outputValue);  // Write the value to the analog output pin
    delay(10);  // Adjust the delay as needed for the desired frequency
  }
}
