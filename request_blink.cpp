#include "request_blink.h"

extern action_union actions[];
extern uint8_t act_size;

unsigned long last_req_blink;

uint8_t req_blink(uint8_t data[], size_t data_len) {

    unsigned long current_time;
    current_time = millis();

    if((current_time-last_req_blink) < 5000) {
        return 0;
    }

    last_req_blink = current_time;

    // prepare message
    const proc_union proc = {1, {}, 0};
    uint8_t msg[MAX_MSG_SIZE];
    size_t msg_len;

    if(is_installed(proc.action_id)) {
        add_dyn_proc(&proc);
    }
    else {
        addr_t emitter = NODE_ADDR;
        msg_builder(emitter, proc, msg, &msg_len);
        send_msg(msg, msg_len);
    }

    return 0;
}

void blink_req_setup() {

    action_union act = {2, req_blink};

    actions[act_size] = act;
    act_size++;

    last_req_blink = millis();

    proc_union proc = {2, {}, 0};
    add_reg_proc(&proc);
}
