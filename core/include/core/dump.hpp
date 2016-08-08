//
// Created by Chaabane on 1/12/16.
//

#ifndef NESMU_DUMP_HPP
# define NESMU_DUMP_HPP

# include <vector>

namespace nesmu
{
    namespace core
    {
        template<typename Container>
        void dump(Container const &bytes)
        {
            for (char byte : bytes)
            {
                std::cout << std::hex << std::uppercase << static_cast<int16_t>(byte) << " ";
            }
        }
    }
}

#endif //NESMU_DUMP_HPP
