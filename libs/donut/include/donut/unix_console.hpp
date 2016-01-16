//
// Created by jalal on 16/01/16.
//

#ifndef DONUT_UNIX_CONSOLE_HPP
# define DONUT_UNIX_CONSOLE_HPP

# include <ostream>
# include <string>

namespace donut
{
    class UnixConsole
    {
    public:
        static std::ostream &success(std::string const &name);
        static std::ostream &log(std::string const &name);
        static std::ostream &error(std::string const &name);
        static std::ostream &warning(std::string const &name);

    private:
        static std::string const    RED;
        static std::string const    BLUE;
        static std::string const    GREEN;
        static std::string const    YELLOW;
        static std::string const    WHITE;
    };
}

#endif // DONUT_UNIX_CONSOLE_HPP
