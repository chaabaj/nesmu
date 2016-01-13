//
// Created by Chaabane on 1/10/16.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "RomReader.hpp"
#include "dump.hpp"

namespace nesmu
{
    namespace reader
    {
        RomReader::RomPtrType RomReader::read(const std::string &filePath)
        {
            RomPtrType          rom;
            std::ifstream       fileStream;

            fileStream.open(filePath, std::ios::in);
            if (fileStream.is_open())
            {
                Rom::ByteContainer  prg;
                Rom::ByteContainer  chr;
                RomInfo info;

                fileStream.read(reinterpret_cast<char*>(&info), sizeof(info));
                prg.resize(Rom::PRG_PAGE_SIZE * info.nbPrgPages);
                chr.resize(Rom::CHR_PAGE_SIZE * info.nbChrPages);
                fileStream.read(&prg[0], 16 - 8);
                fileStream.read(&prg[0], Rom::PRG_PAGE_SIZE * info.nbPrgPages);
                fileStream.read(&chr[0], Rom::CHR_PAGE_SIZE * info.nbChrPages);
                return RomPtrType(new Rom(info, std::move(prg), std::move(chr)));
            }
            return nullptr;
        }
    }
}
