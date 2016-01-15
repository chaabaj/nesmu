//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_ROM_HPP
# define NESMU_ROM_HPP

# include <vector>
# include "types.hpp"
# include "utils.hpp"

namespace nesmu
{
    namespace core
    {
        // Each prg page is 16384 bytes(prg is for program code)
        // Each chr page is 8192 bytes(chr is for graphics data
        struct RomInfo
        {
            char magic[4];
            uint8_t nbPrgPages;
            uint8_t nbChrPages;
            uint8_t flag6;
            uint8_t flag7;

            static constexpr int8_t NES_MAGIC[4] = {'N', 'E', 'S', 0};
        };

        class Rom
        {
        public:

            NESMU_SMART_POINTERS(Rom);

            Rom(RomInfo const &info,
                ByteVector &&prg,
                ByteVector &&chr);

            ~Rom() {}
            ByteVector const &getPrg() const;
            ByteVector const &getChr() const;
            RomInfo const &getInfo() const;

            ByteVector::const_iterator getBank(uint8_t bank) const;


            static const uint16_t   PRG_PAGE_SIZE = 16384;
            static const uint16_t   CHR_PAGE_SIZE = 8192;
        private:
            RomInfo            _info;
            ByteVector const   _prg;
            ByteVector const   _chr;
        };
    }

}


#endif //NESMU_ROM_HPP_
