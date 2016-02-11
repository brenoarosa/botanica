/*
 * actions.h - List of actions
 */

struct action_union {
    act_t action_id;
    uint8_t (*function)(uint8_t data[], size_t data_len);
};

action_union actions[MAX_ACTIONS] = {};
act_t actions_ids[MAX_ACTIONS] = {};
uint8_t act_size = 0;

bool is_installed(const act_t action_id);

void get_action(const act_t action_id, uint8_t (*function)(uint8_t, size_t));
