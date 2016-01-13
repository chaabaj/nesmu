//
// Created by Chaabane on 1/10/16.
//
#include <iostream>
#include "RomReader.hpp"
#include "dump.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        auto rom = nesmu::reader::RomReader::read(std::string(av[1]));

        nesmu::dump(rom->getPrg());
        std::cout << "Print chr data" << std::endl;
        nesmu::dump(rom->getChr());
    }
    else
    {
        std::cout << "./nesmu rom" << std::endl;
    }

    return 0;
}