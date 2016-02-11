#include "actions.h"

action_union actions[MAX_ACTIONS] = {};
act_t actions_ids[MAX_ACTIONS] = {};
uint8_t act_size = 0;

bool is_installed(const act_t action_id) {

    for(uint8_t i=0; i < act_size; i++) {
        if(actions_ids[i] == action_id) {
            return true;
        }
    }

    return false;
}

void get_action(const act_t action_id, uint8_t (*function)(uint8_t*, size_t)) {
    for(uint8_t i; i < act_size; i++) {
        if(actions[i].action_id == action_id) {
            function = actions[1].function;
            return;
        }
    }
}
