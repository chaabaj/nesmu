//
// Created by Chaabane on 1/12/16.
//

#ifndef DONUT_DEBUG_HPP
# define DONUT_DEBUG_HPP

# include <cassert>
# include "console.hpp"
# include "flags.hpp"

# define DONUT_PRINT_INFO() \
    donut::Console::log("INFO") << "In file " << __FILE__ << " function " \
    << __func__ << " line " << __LINE__;

# define DONUT_ASSERT(cond, msg) if (donut::flags::DEBUG && !cond) { \
        DONUT_PRINT_INFO(); \
        donut::Console::error("Error") << msg << std::endl; \
        assert(cond); \
    }

# define DONUT_PRINT_DEBUG(name, ...) if (donut::flags::DEBUG) { \
        DONUT_PRINT_INFO() \
        donut::Console::log(name) << donut::str(__VA_ARGS__) << std::endl; \
    }

#endif //DONUT_DEBUG_HPP
