#include "SRF05.h"

SRF05::SRF05(uint8_t triggerPin, uint8_t echoPin) {
  _triggerPin = triggerPin;
  _echoPin = echoPin;
}

void SRF05::begin() {
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

long SRF05::getDistance(char unit) {
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW);

  long duration = pulseIn(_echoPin, HIGH);

  if (unit == 'i') {
    return duration / 148;  // 1 inch = 2.54cm
  } else {
    return duration / 58;  
  }
}
bool SRF05:: isObjectNear(uint8_t dist){
  long distance = getDistance("c");
  return (distance > 0 && distance <= dist);

}
long SRF05::getFilteredDistance(char unit){
  long distance ;
  if (unit == 'i') {
    for(int i =0 ; i<=5; i++){
      distance += getDistance('i');
      
    }
    distance = distance / 5; 
    return distance / 148;  
  }else {
    for(int i =0 ; i<=5; i++){
       distance += getDistance();
      
    }
    distance = distance / 5; 
    return distance / 58;  
  }
  
}