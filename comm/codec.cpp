#include "codec.h"

err_t msg_builder(const addr_t emitter, const act_t action, const uint8_t data[], const size_t data_len, uint8_t msg[], size_t *msg_len) {

    msg[0] = (uint8_t) emitter;
    msg[1] = (uint8_t) action;
    for(unsigned int i = 0; i < data_len; i++) {
        msg[i+2] = data[i];
    }

    *msg_len = 2 + data_len;

    return 0;
}

err_t msg_reader(const uint8_t msg[], const size_t msg_len, addr_t *emitter, act_t *action, uint8_t data[], size_t *data_len) {

    *emitter = (addr_t) msg[0];
    *action = (act_t) msg[1];

    *data_len = msg_len - 2;

    for(unsigned int i = 0; i < *data_len; i++) {
        data[i] = msg[i+2];
    }

    return 0;
}
