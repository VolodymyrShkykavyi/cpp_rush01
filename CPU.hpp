#ifndef CPU_HPP
#define CPU_HPP

#define CPU_NAME_LEN 1024

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <string>
#include <iostream>


class CPU
{
private:
    char    _name[CPU_NAME_LEN];
    size_t  _nameLen;
    int         _count;


public:
    CPU();
    ~CPU();
    CPU(CPU const &src);
    CPU &operator=(CPU const &src);

    std::string getName();
    int         getCount();

};


#endif