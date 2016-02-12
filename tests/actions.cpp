#include <iostream>
#include "actions.h"

extern uint8_t act_size;

uint8_t mod_func(uint8_t data[], size_t data_len) {
    std::cout << "I'm in mod_func, kids!" << std::endl;
    return 0;
}

uint8_t mod_func_2(uint8_t data[], size_t data_len) {
    std::cout << "I'm in mod_func_2, kids!" << std::endl;
    return 0;
}

int struct_test(void) {

    uint8_t data[20] = {1,2,3,4};
    size_t data_len = 4;

    std::cout << "Testing function:" << std::endl;
    mod_func(data, data_len);

    std::cout << "Creating struct...";
    action_union action = {1, &mod_func};
    std::cout << "\tOk." << std::endl;

    std::cout << "Testing stored function:" << std::endl;
    std::cout << "\t";

    uint8_t (*function)(uint8_t *, size_t);
    function = action.function;
    function(data, data_len);

    return 0;
}

int register_test(void) {

    action_union act = {1, &mod_func};
    std::cout << "Registering act1." << std::endl;
    register_action(act);
    std::cout << "Registering act2." << std::endl;
    act = {2, &mod_func_2};
    register_action(act);
    std::cout << "Current act_size: " << (int)act_size << std::endl;


    return 0;
}

int installed_test(void) {

    act_t act_id = 1;
    bool result = false;
    result = is_installed(act_id);

    std::cout << "\tis_installed: " << result << std::endl;

    return 0;
}

int get_test(void) {

    act_t act_id = 1;

    uint8_t (*function)(uint8_t *, size_t);
    uint8_t data[20] = {1,2,3,4};
    size_t data_len = 4;

    std::cout << "Getting action with id: " << (int)act_id;
    get_action(act_id, function);
    std::cout << "\tOk." << std::endl;
    std::cout << "Testing action " << (int)act_id << std::endl;
    function(data, data_len);

    act_id = 2;

    std::cout << "Getting action with id: " << (int)act_id;
    get_action(act_id, function);
    std::cout << "\tOk." << std::endl;
    std::cout << "Testing action " << (int)act_id << std::endl;
    function(data, data_len);

    return 0;
}

int main(void) {

    std::cout << "Testing Struct..." << std::endl;
    std::cout << std::endl;
    struct_test();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Testing Resgiter..." << std::endl;
    std::cout << std::endl;
    register_test();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Testing Installed..." << std::endl;
    std::cout << std::endl;
    installed_test();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Testing get..." << std::endl;
    std::cout << std::endl;
    get_test();
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}
