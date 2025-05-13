#ifndef SRF05_H
#define SRF05_H

#include "Arduino.h"

class SRF05 {
  public:
    SRF05(uint8_t triggerPin, uint8_t echoPin);
    void begin();
    long getDistance(char unit = 'c');  
    bool isObjectNear(uint8_t dist);
    long getFilteredDistance(char unit = 'c');
  private:
    uint8_t _triggerPin;
    uint8_t _echoPin;
};

#endif
