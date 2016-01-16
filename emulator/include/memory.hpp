//
// Created by jalal on 16/01/16.
//

#ifndef NESMU_MEMORY_HPP
#define NESMU_MEMORY_HPP

# include <array>
# include "constants.hpp"

namespace nesmu
{
    using Memory = std::array<uint8_t, MEM_SIZE>;
}

#endif //NESMU_MEMORY_HPP
