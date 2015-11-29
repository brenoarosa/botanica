/*
 * network.h - Network class
 */

class Network {

    public:

        /*
         * @brief   Network constructor
         * @usage   set address and kernel callback for received message callback(msg, msg_len)
         *
         * @param   node_addr - in - unit address in the network
         * @param   message_handler - in - function pointer to message handler
         */
        void Network(const addr_t node_addr, void &message_handler);

        /*
         * @brief   Send message to all nodes
         * @usage
         *
         * @param   msg - in - message to be spread to all nodes
         * @param   msg_len - in - message lenght
         */
        void send(const uint8_t &msg, const uint8_t msg_len);

        /*
         * @brief   Send message to specific node
         * @usage
         *
         * @param   receiver_addr - in - receiver network's address
         * @param   msg - in - message to be spread to all nodes
         * @param   msg_len - in - message lenght
         */
        void send(const addr_t receiver_addr, const uint8_t &msg, const uint8_t msg_len);
}
