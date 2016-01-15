//
// Created by Chaabane on 1/14/16.
//

#include <iostream>
#include <algorithm>
#include "emulator.hpp"
#include "RomReader.hpp"
#include "dump.hpp"

namespace nesmu
{
    Emulator::Emulator() : _cpu(CPU(_memory))
    {
    }

    void Emulator::start(std::string const &file)
    {
        std::cout << "Reading  " << file << std::endl;
        core::Rom::SPtr rom = reader::RomReader::read(file);

        std::cout << "Mapping in first bank of program in memory" << std::endl;
        std::copy(rom->getBank(1), rom->getBank(1) + core::Rom::PRG_PAGE_SIZE, _memory.begin() + 0x8000);
        std::copy(rom->getBank(2), rom->getBank(2) + core::Rom::PRG_PAGE_SIZE, _memory.begin() + 0xC000);
        std::cout << "First program bank is loaded in memory from address 0 to PRG PAGE SIZE" << std::endl;
        while (true)
        {
            _cpu.play(*rom);
        }
    }
}