//
// Created by jalal on 16/01/16.
//

#ifndef NESMU_PPU_HPP
# define NESMU_PPU_HPP

# include "emulator/memory.hpp"
# include "core/rom.hpp"

namespace nesmu
{
    class PPU
    {
    public:
        PPU(Memory &memory);

        void init();
        void reset();
        void play(core::Rom &rom);

    private:
        Memory  &_memory;
        Memory  _vmemory;
    };
}

#endif //NESMU_PPU_HPP
