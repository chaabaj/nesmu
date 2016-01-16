//
// Created by Chaabane on 1/12/16.
//

#include "rom.hpp"

namespace nesmu
{
    namespace core
    {
        Rom::Rom(RomInfo const &info, ByteVector &&prg, ByteVector &&chr) : _info(info), _prg(prg), _chr(chr)
        {
        }

        const ByteVector &Rom::getChr() const
        {
            return _chr;
        }

        const ByteVector &Rom::getPrg() const
        {
            return _prg;
        }

        RomInfo const&Rom::getInfo() const
        {
            return _info;
        }

        ByteVector::const_iterator Rom::getBank(uint8_t bank) const
        {
            return _prg.cbegin() + (PRG_PAGE_SIZE * (bank - 1));
        }
    }

}
