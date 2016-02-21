#pragma once

#include <Arduino.h>
#include "actions.h"
#include "manager.h"
#include <Servo.h>

void setup_lum_controller();
uint8_t lum_controller(uint8_t data[], size_t data_len);
