#include "lum_sensor.h"

extern action_union actions[];
extern uint8_t act_size;

unsigned long last_lum_measure;

uint8_t lum_measure(uint8_t data[], size_t data_len) {

    unsigned long current_time;
    current_time = millis();

    if((current_time-last_lum_measure) < LUM_MEASURE_INTERVAL) {
        return 0;
    }

    last_lum_measure = current_time;

    int _value;
    _value = analogRead(LUM_SENSOR_PIN);
    _value = _value / 4; // up to 256

    uint8_t value = _value;

    Serial.print("Lum sensor sending: ");
    Serial.println(value);

    /* Preparing controller call */
    const proc_union lum_controller = {20, {value}, 1};
    uint8_t msg[MAX_MSG_SIZE];
    size_t msg_len;

    /* Controller call */
    if(is_installed(lum_controller.action_id)) {
        add_dyn_proc(&lum_controller);
    }
    else {
        addr_t emitter = NODE_ADDR;
        msg_builder(emitter, lum_controller, msg, &msg_len);
        send_msg(msg, msg_len);
    }

    return 0;
}

void setup_lum_sensor() {

    pinMode(LUM_SENSOR_PIN, INPUT);

    action_union act = {21, lum_measure};

    actions[act_size] = act;
    act_size++;

    proc_union proc = {21, {}, 0};
    add_reg_proc(&proc);

    last_lum_measure = millis();

    return;
}
