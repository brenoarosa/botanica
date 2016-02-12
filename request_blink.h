#pragma once

#include "actions.h"
#include "proc/manager.h"
#include "comm/codec.h"
#include "comm/network.h"

void blink_req_setup();
void req_blink(uint8_t data[], size_t data_len);
