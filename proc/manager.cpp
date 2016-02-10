// Global proccessing variables
proc_queue reg_list[MAX_REG_PROCS];
uint8_t reg_queue_size = 0;
uint8_t reg_queue_pointer = 0;

proc_queue dyn_queue[MAX_DYN_PROCS + 1];
uint8_t dyn_queue_size;

/*
* @brief   Setup dynamic queue
*
* @return  Error status
*/
uint8_t setup_dyn_proc() {
    dyn_queue[0].action_id = 0;
    dyn_queue[0].data_len = 0;

    dyn_queue_size = 0;

    return 0;
}

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
uint8_t add_dyn_proc(const act_t action_id, const uint8_t data[], const size_t data_len) {
    if(dyn_queue_size == MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    dyn_queue[dyn_queue_size - 1].action_id = action_id;
    memcpy(dyn_queue[dyn_queue_size - 1].action_data, data, data_len);
    dyn_queue[dyn_queue_size - 1].data_len = data_len;

    dyn_queue_size++;
    return 0;
}

/*
* @brief   Removes action to dynamic queue
* @usage   Action will be removed from dynamic FIFO
*
* @param   index - in - index in the queue (normally = 0)
*
* @return  Error status
*/
uint8_t remove_dyn_proc(uint8_t index) {

    if(index > (dyn_queue_size-1)) {
        return INVALID_ARG;
    }

    // inefficient but fixed length
    for(uint8_t i = index; i < (dyn_queue_size-1); i++) {
        dyn_queue[i].action_id = dyn_queue[i+1].action_id;
        memcpy(dyn_queue[i].action_data, dyn_queue[i+1].action_data, dyn_queue[i+1].data_len);
        dyn_queue[i].data_len = dyn_queue[i+1].data_len;
    }

    dyn_queue_size--;
    return 0;
}

uint8_t next_dyn(act_t *action_id, uint8_t data[], size_t *data_len) {

    if(dyn_queue_size == 0) {
        return EMPTY_QUEUE;
    }

    *action_id = dyn_queue[0].action_id;
    *data_len = dyn_queue[0].data_len;
    memcpy(data, dyn_queue[0].action_data, dyn_queue[0].data_len);

    return 0;
}

/*
* @brief   Adds action to regular actions list
* @usage   Action will be added to regular list
*
* @param   action_id - in - action id
* @param   data - in - data (parameters) to be passed for action
* @param   data_len - in - data length
*
* @return  Error status
*/
uint8_t add_reg_proc(const act_t action_id, const uint8_t data[], const size_t data_len) {

    if(reg_queue_size == MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    reg_queue_size++;

    reg_list[reg_queue_size-1].action_id = action_id;
    memcpy(reg_list[reg_queue_size-1].action_data, data, data_len);
    reg_list[reg_queue_size-1].data_len = data_len;

    return 0;
}

uint8_t next_reg(act_t *action_id, uint8_t data[], size_t *data_len) {

    if(reg_queue_size == 0) {
        return EMPTY_QUEUE;
    }


    *action_id = dyn_queue_size[reg_queue_pointer].action_id;
    *data_len = dyn_queue_size[reg_queue_pointer].data_len;
    memcpy(data, dyn_queue[reg_queue_pointer].action_data, dyn_queue[reg_queue_pointer].data_len);

    reg_queue_pointer++;

    if(reg_queue_pointer == reg_queue_size) {
        reg_queue_pointer = 0;
    }

    return 0;
}

/*
* @brief   Pointer to next action
* @usage
*
* @param   next_act - out - pointer to next action
*
* @return  Error status
*/
uint8_t next_proc(act_t *action_id, uint8_t data[], size_t *data_len) {

    uint8_t func_return = next_dyn(action_id, data[], data_len);

    if(func_return != EMPTY_QUEUE) {
        return 0;
    }

    func_return = next_reg(action_id, data[], data_len);
    if(func_return != EMPTY_QUEUE) {
        return 0;
    }

    return EMPTY_QUEUE;
}
