#include "hum_sensor.h"

extern action_union actions[];
extern uint8_t act_size;

unsigned long last_hum_measure;

uint8_t hum_measure(uint8_t data[], size_t data_len) {

    unsigned long current_time;
    current_time = millis();

    if((current_time-last_hum_measure) < HUM_MEASURE_INTERVAL) {
        return 0;
    }

    last_hum_measure = current_time;

    int _value;
    _value = analogRead(HUM_SENSOR_PIN);
    _value = _value / 4; // up to 256

    uint8_t value = _value;

    Serial.print("Sensor sending: ");
    Serial.println(value);

    /* Preparing controller call */
    const proc_union hum_controller = {10, {value}, 1};
    uint8_t msg[MAX_MSG_SIZE];
    size_t msg_len;

    /* Controller call */
    if(is_installed(hum_controller.action_id)) {
        add_dyn_proc(&hum_controller);
    }
    else {
        addr_t emitter = NODE_ADDR;
        msg_builder(emitter, hum_controller, msg, &msg_len);
        send_msg(msg, msg_len);
    }

    return 0;
}

void setup_hum_sensor() {

    pinMode(HUM_SENSOR_PIN, INPUT);

    action_union act = {11, hum_measure};

    actions[act_size] = act;
    act_size++;

    proc_union proc = {11, {}, 0};
    add_reg_proc(&proc);

    last_hum_measure = millis();

    return;
}
