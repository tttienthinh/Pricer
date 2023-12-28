cmake_minimum_required(VERSION 3.25)
project(Pricer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pricer
        main.cpp
        Stock.cpp MonteCarlo.cpp BlackScholes.cpp)
