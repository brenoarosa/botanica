// Global proccessing variables
proc_queue reg_list[MAX_REG_PROCS];
uint8_t last_reg_index;
uint8_t reg_queue_pointer;

proc_queue dyn_queue[MAX_DYN_PROCS + 1];
uint8_t next_dyn_index;

/*
* @brief   Setup dynamic queue
*
* @return  Error status
*/
uint8_t setup_dyn_proc() {
    dyn_queue[0].action_id = 0;
    dyn_queue[0].data_len = 0;

    next_dyn_index = 0;

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
    if(next_dyn_index > MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    dyn_queue[next_dyn_index].action_id = action_id;
    memcpy(dyn_queue[next_dyn_index].action_data, data, data_len);
    dyn_queue[next_dyn_index].data_len = data_len;

    next_dyn_index++;
    //setup next
    dyn_queue[next_dyn_index].action_id = 0;
    dyn_queue[next_dyn_index].data_len = 0;

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

    if(index == next_dyn_index) {
        return 0;
    }

    if(index > next_dyn_index) {
        return INVALID_ARG;
    }

    // inefficient but fixed length
    for(uint8_t i = index; i < next_dyn_index; i++) {
        dyn_queue[i].action_id = dyn_queue[i+1].action_id;
        memcpy(dyn_queue[i].action_data, dyn_queue[i+1].action_data, dyn_queue[i+1].data_len);
        dyn_queue[i].data_len = dyn_queue[i+1].data_len;
    }

    next_dyn_index--;

    return 0;
}

uint8_t next_dyn(act_t *action_id, uint8_t data[], size_t *data_len) {

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

    if(last_reg_index == MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    last_reg_index++;

    reg_list[last_reg_index].action_id = action_id;
    memcpy(reg_list[last_reg_index].action_data, data, data_len);
    reg_list[last_reg_index].data_len = data_len;

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
uint8_t next_proc(act_t *action_id, uint8_t data[], size_t *data_len);
