//
// Created by Chaabane on 1/10/16.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "reader/RomReader.hpp"
#include "core/dump.hpp"

namespace nesmu
{
    namespace reader
    {
        RomReader::RomSPtrType RomReader::read(const std::string &filePath)
        {
            RomSPtrType     rom;
            std::ifstream   fileStream;

            fileStream.open(filePath, std::ios::in);
            if (fileStream.is_open())
            {
                nesmu::core::ByteVector prg;
                nesmu::core::ByteVector chr;
                nesmu::core::RomInfo    info;

                fileStream.read(reinterpret_cast<char*>(&info), sizeof(info));
                prg.resize(nesmu::core::Rom::PRG_PAGE_SIZE * info.nbPrgPages);
                chr.resize(nesmu::core::Rom::CHR_PAGE_SIZE * info.nbChrPages);
                fileStream.read(&prg[0], 16 - 8);
                fileStream.read(&prg[0], nesmu::core::Rom::PRG_PAGE_SIZE * info.nbPrgPages);
                fileStream.read(&chr[0], nesmu::core::Rom::CHR_PAGE_SIZE * info.nbChrPages);
                return RomSPtrType(new nesmu::core::Rom(info, std::move(prg), std::move(chr)));
            }
            return nullptr;
        }
    }
}
