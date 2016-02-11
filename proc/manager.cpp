#include "manager.h"

// Global proccessing variables
proc_union reg_list[MAX_REG_PROCS];
uint8_t reg_queue_size = 0;
uint8_t reg_queue_pointer = 0;

proc_union dyn_queue[MAX_DYN_PROCS];
uint8_t dyn_queue_size;

uint8_t setup_dyn_proc() {
    dyn_queue[0].action_id = 0;
    dyn_queue[0].data_len = 0;

    dyn_queue_size = 0;

    return 0;
}

uint8_t add_dyn_proc(const proc_union *proc) {
    if(dyn_queue_size == MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    dyn_queue[dyn_queue_size - 1].action_id = (*proc).action_id;
    memcpy(dyn_queue[dyn_queue_size - 1].data, (*proc).data, (*proc).data_len);
    dyn_queue[dyn_queue_size - 1].data_len = (*proc).data_len;

    dyn_queue_size++;
    return 0;
}

uint8_t remove_dyn_proc(uint8_t index) {

    if(index > (dyn_queue_size-1)) {
        return INVALID_ARG;
    }

    // inefficient but fixed length
    for(uint8_t i = index; i < (dyn_queue_size-1); i++) {
        dyn_queue[i].action_id = dyn_queue[i+1].action_id;
        memcpy(dyn_queue[i].data, dyn_queue[i+1].data, dyn_queue[i+1].data_len);
        dyn_queue[i].data_len = dyn_queue[i+1].data_len;
    }

    dyn_queue_size--;
    return 0;
}

uint8_t next_dyn(proc_union *proc) {

    if(dyn_queue_size == 0) {
        return EMPTY_QUEUE;
    }

    (*proc).action_id = dyn_queue[0].action_id;
    (*proc).data_len = dyn_queue[0].data_len;
    memcpy((*proc).data, dyn_queue[0].data, dyn_queue[0].data_len);

    return 0;
}

uint8_t add_reg_proc(const proc_union *proc) {

    if(reg_queue_size == MAX_DYN_PROCS) {
        return UNAVAILABLE_RESOURCE;
    }

    reg_queue_size++;

    reg_list[reg_queue_size-1].action_id = (*proc).action_id;
    memcpy(reg_list[reg_queue_size-1].data, (*proc).data, (*proc).data_len);
    reg_list[reg_queue_size-1].data_len = (*proc).data_len;

    return 0;
}

uint8_t next_reg(proc_union *proc) {

    if(reg_queue_size == 0) {
        return EMPTY_QUEUE;
    }


    (*proc).action_id = dyn_queue[reg_queue_pointer].action_id;
    (*proc).data_len = dyn_queue[reg_queue_pointer].data_len;
    memcpy((*proc).data, dyn_queue[reg_queue_pointer].data, dyn_queue[reg_queue_pointer].data_len);

    reg_queue_pointer++;

    if(reg_queue_pointer == reg_queue_size) {
        reg_queue_pointer = 0;
    }

    return 0;
}

uint8_t next_proc(proc_union *proc) {

    uint8_t func_return = next_dyn(proc);

    if(func_return != EMPTY_QUEUE) {
        return 0;
    }

    func_return = next_reg(proc);
    if(func_return != EMPTY_QUEUE) {
        return 0;
    }

    return EMPTY_QUEUE;
}
