cmake_minimum_required(VERSION 3.20)
project(HW5)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW5 main.cpp headers/Context.h headers/Array.h headers/HoneyPot.h src/HoneyPot.cpp headers/Logger.h src/Logger.cpp)
