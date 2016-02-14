#include "actions.h"

action_union actions[MAX_ACTIONS] = {};
uint8_t act_size = 0;

void register_action(action_union act) {

    actions[act_size] = act;
    act_size++;

    return;
}

bool is_installed(const act_t action_id) {

    for(uint8_t i=0; i < act_size; i++) {
        if(actions[i].action_id == action_id) {
            return true;
        }
    }

    return false;
}

void get_action(const act_t action_id, actptr_t& function) {

    for(uint8_t i=0; i < act_size; i++) {
        if(actions[i].action_id == action_id) {
            function = actions[i].function;
            return;
        }
    }
}
