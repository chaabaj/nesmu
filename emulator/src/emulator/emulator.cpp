//
// Created by Chaabane on 1/14/16.
//

#include <iostream>
#include <algorithm>
#include "emulator/emulator.hpp"
#include "reader/RomReader.hpp"
#include "core/dump.hpp"
#include "donut/donut.hpp"

namespace nesmu
{
    emulator::emulator() : _cpu(Cpu(_memory)), _ppu(PPU(_memory))
    {
    }

    void emulator::start(std::string const &file)
    {
        donut::Console::log("NESMU") << "Reading " << file << std::endl;
        core::Rom::SPtr rom = reader::RomReader::read(file);

        donut::Console::log("NESMU") << "Mapping in first bank of program in memory" << std::endl;
        std::copy(rom->getBank(1), rom->getBank(1) + core::Rom::PRG_PAGE_SIZE, _memory.begin() + 0x8000);
        std::copy(rom->getBank(2), rom->getBank(2) + core::Rom::PRG_PAGE_SIZE, _memory.begin() + 0xC000);
        donut::Console::log("NESMU") << "First program bank is loaded in memory from address 0 to PRG PAGE SIZE" << std::endl;

        _cpu.init();
        _ppu.init();
        while (true)
        {
            _cpu.play(*rom);
            _ppu.play(*rom);
        }
    }
}