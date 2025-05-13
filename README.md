# SRF05 Arduino Library

A simple Arduino library for the SRF05 ultrasonic distance sensor.

## Usage

```cpp
#include <SRF05.h>

SRF05 sensor(7, 6);

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  long distance = sensor.getDistanceCM();
  Serial.println(distance);
  delay(500);
}
```
