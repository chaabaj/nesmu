cmake_minimum_required(VERSION 2.6)

project(nesmu_reader)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.tpp")

if (UNIX OR APPLE)
    add_definitions("-std=c++11 -Wall -ggdb")
endif()

add_definitions("-std=c++11 -Wall -ggdb")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin)

include_directories(include ../core/include)

add_library(nesmu_reader SHARED ${SRCS} ${HEADERS})

TARGET_LINK_LIBRARIES(nesmu_reader nesmu_core ${CMAKE_DL_LIBS})