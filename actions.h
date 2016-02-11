/*
 * actions.h - List of actions
 */

#pragma once

#include "includes.h"

struct action_union {
    act_t action_id;
    uint8_t (*function)(uint8_t data[], size_t data_len);
};

bool is_installed(const act_t action_id);

void get_action(const act_t action_id, uint8_t (*function)(uint8_t*, size_t));
