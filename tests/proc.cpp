#include <iostream>
#include "proc/manager.h"

extern proc_union dyn_queue[];
extern proc_union reg_queue[];

int main(void) {

    setup_dyn_proc();

    std::cout << "DYNAMIC:" << std::endl;
    std::cout << "after setup:" << (int) dyn_queue[0].data_len << std::endl;

    proc_union proc = {1, {41, 42}, 2};

    std::cout << "after init1:" << (int) proc.data_len << std::endl;

    add_dyn_proc(&proc);
    std::cout << "after add1:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after add1:" << (int) dyn_queue[0].data[1]<< std::endl;

    proc = {2, {21}, 1};

    add_dyn_proc(&proc);
    std::cout << "after add2:" << (int) dyn_queue[1].data_len << std::endl;
    std::cout << "after add2:" << (int) dyn_queue[1].data[0]<< std::endl;

    remove_dyn_proc(0);
    std::cout << "after remove1:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after remove1:" << (int) dyn_queue[0].data[0]<< std::endl;

    remove_dyn_proc(0);
    std::cout << "after remove2:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "after remove2:" << (int) dyn_queue[0].data[0]<< std::endl;

    proc = {1, {55,66,77,88}, 4};
    add_dyn_proc(&proc);
    proc = {2, {21}, 1};
    add_dyn_proc(&proc);
    proc = {3, {41, 42}, 2};
    add_dyn_proc(&proc);

    next_dyn(&proc);
    remove_dyn_proc();
    std::cout << "First next:" << (int) proc.data_len << std::endl;
    std::cout << "First next:" << (int) proc.data[3]<< std::endl;

    next_dyn(&proc);
    remove_dyn_proc();
    std::cout << "Second next:" << (int) proc.data_len << std::endl;
    std::cout << "Second next:" << (int) proc.data[0]<< std::endl;

    next_dyn(&proc);
    remove_dyn_proc();
    std::cout << "Third next:" << (int) proc.data_len << std::endl;
    std::cout << "Third next:" << (int) proc.data[1]<< std::endl;

    std::cout << "Gran finale:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "Gran finale:" << (int) dyn_queue[0].data[0]<< std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "REGULAR:" << std::endl;

    proc = {1, {55,66,77,88}, 4};
    add_reg_proc(&proc);
    proc = {2, {21}, 1};
    add_reg_proc(&proc);
    proc = {3, {41, 42}, 2};
    add_reg_proc(&proc);

    next_reg(&proc);
    std::cout << "First next:" << (int) proc.data_len << std::endl;
    std::cout << "First next:" << (int) proc.data[0]<< std::endl;
    next_reg(&proc);
    std::cout << "Second next:" << (int) proc.data_len << std::endl;
    std::cout << "Second next:" << (int) proc.data[0]<< std::endl;
    next_reg(&proc);
    std::cout << "Third next:" << (int) proc.data_len << std::endl;
    std::cout << "Third next:" << (int) proc.data[0]<< std::endl;
    next_reg(&proc);
    std::cout << "Wrapping:" << (int) proc.data_len << std::endl;
    std::cout << "Wrapping:" << (int) proc.data[0]<< std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    //resets
    extern uint8_t reg_queue_size;
    extern uint8_t reg_queue_pointer;
    reg_queue_size = 0;
    reg_queue_pointer = 0;

    std::cout << "COMPLETE:" << std::endl;

    if(next_proc(&proc) == EMPTY_QUEUE) {
        std::cout << "0 reg, 0 dyn: OK" << std::endl;
    } else {
        std::cout << "0 reg, 0 dyn: FAILED" << std::endl;
    }

    proc = {1, {1,66,77,88}, 4};
    add_reg_proc(&proc);
    proc = {2, {2}, 1};
    add_reg_proc(&proc);
    proc = {3, {3, 42}, 2};
    add_reg_proc(&proc);
    proc = {4, {4,66,77,88}, 4};
    add_dyn_proc(&proc);
    proc = {5, {5}, 1};
    add_dyn_proc(&proc);
    proc = {6, {6, 42}, 2};
    add_dyn_proc(&proc);

    std::cout << "3 reg, 3 dyn:" << std::endl;
    for (int i = 0; i < 10; i++) {
        next_proc(&proc);
        std::cout << "\t" << i << ":" << (int) proc.data[0] << std::endl;
    }

    return 0;
}
