#include "network.h"

/*
 * @brief   Network setup
 * @usage   set address and kernel callback for received message callback(msg, msg_len)
 *
 * @param   node_addr - in - unit address in the network
 * @param   message_handler - in - function pointer to message handler
 */
void setup_net(const addr_t node_addr, void (*message_handler)(int)) {

    Wire.begin(node_addr);
    // enable general calls - http://playground.arduino.cc/Main/WireLibraryDetailedReference#begin
    TWAR = (node_addr << 1) | 1;
    Wire.onReceive(message_handler);
}

/*
 * @brief   Send message to all nodes
 * @usage
 *
 * @param   msg - in - message to be spread to all nodes
 * @param   msg_len - in - message lenght
 */
void send_msg(const uint8_t *msg, const size_t msg_len) {
    Wire.beginTransmission(GCALL_ADDR);
    Wire.write(msg, msg_len);
    Wire.endTransmission();
}

void send_msg(const addr_t node_addr, const uint8_t *msg, const size_t msg_len) {
    Wire.beginTransmission(node_addr);
    Wire.write(msg, msg_len);
    Wire.endTransmission();
}
