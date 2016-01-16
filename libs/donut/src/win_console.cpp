//
// Created by jalal on 16/01/16.
//

#include <windows.h>
#include <iostream>
#include "donut/win_console.hpp"

namespace donut
{
    std::ostream &WinConsole::success(std::string const &name)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << "[BricksVM:" << name << "] : ";
        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return std::cout;
    }

    std::ostream &WinConsole::log(std::string const &name)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "[BricksVM:" << name << "] : ";
        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return std::cout;
    }

    std::ostream &WinConsole::error(std::string const &name)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "[BricksVM:" << name << "] : ";
        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return std::cout;
    }

    std::ostream & WinConsole::warning(std::string const &name)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << "[BricksVM:" << name << "] : ";
        SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        return std::cout;
    }
}