cmake_minimum_required(VERSION 4.1)
project(OOP1projekat)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(OOP1projekat main.cpp ${SOURCES}
        src/Commands/TimeCommand.h
        src/Commands/TimeCommand.cpp
        src/Commands/TouchCommand.h
        src/Commands/TouchCommand.cpp
        src/Commands/DateCommand.h
        src/Commands/DateCommand.cpp
        src/Commands/CommandHeader.h
        src/Commands/WcCommand.h
        src/Commands/WcCommand.cpp)