cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator
    src/main.cpp
    src/calculator.cpp
    src/conversions.cpp
    src/quadratic.cpp
    src/trigonometry.cpp
)