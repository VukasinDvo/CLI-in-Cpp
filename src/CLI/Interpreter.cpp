//
// Created by vladi on 8/25/2026.
//

#include "Interpreter.h"

#include "../Commands/PromptCommand.h"
#include "../LineParser/Parser.h"

Interpreter::Interpreter(CommandFactory& factory, std::istream& input, std::ostream& output)
    : factory(factory), parser(factory), input(input), output(output) {}

void Interpreter::run() {
    std::string line;

    // Print initial prompt before waiting for input
    output << PromptCommand::getPrompt() << " ";

    while (std::getline(input, line)) {
        try {
            BaseCommand* cmd = parser.parseCmd(line);
            if (cmd) {
                cmd->execute();
                delete cmd;
            }
        } catch (const std::exception& e) {
            output << "Greska: " << e.what();
        }

        output<<"\n";
        output << PromptCommand::getPrompt();
    }
}

