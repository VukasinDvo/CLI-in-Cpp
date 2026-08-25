//
// Created by vladi on 8/25/2026.
//

#ifndef OOP1PROJEKAT_DATECOMMAND_H
#define OOP1PROJEKAT_DATECOMMAND_H
#include "../Command/BaseCommand.h"
#include "../IOResolver/OutputResolver.h"

class DateCommand:public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    void execute() noexcept override;
    static BaseCommand* create(ParsedCommand parsed) {
        auto output = OutputResolver::resolve(parsed);
        return new DateCommand(std::move(parsed), nullptr, std::move(output));
    }
};
#endif //OOP1PROJEKAT_DATECOMMAND_H