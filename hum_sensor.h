#pragma once

#include <Arduino.h>
#include "actions.h"
#include "manager.h"
#include "codec.h"
#include "network.h"

void setup_hum_sensor();
uint8_t hum_measure(uint8_t data[], size_t data_len);
