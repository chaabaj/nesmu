//
// Created by jalal on 16/01/16.
//

#ifndef DONUT_CONSOLE_HPP
# define DONUT_CONSOLE_HPP

# include <type_traits>
# include "constants.hpp"

namespace donut
{
    class WinConsole;
    class UnixConsole;
}

# ifdef WIN32
#  include "win_console.hpp"
# elif _WIN32_ || __CYGWIN__ || __MINGW32__
#  include "win_console.hpp"
# elif __gnu_linux__ || __APPLE__
#  include "unix_console.hpp"
# endif

namespace donut
{
    typedef std::conditional<IS_WINDOWS, WinConsole, UnixConsole>::type    Console;
}

#endif // DONUT_CONSOLE_HPP
