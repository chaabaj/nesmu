cmake_minimum_required(VERSION 2.8)

project(emulator)

file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.tpp")

if (UNIX OR APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++11 -ggdb -Wall")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)

include_directories(include ../libs/reader/include ../libs/core/include)

add_executable(emulator ${SRCS} ${HEADERS})

install(TARGETS emulator DESTINATION ../bin)

target_link_libraries (emulator nesmu_reader nesmu_core ${CMAKE_DL_LIBS})