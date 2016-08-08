//
// Created by Chaabane on 1/13/16.
//

#include <iostream>
#include <cstring>
#include <bitset>
#include "donut/donut.hpp"
#include "emulator/6502_cpu.hpp"

namespace nesmu
{
    Cpu::Cpu(Memory &memory) : _mem(memory)
    {
        spi_program_config_t    cfg;

        cfg.load_addr = 0xC000;
        cfg.prg_size = 16 * 1024;
        cfg.reset_vector_offset = 0xFFFC;
        cfg.stack_addr = 0x100;
        spi_cpu_init(&_cpu, 0, spi_clock_speed_unit_e::MHZ);
        spi_cpu_reset(&_cpu, _mem.begin(), &cfg);
    }

    void Cpu::play() {
        spi_cpu_execute(&_cpu, _mem.begin());
    }
}
