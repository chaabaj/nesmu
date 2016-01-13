//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_6302_CPU_HPP
# define NESMU_6302_CPU_HPP

# include <cstdint>
# include <array>
# include <vector>
# include "Rom.hpp"

namespace nesmu
{
    class CPU
    {
    public:
        // memory is shared between component write in s
        // some address will affect other device such as ppu for exameple
        CPU(std::vector<char> &memory);

        void play(Rom &rom);

        static size_t const NB_REGISTERS = 6;
    private:
        std::vector<char>               _memory;
        std::array<char, NB_REGISTERS>  _registers;
    };
}

#endif //NESMU_6302_CPU_HPP
