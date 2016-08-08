//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_6302_CPU_HPP
# define NESMU_6302_CPU_HPP

# include <cstdint>
# include "memory.hpp"
# include "core/rom.hpp"
# include "spi/cpu/cpu_6502.h"

namespace nesmu
{
    class Cpu
    {
    public:

        Cpu(Memory &memory);
        ~Cpu() {}

        void play();

    private:

        spi_cpu_t   _cpu;
        Memory      &_mem;
    };
}

#endif //NESMU_6302_CPU_HPP
