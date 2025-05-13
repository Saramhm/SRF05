# SRF05 Arduino Library

A simple Arduino library for the SRF05 ultrasonic distance sensor.

## Usage

```cpp
#include <SRF05.h>

SRF05 sensor(7, 6);  // Trigger on pin 7, Echo on pin 6
bool obj_near;
void setup() {
  Serial.begin(9600);
  sensor.begin();
}
void loop() {
  long distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  long distance_inch = sensor.getDistance('i');
  Serial.print("Distance: ");
  Serial.print(distance_inch);
  Serial.println(" inch");
  delay(500);
  long distance23 = sensor.getFilteredDistance("c");
  if (sensor.isObjectNear(30)) {
    Serial.println("object is near");
  }
}

```
