//
// Created by Chaabane on 1/12/16.
//

#include "Rom.hpp"

namespace nesmu
{
    int8_t const RomInfo::NES_MAGIC[4] = {'N', 'E', 'S', 0};

    const Rom::ByteContainer & Rom::getChr() const
    {
        return _chr;
    }

    const Rom::ByteContainer & Rom::getPrg() const
    {
        return _prg;
    }

    Rom::Rom(RomInfo const &info, ByteContainer &&prg, ByteContainer &&chr) : _prg(prg), _chr(chr)
    {
    }
}
