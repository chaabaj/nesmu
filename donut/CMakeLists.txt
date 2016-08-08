cmake_minimum_required(VERSION 2.6)

project(donut)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.tpp")

if (UNIX OR APPLE OR CYGWIN)
    add_definitions("-std=c++11 -Wall -ggdb")
    list(REMOVE_ITEM SRCS src/donut/win_console.cpp)
    list(REMOVE_ITEM HEADERS include/donut/win_console.hpp)
else()
    list(REMOVE_ITEM SRCS src/donut/unix_console.cpp)
    list(REMOVE_ITEM HEADERS include/donut/unix_console.hpp)
endif()

add_definitions("-std=c++11 -Wall -ggdb")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin)

include_directories(include)

add_library(donut SHARED ${SRCS} ${HEADERS})

TARGET_LINK_LIBRARIES(donut ${CMAKE_DL_LIBS})