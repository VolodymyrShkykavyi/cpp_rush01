#include "Memory.hpp"

Memory::Memory() {}
Memory::~Memory() {}
Memory::Memory(Memory const &src) {
    *this = src;
}
Memory& Memory::operator=(Memory const &src) {
    _title = src._title;

    return *this;
}

