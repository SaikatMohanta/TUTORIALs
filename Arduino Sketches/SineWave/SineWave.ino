// Define the output pin
int outputPin = 3;

// Define the frequency of the sine wave
float frequency = 50; // in Hz

void setup() {
  // Set the output pin as an output
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // Generate a sine wave using the tone() function
  tone(outputPin, 1000 * frequency);
  delay(1);
}
