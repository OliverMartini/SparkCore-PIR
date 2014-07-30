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

#ifndef _OM_PIR
#define _OM_PIR

// Make library cross-compatiable
// with Arduino, GNU C++ for tests, and Spark.
//#if defined(ARDUINO) && ARDUINO >= 100
//#include "Arduino.h"
//#elif defined(SPARK)
//#include "application.h"
//#endif

// TEMPORARY UNTIL the stuff that supports the code above is deployed to the build IDE
#include "application.h"

namespace OM
{
    class Pir {
        private:
            int pin;
            bool state;
            bool pinState;
            int calibrateTime;
    
        public:
            Pir(int _pin, bool _pirState, int _pinState, int _calibrateTime);
            Pir(int _pin);
            void setupPinMode();
            bool calibrated();
            void readTheSensor();
            int getPin();
            bool getPinState();
            bool getState();
            bool isHigh();
            void setHigh();
            void setLow();
    };
}

#endif