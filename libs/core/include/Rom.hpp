//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_ROM_HPP
# define NESMU_ROM_HPP

# include <vector>

namespace nesmu
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

        static const int8_t NES_MAGIC[4];
    };

    class Rom
    {
    public:
        typedef std::vector<char>   ByteContainer;

        Rom(RomInfo const &info,
            ByteContainer &&prg,
            ByteContainer &&chr);

        ~Rom() {}
        ByteContainer const &getPrg() const;
        ByteContainer const &getChr() const;


        static const uint16_t   PRG_PAGE_SIZE = 16384;
        static const uint16_t   CHR_PAGE_SIZE = 8192;
    private:
        RomInfo               _info;
        ByteContainer const   _prg;
        ByteContainer const   _chr;
    };
}


#endif //NESMU_ROM_HPP_
