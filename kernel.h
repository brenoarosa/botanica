#pragma once

#include "includes.h"
#include "network.h"
#include "blink.h"
#include "request_blink.h"
#include "hum_controller.h"
#include "hum_sensor.h"

void setup_kernel();
void msg_handler(int bytes_available);
void run_it_baby();
