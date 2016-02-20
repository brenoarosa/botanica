#pragma once

#include <Arduino.h>
#include "actions.h"
#include "manager.h"

void setup_hum_controller();
uint8_t hum_controller(uint8_t data[], size_t data_len);
