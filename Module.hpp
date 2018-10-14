#ifndef MODULE_HPP
#define MODULE_HPP

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <string>
#include <iostream>
# include <SDL.h>
# include <SDL_ttf.h>


#include "IMonitorModule.hpp"

class Module: public IMonitorModule
{
protected:
    int _startY;
    Module();

public:
    ~Module();
    Module(Module const &src);
    Module &operator=(Module const &src);

    virtual void draw() = 0;
    int getStartY();
};

#endif