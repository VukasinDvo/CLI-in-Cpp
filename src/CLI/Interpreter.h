//
// Created by vladi on 8/25/2026.
//

#ifndef OOP1PROJEKAT_INTERPRETER_H
#define OOP1PROJEKAT_INTERPRETER_H
#include "../CommandFactory/CommandFactory.h"
#include "../LineParser/Parser.h"

class Interpreter {
    public:
    Interpreter(CommandFactory& factory,std::istream& input,std::ostream& output);
    void run();

    private:
    CommandFactory& factory;
    Parser parser;
    std::istream& input;
    std::ostream& output;

    bool readLine(std::string& line);
};
#endif //OOP1PROJEKAT_INTERPRETER_H