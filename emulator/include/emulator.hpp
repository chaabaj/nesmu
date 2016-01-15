//
// Created by Chaabane on 1/14/16.
//

#ifndef NESMU_EMULATOR_HPP
# define NESMU_EMULATOR_HPP

# include "6502_cpu.hpp"

namespace nesmu
{
    class Emulator
    {
    public:

        Emulator();

        void start(std::string const &file);

        void stop();

    private:
        std::array<char, MEM_SIZE>  _memory;
        CPU                         _cpu;
    };
}

#endif //NESMU_EMULATOR_HPP
