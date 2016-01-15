//
// Created by Chaabane on 1/13/16.
//

#include <iostream>
#include "6502_cpu.hpp"

namespace nesmu
{
    CPU::CPU(std::array<char, MEM_SIZE> &memory) : _memory(memory)
    {
        std::memset(&_registers, 0, sizeof(_registers));
        _registers.pc = 0x8000;
        _handlers[0x78] = &CPU::sei;
        _handlers[0xD8] = &CPU::cld;
    }

    void CPU::play(core::Rom &rom)
    {
        uint8_t opcode = static_cast<uint8_t>(_memory[_registers.pc]);

        if (opcode < NB_OPCODE && _handlers[opcode])
        {
            OpCodeHandler handler = _handlers[opcode];

            std::cout << "Executing opcode : " << std::hex << std::uppercase << static_cast<int16_t>(opcode) << std::endl;
            _registers.pc += (this->*handler)(rom);
        }
        else
        {
            std::cout << "Unrecognized opcode " << static_cast<int16_t>(opcode) << " stop executing" << std::endl;
        }
    }

    uint8_t CPU::sei(core::Rom &rom)
    {
        _registers.p |= 0b0000100; // set true the disable interrupt flag
        return 1;
    }

    uint8_t CPU::cld(core::Rom &rom)
    {
        _registers.p &= 0b11110111;
        return 1;
    }
}
