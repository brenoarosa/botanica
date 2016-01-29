#include <iostream>
#include "manager.h"

extern proc_queue_union dyn_queue[];

int main(void) {

    setup_dyn_proc();

    std::cout << "after setup:" << (int) dyn_queue[0].data_len << std::endl;

    act_t action_id = 1;
    uint8_t data[] = {41, 42};
    size_t data_len = 2;

    add_dyn_proc(action_id, data, data_len);
    std::cout << "after add1:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after add1:" << (int) dyn_queue[0].action_data[1]<< std::endl;

    action_id = 2;
    data[0] = (uint8_t) 21;
    data_len = 1;

    add_dyn_proc(action_id, data, data_len);
    std::cout << "after add2:" << (int) dyn_queue[1].data_len << std::endl;
    std::cout << "after add2:" << (int) dyn_queue[1].action_data[0]<< std::endl;

    remove_dyn_proc(0);
    std::cout << "after remove1:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after remove1:" << (int) dyn_queue[0].action_data[0]<< std::endl;

    remove_dyn_proc(0);
    std::cout << "after remove2:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after remove2:" << (int) dyn_queue[0].action_data[0]<< std::endl;

    return 0;
}
