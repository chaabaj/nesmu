//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_6302_CPU_HPP
# define NESMU_6302_CPU_HPP

# include <cstdint>
# include <array>
# include <vector>
# include <bitset>
# include "Rom.hpp"
# include "constants.hpp"

namespace nesmu
{
    struct Registers
    {
        char        a;
        char        x;
        char        y;
        char        p;
        uint16_t    sp;
        uint16_t    pc;
    };

    class CPU
    {
    public:
        typedef uint8_t (CPU::*OpCodeHandler)(core::Rom &rom);

        // memory is shared between component write in s
        // some address will affect other device such as ppu for exameple
        CPU(std::array<char, MEM_SIZE> &memory);

        void play(core::Rom &rom);

        static const int NB_OPCODE = 255;

        uint8_t sei(core::Rom &rom);
        uint8_t cld(core::Rom &rom);

    private:
        std::array<char, MEM_SIZE>  &_memory;
        Registers                   _registers;
        OpCodeHandler               _handlers[NB_OPCODE];

    };
}

#endif //NESMU_6302_CPU_HPP
