cmake_minimum_required(VERSION 3.22)
project(Pricer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pricer
        main.cpp
        src/MonteCarlo.cpp src/BlackScholes.cpp)
