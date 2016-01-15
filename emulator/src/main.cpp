//
// Created by Chaabane on 1/10/16.
//
#include <iostream>
#include <emulator.hpp>
#include "RomReader.hpp"
#include "dump.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        nesmu::Emulator emulator;

        emulator.start(std::string(av[1]));
    }
    else
    {
        std::cout << "./nesmu rom" << std::endl;
    }
    return 0;
}