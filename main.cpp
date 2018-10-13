#include <iostream>
#include "CPU.hpp"

int main()
{
    CPU cpu;

    std::cout << "name: " << cpu.getName() << ", cpu num: " << cpu.getCount() << std::endl;
}