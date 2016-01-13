//
// Created by Chaabane on 1/12/16.
//

#include <iostream>
#include <cstdint>
#include "dump.hpp"

namespace nesmu
{
    void dump(std::vector<char> const &bytes)
    {
        for (char byte : bytes)
        {
            std::cout << std::hex << std::uppercase <<static_cast<int16_t>(byte) << " ";
        }
    }
}