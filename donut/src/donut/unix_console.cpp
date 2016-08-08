//
// Created by jalal on 16/01/16.
//

#include <iostream>
#include "donut/unix_console.hpp"

namespace donut
{
    std::string const UnixConsole::RED = "\033[30m";
    std::string const UnixConsole::GREEN = "\033[32m";
    std::string const UnixConsole::WHITE = "\033[37m";
    std::string const UnixConsole::BLUE = "\033[34m";
    std::string const UnixConsole::YELLOW = "\033[33m";

    std::ostream &UnixConsole::success(std::string const &name)
    {
        std::cout << UnixConsole::GREEN << "[" << name << "]";
        std::cout << UnixConsole::WHITE;
        return std::cout;
    }

    std::ostream &UnixConsole::log(std::string const &name)
    {
        std::cout << UnixConsole::BLUE << "[" << name << "]";
        std::cout << UnixConsole::WHITE;
        return std::cout;
    }

    std::ostream &UnixConsole::error(std::string const &name)
    {
        std::cout << UnixConsole::RED << "[" << name << "]";
        std::cout << UnixConsole::WHITE;
        return std::cout;
    }

    std::ostream& UnixConsole::warning(std::string const &name)
    {
        std::cout << UnixConsole::YELLOW << "[" << name << "]";
        std::cout << UnixConsole::WHITE;
        return std::cout;
    }
}
