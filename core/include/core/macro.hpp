//
// Created by jalal on 16/01/16.
//

#ifndef NESMU_CORE_MACRO_HPP
#define NESMU_CORE_MACRO_HPP

# include <memory>

# define NESMU_SMART_POINTERS(classname) \
    using SPtr = std::shared_ptr<classname>;\
    using UPtr = std::unique_ptr<classname>;\
    using WPtr = std::weak_ptr<classname>;

#endif //NESMU_CORE_MACRO_HPP
