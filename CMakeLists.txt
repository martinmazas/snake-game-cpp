cmake_minimum_required(VERSION 3.16)
project(FinalProject_SnakeGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(FinalProject_SnakeGame main.cpp Snake.cpp Snake.h Food.cpp Food.h)
