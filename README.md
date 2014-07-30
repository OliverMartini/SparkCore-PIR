SparkCore-PIR
=============

A simple PIR libary for Spark Core.

Components Required
---
- PIR (motion) sensor (get at [adafruit.com](adafruit.com))

Example Usage
---

See this [example](firmware/examples/ws2801-example.cpp) for details, or, in a nutshell:

```cpp
OM::Pir pir(D0);
void setup() {
  pir.setupPinMode();
}
void loop() {
  if (pir.calibrated()) {
    pir.readTheSensor();
    // calibrate and read the sensor. When value changed, perform action
  }
}
```

Useful Links
---

- PIR Guide: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/overview
- Sprint 7: Spark.publish() released! Let’s build a cloud-connected motion detector: http://community.spark.io/t/sprint-7-spark-publish-released-lets-build-a-cloud-connected-motion-detector/3391



