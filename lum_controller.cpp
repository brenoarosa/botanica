#include "lum_controller.h"

extern action_union actions[];
extern uint8_t act_size;
Servo myServo;

uint8_t lum_controller(uint8_t data[], size_t data_len) {

    if(data_len != 1) {
        return 0;
    }

    uint8_t value = data[0];

    Serial.print("Luminosity Controller receiver: ");
    Serial.println(value);

    if(value > LUM_THRESHOLD) {
        myServo.write(90);
        delay(200);
    } else {
        myServo.write(0);
        delay(200);
    }


    return 0;
}

void setup_lum_controller() {

    action_union act = {20, lum_controller};

    actions[act_size] = act;
    act_size++;

    myServo.attach(LUM_MOTOR_PIN);
    myServo.write(0);
    delay(200);
    return;
}
