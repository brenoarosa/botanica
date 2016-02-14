/*
 * actions.h - List of actions
 */

#pragma once

#include "includes.h"

typedef uint8_t (*actptr_t)(uint8_t*, size_t);

struct action_union {
    act_t action_id;
    actptr_t function;
};

void register_action(action_union);

bool is_installed(const act_t);

void get_action(const act_t, actptr_t&);
