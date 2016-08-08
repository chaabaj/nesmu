cmake_minimum_required(VERSION 2.8)

project(emulator)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.tpp")

if (UNIX OR APPLE OR CYGWIN)
    set(CMAKE_CXX_FLAGS "-std=c++11 -ggdb -Wall")
endif()

add_definitions("-std=c++11 -Wall -ggdb")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)

include_directories(include ../reader/include ../core/include ../donut/include)

add_executable(emulator ${SRCS} ${HEADERS})

install(TARGETS emulator DESTINATION ../bin)

target_link_libraries (emulator nesmu_reader donut nesmu_core ${CMAKE_DL_LIBS})