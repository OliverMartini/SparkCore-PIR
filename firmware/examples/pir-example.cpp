#include "om-pir/om-pir.h"

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
 
/*
 * Connected sensor
 * Spark.publish() + PIR motion sensor = awesome
 * Thanks to Adafruit and zach for the reference and inspiration
 */

// Initialize objects from the lib; be sure not to call anything
// that requires hardware be initialized here, put those in setup()
OM::Pir pir(D0);

void setup() {
    // Call functions on initialized library objects that require hardware
    // to be wired up correct and available.
    pir.setupPinMode();
    Serial.begin(9600);
}

void loop() {
    // Use the library's initialized objects and functions
    if (pir.calibrated()) {
        pir.readTheSensor();
        reportTheData();
    }
}


void reportTheData() {
    if (pir.getPinState() == HIGH) {
        if (pir.getState() == LOW) {
            // we have just turned on
            Serial.println("Motion detected!");
            Spark.publish("om-pir/pir");
            // We only want to print on the output change, not state
            pir.setHigh();
        }
    }
    else {
        if (pir.getState() == HIGH) {
            // we have just turned off
            Serial.println("Motion ended!");
            // We only want to print on the output change, not state
            pir.setLow();
        }
    }
}

