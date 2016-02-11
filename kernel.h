#pragma once

#include "includes.h"
#include "comm/network.h"
#include "mod/blink.h"
#include "mod/request_blink.h"

void setup_kernel();
void msg_handler(int bytes_available);
void run_it_baby();
