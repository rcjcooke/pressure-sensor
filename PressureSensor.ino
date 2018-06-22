#include "SerialDebugger.hpp"

/*******************************
 * Global variables definitions
 *******************************/
// The Arduino analogue input pin for the pressure sensor
static const uint8_t SENSOR_INPUT_PIN = A4;

// Real Value data point for calibration / kPa in this case
static const float CALIBRATION_REAL_DATA_POINT = 50;
// Equivalent raw sensor value data point for calibration
static const float CALIBRATION_RAW_DATA_POINT = 886;
// The sensor output when the real value is zero for calibration
static const float CALIBRATION_ZERO_RAW_DATA_POINT = 597;

// NOTE: AS THESE ARE STATIC CONST THE ARE CALCULATED AND SUBSTITUTED DURING COMPILATION NOT ON THE ARDUINO
// The multiplier to get real unit values from the raw sensor value / kPa in this case
static const float CORRECTION_FACTOR = CALIBRATION_REAL_DATA_POINT/(CALIBRATION_RAW_DATA_POINT - CALIBRATION_ZERO_RAW_DATA_POINT);
// The sensor value when the real value is zero
static const float CORRECTION_ZERO_POINT = -CORRECTION_FACTOR * CALIBRATION_ZERO_RAW_DATA_POINT;

// The serial output interface
SerialDebugger* mDebugger;

/*******************************
 * Setup functions
 *******************************/
void setup() {
  // Note: this also starts the serial interface at a baud rate of 115200 bps
  mDebugger = new SerialDebugger();
}

/*******************************
 * Main loop
 *******************************/
void loop() {
  int sensorRawValue = analogRead(SENSOR_INPUT_PIN);
  float realValue = sensorRawValue * CORRECTION_FACTOR + CORRECTION_ZERO_POINT;

  mDebugger->updateValue("Raw Sensor Value / bits", sensorRawValue);
  mDebugger->updateValue("Pressure / kPa", realValue);
  mDebugger->printUpdate();
}


