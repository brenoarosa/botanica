#pragma once

#include "includes.h"
#include "proc/manager.h"

err_t msg_builder(const addr_t emitter, const proc_union proc, uint8_t msg[], size_t *msg_len);

err_t msg_reader(const uint8_t msg[], const size_t msg_len, addr_t *emitter, proc_union *proc);
