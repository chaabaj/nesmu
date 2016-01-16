//
// Created by Chaabane on 1/14/16.
//

#ifndef NESMU_EMULATOR_HPP
# define NESMU_EMULATOR_HPP

# include "6502_cpu.hpp"
# include "memory.hpp"
# include "ppu.hpp"

namespace nesmu
{
    class emulator
    {
    public:

        emulator();

        void start(std::string const &file);

        void stop();

    private:
        Memory  _memory;
        Cpu     _cpu;
        PPU     _ppu;
    };
}

#endif //NESMU_EMULATOR_HPP
