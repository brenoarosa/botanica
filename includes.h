#include <stdint.h>
#include <stdlib.h>

// constants
#define MAX_REG_PROCS 20
#define MAX_DYN_PROCS 15
#define GCALL_ADDR 0x00

// error codes
#define UNAVAILABLE_RESOURCE 1
#define INVALID_ARG 2

// types
typedef uint8_t err_t;
typedef uint8_t addr_t;
typedef uint8_t act_t;

