//
// Created by Chaabane on 1/13/16.
//

#ifndef NESMU_UTILS_HPP
# define NESMU_UTILS_HPP

# include <memory>

# define NESMU_SMART_POINTERS(classname) \
    using SPtr = std::shared_ptr<classname>; \
    using UPtr = std::unique_ptr<classname>;

#endif //NESMU_UTILS_HPP
