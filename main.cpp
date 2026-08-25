#include <fstream>
#include <iosfwd>
#include <iostream>

#include "src/CLI/Interpreter.h"

#include "src/CommandFactory/CommandFactory.h"



int main() {
    CommandFactory factory;
    Interpreter interpreter(factory, std::cin, std::cout);
    interpreter.run();
}