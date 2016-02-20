#pragma once

/* network parameters */

#define NODE_ADDR 0x1

/* kernel configurations */

#define MAX_ACTIONS 20
#define MAX_REG_PROC 10
#define MAX_DYN_PROC 20
#define MAX_DATA_SIZE 10
#define MAX_MSG_SIZE 32

/* humidity module */
#define HUM_SENSOR_PIN A0
#define HUM_MOTOR_PIN 22
// 0 to 255
#define HUM_THRESHOLD 125
#define HUM_MEASURE_INTERVAL 1000
