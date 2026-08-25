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

    while (readLine(line)) {
        try {
            BaseCommand* cmd = parser.parseCmd(line);
            if (cmd) {
                cmd->execute();
                delete cmd;
            }
        } catch (const std::exception& e) {
            output << "Greska: " << e.what() << "\n";
        }

        // Print prompt for the next iteration
        output << PromptCommand::getPrompt() << " ";
    }
}

bool Interpreter::readLine(std::string &line) {
    return static_cast<bool>(std::getline(input, line));
}