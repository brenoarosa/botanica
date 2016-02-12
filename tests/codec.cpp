#include "codec.h"
#include <iostream>

int main(void) {

    uint8_t emitter = 3;
    uint8_t action = 81;


    uint8_t data[80] = {41, 41, 41, 41, 41, 41, 41, 41};
    size_t data_len = 8;

    uint8_t msg[80];
    size_t msg_len = 0;

    std::cout << "before encode\t\temitter:" << (int) emitter << " act:" << (int) action << " data_len:" << (int) data_len << "\tdata: {";

    for( unsigned int i = 0; i < data_len ; i++) {
        std::cout << (int) data[i] << ",";
    }
    std::cout << "}" << std::endl;

    msg_builder(emitter, action, data, data_len, msg, &msg_len);

    std::cout << "after encode\t\tmsg_len:" << msg_len << "\t\t\tmsg: {";
    for( unsigned int i = 0; i < msg_len ; i++) {
        std::cout << (int) msg[i] << ",";
    }
    std::cout << "}" << std::endl;

    emitter = 0;
    action = 0;

    data_len = 8;
    for( unsigned int i = 0; i < data_len ; i++) {
        data[i] = 0;
    }

    std::cout << "before decode\t\temitter:" << (int) emitter << " act:" << (int) action << " data_len:" << (int) data_len << "\tdata: {";

    for( unsigned int i = 0; i < data_len ; i++) {
        std::cout << (int) data[i] << ",";
    }
    std::cout << "}" << std::endl;

    msg_reader(msg, msg_len, &emitter, &action, data, &data_len);

    std::cout << "after decode\t\temitter:" << (int) emitter << " act:" << (int) action << " data_len:" << (int) data_len << "\tdata: {";

    for( unsigned int i = 0; i < data_len ; i++) {
        std::cout << (int) data[i] << ",";
    }
    std::cout << "}" << std::endl;

    return 0;
}
