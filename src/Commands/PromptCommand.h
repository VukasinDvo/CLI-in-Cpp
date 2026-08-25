//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_PROMPTCOMMAND_H
#define OOP1PROJEKAT_PROMPTCOMMAND_H
#include <string>
#include <vector>
#include "../Command/BaseCommand.h"

class PromptCommand : public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    PromptCommand(std::vector<std::string> args);
    void execute() override;

    static BaseCommand* create(ParsedCommand parsed) {
        return new PromptCommand(std::move(parsed), nullptr, nullptr);
    }

    static std::string getPrompt();

private:
    static std::string prompt;
};
#endif //OOP1PROJEKAT_PROMPTCOMMAND_H