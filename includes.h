#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "config.h"

// constants
#define GCALL_ADDR 0x0

// error codes
#define UNAVAILABLE_RESOURCE 1
#define INVALID_ARG 2

// types
typedef uint8_t err_t;
typedef uint8_t addr_t;
typedef uint8_t act_t;

