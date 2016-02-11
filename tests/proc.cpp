#include <iostream>
#include "proc/manager.h"

extern proc_union dyn_queue[];

int main(void) {

    setup_dyn_proc();

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
    std::cout << "First next:" << (int) proc.data_len << std::endl;
    std::cout << "First next:" << (int) proc.data[3]<< std::endl;
    remove_dyn_proc();

    next_dyn(&proc);
    std::cout << "Second next:" << (int) proc.data_len << std::endl;
    std::cout << "Second next:" << (int) proc.data[0]<< std::endl;
    remove_dyn_proc();

    next_dyn(&proc);
    std::cout << "Third next:" << (int) proc.data_len << std::endl;
    std::cout << "Third next:" << (int) proc.data[1]<< std::endl;
    remove_dyn_proc();

    std::cout << "Gran finale:" << (int) dyn_queue[0].data_len << std::endl;
    std::cout << "Gran finale:" << (int) dyn_queue[0].data[0]<< std::endl;

    return 0;
}
