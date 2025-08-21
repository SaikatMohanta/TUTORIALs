#define S2 6
#define S3 7
#define sensorOut 8

double features[3];

void setup() {
  Serial.begin(115200);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
}

void loop() {
  readRGB();
  printFeatures();
  delay(100);
}

int readComponent(bool s2, bool s3) {
  delay(10);
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);

  return pulseIn(sensorOut, LOW);
}

void readRGB() {
  features[0] = readComponent(LOW, LOW);
  features[1] = readComponent(HIGH, HIGH);
  features[2] = readComponent(LOW, HIGH);
}

void printFeatures() {
    const uint16_t numFeatures = sizeof(features) / sizeof(float);
    
    for (int i = 0; i < numFeatures; i++) {
        Serial.print(features[i]);
        Serial.print(i == numFeatures - 1 ? 'n' : ',');
    }
}
