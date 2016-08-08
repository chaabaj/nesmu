//
// Created by jalal on 16/01/16.
//

#ifndef DONUT_WIN_CONSOLE_H
# define DONUT_WIN_CONSOLE_H

# include <ostream>
# include <string>
# include "exports.hpp"

namespace donut
{
    class EXPORT_DLL WinConsole
    {
    public:
        static std::ostream &success(std::string const &name);
        static std::ostream &log(std::string const &name);
        static std::ostream &error(std::string const &name);
        static std::ostream &warning(std::string const &name);
    };
}

#endif //DONUT_WIN_CONSOLE_H
