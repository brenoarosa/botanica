#include "codec.h"

err_t msg_builder(const addr_t emitter, const proc_union proc, uint8_t msg[], size_t *msg_len) {

    msg[0] = (uint8_t) emitter;
    msg[1] = (uint8_t) proc.action_id;
    for(unsigned int i = 0; i < proc.data_len; i++) {
        msg[i+2] = proc.data[i];
    }

    *msg_len = 2 + proc.data_len;

    return 0;
}

err_t msg_reader(const uint8_t msg[], const size_t msg_len, addr_t *emitter, proc_union *proc) {

    *emitter = (addr_t) msg[0];
    (*proc).action_id = (act_t) msg[1];

    (*proc).data_len = msg_len - 2;

    for(unsigned int i = 0; i < (*proc).data_len; i++) {
        (*proc).data[i] = msg[i+2];
    }

    return 0;
}
