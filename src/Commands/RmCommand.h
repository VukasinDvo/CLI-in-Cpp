//
// Created by vladi on 8/26/2026.
//

#ifndef OOP1PROJEKAT_RMCOMMAND_H
#define OOP1PROJEKAT_RMCOMMAND_H
#include "../Command/BaseCommand.h"

class RmCommand:public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    void execute() override;

    static BaseCommand* create(ParsedCommand parsed) {
        return new RmCommand(std::move(parsed), nullptr, nullptr);
    }
};

#endif