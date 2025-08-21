#include <Wire.h>

int16_t ax, ay, az;
int16_t gx, gy, gz;

int16_t ax_offset, ay_offset, az_offset;
int16_t gx_offset, gy_offset, gz_offset;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Record the offsets for the accelerometer and gyroscope
  ax_offset = 0;
  ay_offset = 0;
  az_offset = 0;
  gx_offset = 0;
  gy_offset = 0;
  gz_offset = 0;

  for (int i = 0; i < 500; i++) {
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 14, true);
    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();
    az = Wire.read() << 8 | Wire.read();
    Wire.read(); // Temperature, not needed
    gx = Wire.read() << 8 | Wire.read();
    gy = Wire.read() << 8 | Wire.read();
    gz = Wire.read() << 8 | Wire.read();
    ax_offset += ax;
    ay_offset += ay;
    az_offset += az;
    gx_offset += gx;
    gy_offset += gy;
    gz_offset += gz;
    delay(2);
  }

  ax_offset /= 500;
  ay_offset /= 500;
  az_offset /= 500;
  gx_offset /= 500;
  gy_offset /= 500;
  gz_offset /= 500;
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14, true);
  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();
  Wire.read(); // Temperature, not needed
  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();

  // Subtract the offsets from the raw data
  ax -= ax_offset;
  ay -= ay_offset;
  az -= az_offset;
  gx -= gx_offset;
  gy -= gy_offset;
  gz -= gz_offset;

  Serial.print("Accelx: ");
  Serial.print(ax);
  Serial.print(" ");
  Serial.print("Accely: ");
  Serial.print(ay);
  Serial.print(" ");
  Serial.print("Accelz: ");
  Serial.print(az);
  Serial.print(" ");

  Serial.print("Accel: ");
  Serial.print(gx);
  Serial.print(" ");
  Serial.print("Accel: ");
  Serial.print(gy);
  Serial.print(" ");
  Serial.print("Accel: ");
  Serial.print(gz);
  Serial.print(" ");

  delay(500);
}
