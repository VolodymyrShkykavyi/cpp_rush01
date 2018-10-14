#include "CPU.hpp"

CPU::CPU() {
    size_t  countLen = sizeof(_count);

    _nameLen = sizeof(_name);
    sysctlbyname("machdep.cpu.brand_string", &_name, &_nameLen, NULL, 0);
    sysctlbyname("hw.ncpu", &_count, &countLen, NULL, 0);
    _title = "CPU";
}

CPU::~CPU() {}

CPU::CPU(CPU const &src) {
    *this = src;
}

CPU& CPU::operator=(CPU const &src) {
    strncpy(_name, src._name, CPU_NAME_LEN);
    _count = src._count;

    return *this;
}

std::string CPU::getName() {
    return _name;
}

int CPU::getCount() {
    return _count;
}

void CPU::draw() {

}

SDL_Surface * CPU::getSurfaceInfo() {
    return getSurface(_name);
}