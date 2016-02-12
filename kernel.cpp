#include "kernel.h"

void setup_kernel() {

    setup_net(NODE_ADDR, msg_handler);

    blink_setup();
    blink_req_setup();
}

void msg_handler(int bytes_available) {
    size_t msg_len = 0;
    uint8_t msg[MAX_MSG_SIZE];
    while (Wire.available() > 0) {
        msg[msg_len] = Wire.read();
        msg_len++;
    }

    proc_union proc = {0, {}, 0};
    addr_t emitter;
    // fix reference in proc
    msg_reader(msg, msg_len, &emitter, &proc);
    if(is_installed(proc.action_id)) {
        add_dyn_proc(&proc);
    }
}

void run_it_baby() {
    while(1) {
        proc_union proc = {0, {}, 0};
        next_proc(&proc);

        uint8_t (*function)(uint8_t*, size_t);
        get_action(proc.action_id, function);

        function(proc.data, proc.data_len);
    }
}
