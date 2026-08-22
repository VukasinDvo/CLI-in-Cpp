cmake_minimum_required(VERSION 4.1)
project(OOP1projekat)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP1projekat main.cpp
        src/Command/BaseCommand.h
        src/Command/BaseCommand.cpp
        src/Commands/EchoCommand.h
        src/Commands/EchoCommand.cpp

        src/LineParser/Parser.h
        src/LineParser/Parser.cpp
        src/LineParser/TokenType.cpp
        src/LineParser/TokenType.h
        src/LineParser/Tokenizer.cpp
        src/LineParser/Tokenizer.h
        src/LineParser/ParsedCommand.h

        src/Exeptions/ParseExeptions.cpp
        src/Exeptions/CommandExeptions.h

        src/IOResolver/InputResolver.h
        src/IOResolver/InputResolver.cpp
        src/IOResolver/OutputResolver.h

        src/CommandFactory/CommandFactory.h
        src/CommandFactory/CommandFactory.cpp
        src/IOResolver/OutputResolver.cpp
)
