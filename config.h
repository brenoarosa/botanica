#pragma once

/* network parameters */

#define NODE_ADDR 0x1

/* kernel configurations */

#define MAX_ACTIONS 20
#define MAX_REG_PROC 10
#define MAX_DYN_PROC 20
#define MAX_DATA_SIZE 10
#define MAX_MSG_SIZE 32

/* blink module */
#define BLINK_REQ_INSTALLED false
#define BLINK_INSTALLED false

/* humidity module */
#define HUM_SENSOR_INSTALLED false
#define HUM_CONTROL_INSTALLED true
#define HUM_SENSOR_PIN A0
#define HUM_MOTOR_PIN 13
// 0 to 255
#define HUM_THRESHOLD 35
#define HUM_MEASURE_INTERVAL 4000
#define HUM_MOTOR_ACTIVE 2000

/* luminosity module */
#define LUM_SENSOR_INSTALLED false
#define LUM_CONTROL_INSTALLED true
#define LUM_SENSOR_PIN A2
#define LUM_MOTOR_PIN 9
// 0 to 255
#define LUM_THRESHOLD 180
#define LUM_MEASURE_INTERVAL 1000
