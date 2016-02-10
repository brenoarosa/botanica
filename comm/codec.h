#include "includes.h"

/*
 * codec.h - Message encoder and decoder
 */

/*
 * @brief   Build message to send to network
 *
 * @usage
 *
 * @param   emitter - in - address of message sender
 * @param   action - in - command to be executed
 * @param   data - in - data if available
 * @param   data_len - in - size of data
 * @param   msg - out - message encoded
 * @param   msg_len - out - message size
 *
 * @return  Error status
 */
err_t msg_builder(const addr_t emitter, const act_t action, const uint8_t data[], const size_t data_len, uint8_t msg[], size_t *msg_len);

/*
 * @brief   Decode received message
 * @usage
 *
 * @param   msg - in - message encoded
 * @param   msg_len - in - message size
 * @param   emitter - out - address of message sender
 * @param   action - out - command to be executed
 * @param   data - out - data if available
 * @param   data_len - out - size of data
 *
 * @return  Error status
 */
err_t msg_reader(const uint8_t msg[], const size_t msg_len, addr_t *emitter, act_t *action, uint8_t data[], size_t *data_len);
