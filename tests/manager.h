#include "includes.h"

struct proc_queue_union {
    act_t action_id;
    uint8_t action_data[];
    size_t data_len;
};

uint8_t setup_dyn_proc();

uint8_t add_dyn_proc(const act_t action_id, const uint8_t data[], const size_t data_len);

uint8_t remove_dyn_proc(uint8_t index);
