cmake_minimum_required(VERSION 3.20)
project(HW5)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW5 main.cpp headers/context.h headers/array.h headers/honeyPot.h src/honeyPot.cpp headers/logger.h src/logger.cpp headers/utils.h)
