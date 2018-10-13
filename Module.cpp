#include "Module.hpp"

Module::Module() {}
Module::~Module() {}

Module::Module(Module const &src) {
    *this = src;
}

Module& Module::operator=(Module const &src) {
    _startY = src._startY;

    return *this;
}

int Module::getStartY() {
    return _startY;
}