#include "kernel.h"

void setup() {
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Setting up kernel.");
  setup_kernel();

  Serial.println("Setting up Humidity module.");
  setup_hum_controller();
  setup_hum_sensor();

  Serial.println("End kernel setup.");
}

void loop() {
  run_it_baby();
}
