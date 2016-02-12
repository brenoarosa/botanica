#pragma once

#include <Arduino.h>
#include "actions.h"
#include "manager.h"
#include "codec.h"
#include "network.h"

void blink_req_setup();
uint8_t req_blink(uint8_t data[], size_t data_len);
