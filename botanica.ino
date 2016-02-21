#include "kernel.h"

void setup() {

    Serial.begin(57600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }

    Serial.println("Setting up kernel.");
    setup_kernel();

    if(BLINK_INSTALLED || BLINK_REQ_INSTALLED) {
        Serial.println("Setting up blink module.");
        if(BLINK_INSTALLED) {
            blink_setup();
        }
        if(BLINK_REQ_INSTALLED) {
            blink_req_setup();
        }
    }

    if(HUM_SENSOR_INSTALLED || HUM_CONTROL_INSTALLED) {
        Serial.println("Setting up Humidity module.");
        if(HUM_SENSOR_INSTALLED) {
            setup_hum_sensor();
        }
        if(HUM_CONTROL_INSTALLED) {
            setup_hum_controller();
        }
    }

    if(LUM_SENSOR_INSTALLED || LUM_CONTROL_INSTALLED) {
        Serial.println("Setting up Luminosity module.");
        if(LUM_SENSOR_INSTALLED) {
            setup_lum_sensor();
        }
        if(LUM_CONTROL_INSTALLED) {
            setup_lum_controller();
        }
    }

    Serial.println("End kernel setup.");
}

void loop() {
  run_it_baby();
}
