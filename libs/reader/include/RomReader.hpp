//
// Created by Chaabane on 1/10/16.
//

#ifndef NESMU_READER_ROMREADER_HPP
#define NESMU_READER_ROMREADER_HPP

# include <string>
# include <memory>
# include "rom.hpp"

namespace nesmu
{
    namespace reader
    {
        class RomReader
        {
        public:
            typedef nesmu::core::Rom::SPtr RomSPtrType;

            ///Read a nes rom (support only NES 2.0 rom format
            static RomSPtrType read(std::string const &filePath);
        };
    }
}

#endif //NESMU_READER_ROMREADER_HPP
