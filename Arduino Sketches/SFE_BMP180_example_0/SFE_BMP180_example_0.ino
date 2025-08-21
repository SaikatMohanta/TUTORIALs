#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp;

void setup() {
  Serial.begin(9600);

  if (!bmp.begin()) {
    Serial.println("BMP180 sensor not found. Check wiring!");
    while (1);
  }
}

void loop() {
  char status;
  double T, P, p0;

  status = bmp.startTemperature();
  if (status != 0) {
    delay(status);

    status = bmp.getTemperature(T);
    if (status != 0) {
      status = bmp.startPressure(3);
      if (status != 0) {
        delay(status);

        status = bmp.getPressure(P, T);
        if (status != 0) {
          p0 = bmp.sealevel(P, 0); // Calculate sea level pressure at altitude 0 (adjust accordingly)

          Serial.print("Temperature: ");
          Serial.print(T, 2);
          Serial.print(" °C");

          Serial.print("Pressure: ");
          Serial.print(P, 2);
          Serial.print(" Pa");

          Serial.print("Sea Level Pressure: ");
          Serial.print(p0, 2);
          Serial.print(" Pa");

          double altitude = bmp.altitude(P, p0); // Calculate altitude based on sea level pressure
          Serial.print("Altitude: ");
          Serial.print(altitude, 2);
          Serial.print(" meters");

          Serial.println("-------------------");
        }
      }
    }
  }

  delay(2000);
}
