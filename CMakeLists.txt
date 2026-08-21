cmake_minimum_required(VERSION 4.1)
project(OOP1projekat)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP1projekat main.cpp
        src/Command/BaseCommand.h
        src/LineParser/Parser.h
        src/LineParser/Parser.h
        src/LineParser/Parser.cpp
        src/LineParser/TokenType.cpp
        src/LineParser/TokenType.h
        src/Exeptions/ParseExeptions.cpp
        src/LineParser/Tokenizer.cpp
        src/LineParser/Tokenizer.h
        src/LineParser/Tokenizer.cpp
        src/LineParser/Parser.h
)
