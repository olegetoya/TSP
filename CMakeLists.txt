cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp BaseParser.cpp Point.h TSPParser.cpp BaseSolver.cpp TSPSolver.cpp)
