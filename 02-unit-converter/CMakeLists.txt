cmake_minimum_required(VERSION 3.10)
project(UnitConverter)

set(CMAKE_CXX_STANDARD 17)

add_executable(unit_converter
    src/main.cpp
    src/unit_converter.cpp
)