//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_ECHOCOMMAND_H
#define OOP1PROJEKAT_ECHOCOMMAND_H
#include <string>
#include <vector>
#include "../IOResolver/InputResolver.h"
#include "../IOResolver/OutputResolver.h"

#include "../Command/BaseCommand.h"

class EchoCommand : public BaseCommand {
public:


    using BaseCommand::BaseCommand;
    void execute() override;
    static BaseCommand* create(ParsedCommand parsed) {
        auto input = InputResolver::resolve(parsed);
        auto output = OutputResolver::resolve(parsed);
        return new EchoCommand(std::move(parsed), std::move(input), std::move(output));
    }
};
#endif //OOP1PROJEKAT_ECHOCOMMAND_H