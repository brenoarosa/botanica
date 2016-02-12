#include "blink.h"

extern action_union actions[];
extern act_t actions_ids[];
extern uint8_t act_size;

uint8_t blink_pin(uint8_t data[], size_t data_len) {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);

    return 0;
}

void blink_setup() {

    actions_ids[act_size] = 1;

    action_union act = {1, blink_pin};
    actions[act_size] = act;
    act_size++;

    pinMode(13, OUTPUT);
}

