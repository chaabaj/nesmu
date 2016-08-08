//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_6302_CPU_HPP
# define NESMU_6302_CPU_HPP

# include <cstdint>
# include "memory.hpp"
# include "core/rom.hpp"

namespace nesmu
{
    struct Registers
    {
        uint8_t     a;
        uint8_t     x;
        uint8_t     y;
        uint8_t     p;
        uint8_t     sp;
        uint16_t    pc;
    };

    class Cpu
    {
    public:
        typedef uint8_t (Cpu::*op_code_handler_t)(core::Rom &rom);

        // memory is shared between component write in s
        // some address will affect other device such as ppu for exameple
        Cpu(Memory &memory);

        void init();
        void play(core::Rom &rom);
        void reset();

        static const int NB_OPCODE = 255;

    private:

        // instructions
        uint8_t sei(core::Rom &rom);
        uint8_t cld(core::Rom &rom);
        uint8_t lda_val(core::Rom &rom);
        uint8_t sta_ind_val(core::Rom &rom);
        uint8_t ldx_val(core::Rom &rom);
        uint8_t txs(core::Rom &rom);
        uint8_t lda_ind_val(core::Rom &rom);
        uint8_t bpl(core::Rom &rom);

    private:
        // utilities
        void set_zero_and_neg_flags(uint8_t val);

    private:
        std::array<uint8_t, MEM_SIZE>  &_memory;
        Registers _registers;
        op_code_handler_t _handlers[NB_OPCODE];
    };
}

#endif //NESMU_6302_CPU_HPP
