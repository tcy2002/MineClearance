cmake_minimum_required(VERSION 3.22)
project(MineClearance)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ..)

include_directories(.)

add_executable(MineClearance
        main.cpp
        mine.h
        Mine_display.cpp
        Mine_initial.cpp)
