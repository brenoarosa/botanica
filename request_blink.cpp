#include "request_blink.h"

void blink_req_setup() {
    actions_ids[act_size] = 2;
    actions[act_size] = {2, req_blink};
    act_size++;

    unsigned long last_req_blink;
    last_req_blink = millis();

    proc_union proc = {2, {}, 0};
    add_reg_proc(&proc);
}

void req_blink(uint8_t data[], size_t data_len) {

    unsigned long current_time;
    current_time = millis();
    if(current_time - last_req_blink > 5000) {
        return;
    }

    last_req_blink = current_time;

    // prepare message
    const proc_union proc = {1, {}, 0};
    uint8_t msg[];
    size_t msg_len;

    if(is_installed(proc.action_id)) {
        add_dyn_proc(&proc);
    }
    else {
        msg_builder(emitter, proc.action_id, proc.data, proc.data_len, msg, &msg_len);
        send_msg(msg, msg_len);
    }

    return;
}
