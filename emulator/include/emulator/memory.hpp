//
// Created by jalal on 16/01/16.
//

#ifndef NESMU_MEMORY_HPP
#define NESMU_MEMORY_HPP

# include <array>
# include "spi/cpu/types.h"
# include "emulator/constants.hpp"

namespace nesmu
{
    using Memory = std::array<spi_byte_t, MEM_SIZE>;
}

#endif //NESMU_MEMORY_HPP
