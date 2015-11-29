/*
 * manager.h - Process manager class
 */

class ProcessManager {

    public:

        /*
         * @brief   Proccess manager constructor
         * @resume  Adds all regular actions to regular queue and prepare dynamic queue.
         *          Dynamic queue is executed, if empty then regular queue follows normal execution plan.
         * @usage
         */
        void ProcessManager();

        /*
         * @brief   Adds action to queue
         * @usage   Module added will be the add to dynamic FIFO
         *
         * @param   action_id - in - action id
         * @param   data - in - data (parameters) to be passed for action
         *
         * @return  Error status
         */
        uint8_t add(act_t action_id, const uint8_t &data, const uint8_t data_len);

        /*
         * @brief   Pointer to next action
         * @usage
         *
         * @param   next_act - out - pointer to next action
         *
         * @return  Error status
         */
        uint8_t next(void &next_act);

    private:

        uint8_t reg_proc_next;

        act_t reg_circular_queue[MAX_REG_PROC];
        uint8_t reg_queue_pointer;

        act_t dyn_queue[MAX_DYN_PROC];
}
