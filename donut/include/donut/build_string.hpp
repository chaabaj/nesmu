//
// Created by jalal on 16/01/16.
//

#ifndef DONUT_BUILD_STRING_HPP
# define DONUT_BUILD_STRING_HPP

# include <sstream>

namespace donut
{
    template<typename T>
    std::string _str(std::stringstream &stream, T const &param)
    {
        stream << param;

        return stream.str();
    }

    template<typename T, typename ... U>
    std::string _str(std::stringstream &stream, T const &param, U const & ...params)
    {
        stream << param;

        return _str(stream, params...);
    }

    template<typename ... T>
    std::string str(T const & ... params)
    {
        std::stringstream   stream;

        return _str(stream, params...);
    }

}

#endif //DONUT_BUILD_STRING_HPP
