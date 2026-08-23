cmake_minimum_required(VERSION 4.1)
project(OOP1projekat)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(OOP1projekat main.cpp ${SOURCES})