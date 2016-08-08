//
// Created by jalal on 16/01/16.
//

#ifndef DONUT_EXPORTS_HPP
#define DONUT_EXPORTS_HPP


# ifdef WIN32
#  define EXPORT_DLL __declspec(dllexport)
# elif _WIN32_ || __CYGWIN__ || __MINGW32__
#  define EXPORT_DLL __declspec(dllexport)
# else
#  define EXPORT_DLL
# endif

#endif //DONUT_EXPORTS_HPP
