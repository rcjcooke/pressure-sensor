#include <Arduino.h>

#include "SerialDisplay.hpp"

SerialDisplay::SerialDisplay(SerialDisplayConfiguration* configuration) {
  mConfigurationPtr = configuration;
}

void SerialDisplay::clearSerialDisplay() {
  switch(mConfigurationPtr->getSerialDisplayType()) {
    case SerialDisplayType::ansi_vt100:
      Serial.print("\e[2J");
      Serial.print("\e[H");
      break;
    default:
      break;
  }
}
