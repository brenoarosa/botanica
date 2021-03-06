#pragma once

#include "includes.h"
#include <string.h>

#define EMPTY_QUEUE 10

struct proc_union {
    act_t action_id;
    uint8_t data[MAX_DATA_SIZE];
    size_t data_len;
};

/*
* @brief   Setup dynamic queue
*
* @return  Error status
*/
uint8_t setup_dyn_proc();

/*
* @brief   Adds action to dynamic queue
* @usage   Action will be added to dynamic FIFO
*
* @param   action_id - in - action id
* @param   data - in - data (parameters) to be passed for action
* @param   data_len - in - data length
*
* @return  Error status
*/
uint8_t add_dyn_proc(const proc_union *proc);

uint8_t remove_dyn_proc();

/*
* @brief   Removes action to dynamic queue
* @usage   Action will be removed from dynamic FIFO
*
* @param   index - in - index in the queue (normally = 0)
*
* @return  Error status
*/
uint8_t remove_dyn_proc(uint8_t index);

uint8_t next_dyn(proc_union *proc);

/*
* @brief   Adds action to regular actions list
* @usage   Action will be the add to regular list
*
* @param   action_id - in - action id
* @param   data - in - data (parameters) to be passed for action
* @param   data_len - in - data length
*
* @return  Error status
*/
uint8_t add_reg_proc(const proc_union *proc);

uint8_t next_reg(proc_union *proc);

/*
* @brief   Pointer to next action
* @usage
*
* @param   next_act - out - pointer to next action
*
* @return  Error status
*/
uint8_t next_proc(proc_union *proc);
