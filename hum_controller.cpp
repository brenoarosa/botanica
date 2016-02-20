#include "hum_controller.h"

extern action_union actions[];
extern uint8_t act_size;

uint8_t hum_controller(uint8_t data[], size_t data_len) {

    if(data_len != 1) {
        return 0;
    }

    uint8_t value = data[0];

    Serial.print("Controller receiver: ");
    Serial.println(value);

    if(value > HUM_THRESHOLD) {
        for(int i = 0; i < 2; i++) {
            digitalWrite(13, HIGH);
            delay(200);
            digitalWrite(13, LOW);
            delay(200);
        }
    }

    return 0;
}

void setup_hum_controller() {

    action_union act = {10, hum_controller};

    actions[act_size] = act;
    act_size++;

    pinMode(HUM_MOTOR_PIN, OUTPUT);
    pinMode(13, OUTPUT);
    return;
}
