/*
 * PIR LIBRARY FOR SPARK CORE
 * =======================================================
 * Copy this into a new application at:
 * https://www.spark.io/build and go nuts!
 * -------------------------------------------------------
 *  Author: Oliver Martini
 *    Date: Jul 29th 2014
 * =======================================================
 * https://github.com/olivermartini/SparkCore-PIR
 */

// NOTE/NUANCE: When including WITHIN a library, no sub-dir prefix is needed.
#include "om-pir.h"

// Constructor 
OM::Pir::Pir(int _pin, bool _state, int _pinState, int _calibrateTime) {
    pin = _pin;                         // choose the input pin (for PIR sensor)
    state = _state;                     // we start, assuming no motion detected
    pinState = _pinState;               // variable for reading the pin status
    calibrateTime = _calibrateTime;     // wait for the thingy to calibrate
}

// Constructor 
OM::Pir::Pir(int _pin) {
    Pir(_pin, LOW, 0, 1000);
}

// Initializers that should be called in the `setup()` function
void OM::Pir::setupPinMode() {
    pinMode(pin, INPUT);
}

// Main API functions that the library provides
// typically called in `loop()` or `setup()` functions
bool OM::Pir::calibrated() {
    return millis() - calibrateTime > 0;
}
 
void OM::Pir::readTheSensor() {
    pinState = digitalRead(pin);
}

// Getters
int OM::Pir::getPin() {
    return pin;
}

bool OM::Pir::getPinState(){
    return pinState;
}

bool OM::Pir::getState(){
    return state;
}

bool OM::Pir::isHigh()
{
  return state == HIGH ? true : false;
}

// Setters
void OM::Pir::setHigh() {
    state = HIGH;
}

void OM::Pir::setLow() {
    state = LOW;
}