//
// Created by Chaabane on 1/10/16.
//
#include <iostream>
#include "emulator/emulator.hpp"
#include "reader/RomReader.hpp"
#include "core/dump.hpp"
#include "donut/donut.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        nesmu::emulator emulator;

        donut::flags::DEBUG = true;
        emulator.start(std::string(av[1]));
    }
    else
    {
        std::cout << "./nesmu rom" << std::endl;
    }
    return 0;
}