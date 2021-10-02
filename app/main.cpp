#include <iostream>
#include "../include/controllerpid.hpp"

int main()
{
    std::cout << "Test_again" << std::endl;
    ControllerPID test_class;
    float test = test_class.ComputePID(20,20);
    std::cout << test << std::endl;
    return 0;
}
