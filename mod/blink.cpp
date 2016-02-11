#include "actions.h"

void blink_setup() {
    actions_ids[act_size] = 1;
    actions[act_size] = {1, blink};
    act_size++;

    pinMode(13, OUTPUT);
}

void blink(uint8_t data[], size_t data_len) {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}
