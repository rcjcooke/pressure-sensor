#include "SerialDisplayConfiguration.hpp"

SerialDisplayConfiguration::SerialDisplayConfiguration(SerialDisplayType displayType) {
  mSerialDisplay = displayType;
}

SerialDisplayType SerialDisplayConfiguration::getSerialDisplayType() const {
  return mSerialDisplay;
}