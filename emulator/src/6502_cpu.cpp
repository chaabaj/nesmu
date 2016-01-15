//
// Created by Chaabane on 1/13/16.
//

#include <iostream>
#include "6502_cpu.hpp"

namespace nesmu
{
    Cpu::Cpu(std::array<uint8_t, MEM_SIZE> &memory) : _memory(memory)
    {
        std::memset(&_registers, 0, sizeof(_registers));
        _registers.pc = 0x8000;
        std::memset(_handlers, 0, sizeof(_handlers));
        _handlers[0x78] = &Cpu::sei;
        _handlers[0xD8] = &Cpu::cld;
        _handlers[0xA9] = &Cpu::lda_val;
        _handlers[0x8D] = &Cpu::sta_ind_val;
        _handlers[0xA2] = &Cpu::ldx_val;
        _handlers[0x9A] = &Cpu::txs;
        _handlers[0xAD] = &Cpu::lda_ind_val;
        _handlers[0x10] = &Cpu::bpl;
    }

    void Cpu::play(core::Rom &rom)
    {
        uint8_t opcode = _memory[_registers.pc];

        if (opcode < NB_OPCODE && _handlers[opcode])
        {
            op_code_handler_t handler = _handlers[opcode];

            std::cout << "Executing opcode : " << std::hex << std::uppercase << static_cast<int16_t>(opcode) << std::endl;
            _registers.pc += (this->*handler)(rom);
        }
        else
        {
            _registers.pc += 1;
        }
    }

    void Cpu::set_zero_and_neg_flags(uint8_t val)
    {
        std::cout << "Set zero and neg flags : " << static_cast<int16_t>(val) << std::endl;
        _registers.p = val == 0 ? _registers.p | 0b00000010 : _registers.p;

        _registers.p = static_cast<int8_t>(val) < 0 ? _registers.p | 0b10000000 : _registers.p;
        std::cout << std::bitset<8>(_registers.p) << std::endl;
    }

    uint8_t Cpu::sei(core::Rom &rom)
    {
        _registers.p |= 0b0000100; // set true the disable interrupt flag
        return 1;
    }

    uint8_t Cpu::cld(core::Rom &rom)
    {
        _registers.p &= 0b11110111;
        return 1;
    }

    uint8_t Cpu::lda_val(core::Rom &rom)
    {
        uint8_t nb = _memory[_registers.pc + 1];

        _registers.a = nb;
        std::cout << "Loaded number a : " << static_cast<int16_t>(_registers.a) << std::endl;
        this->set_zero_and_neg_flags(_registers.a);
        return 2;
    }

    uint8_t Cpu::sta_ind_val(core::Rom &rom)
    {
        uint16_t addr = (_memory[_registers.pc + 2] << 8) + (_memory[_registers.pc + 1]);

        _memory[addr] = _registers.a;
        std::cout << "Memory at addr " << addr << " value is : " << static_cast<int16_t>(_memory[addr]) << std::endl;
        return 3;
    }

    uint8_t Cpu::ldx_val(core::Rom &rom)
    {
        uint8_t val = _memory[_registers.pc + 1];

        _registers.x = val;
        std::cout << "Loaded direct value " << static_cast<int16_t>(val) << " in register x" << std::endl;
        this->set_zero_and_neg_flags(_registers.x);
        return 2;
    }

    uint8_t Cpu::txs(core::Rom &rom)
    {
        _registers.sp = _registers.x;
        std::cout << "Transfert the value in register x : " <<  std::hex << static_cast<int16_t>(_registers.x)
          << " to the register sp" << std::endl;
        return 1;
    }

    uint8_t Cpu::lda_ind_val(core::Rom &rom)
    {
        uint16_t addr = (_memory[_registers.pc + 2] << 8) + (_memory[_registers.pc + 1]);

        _registers.a = _memory[addr];
        this->set_zero_and_neg_flags(_registers.a);
        return 3;
    }

    // Jump to the address $aa if the negative flag in the register flag is false
    uint8_t Cpu::bpl(core::Rom &rom)
    {
        bool isPos = (_registers.p & 0b10000000) == 0;

        if (!isPos)
        {
            int8_t addr = static_cast<int8_t>(_memory[_registers.pc + 1]);

            std::cout << "Relative jump at relative addr : " << std::dec << static_cast<int16_t>(addr) << std::endl;
            // relative jump if negative flag in register p is zero
            _registers.pc += addr;
        }
        return 0;
    }
}
