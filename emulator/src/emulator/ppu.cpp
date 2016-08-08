//
// Created by jalal on 16/01/16.
//

#include "emulator/ppu.hpp"
#include "donut/donut.hpp"

namespace nesmu
{
    PPU::PPU(Memory &memory) : _memory(memory)
    {

    }

    /// init ppu register see http://wiki.nesdev.com/w/index.php/PPU_power_up_state
    void PPU::init()
    {
        donut::Console::log("PPU") << "Initialize the ppu" << std::endl;
        _memory[0x2000] = 0;
        _memory[0x2001] = 0;
        _memory[0x2003] = 0;
        _memory[0x2004] = 0;
        _memory[0x2005] = 0;
        _memory[0x2006] = 0;
        _memory[0x2007] = 0;
        donut::Console::log("PPU") << "PPU initialized" << std::endl;

    }

    void PPU::reset()
    {
        donut::Console::log("PPU") << "Reseting ppu" << std::endl;
        _memory[0x2000] = 0;
        _memory[0x2001] = 0;
        _memory[0x2005] = 0;
        _memory[0x2007] = 0;
        donut::Console::log("PPU") << "ppu resetted" << std::endl;
    }

    void PPU::play(core::Rom &rom)
    {
        _memory[0x2002] |= 0b01000000;
        // TODO
    }
}
