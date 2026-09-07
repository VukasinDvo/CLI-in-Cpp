//
// Created by vladi on 9/7/2026.
//

#ifndef OOP1PROJEKAT_HEADCOMMND_H
#define OOP1PROJEKAT_HEADCOMMAND_H
#include "../Command/BaseCommand.h"
#include "../IOResolver/InputResolver.h"
#include "../IOResolver/OutputResolver.h"

class HeadCommand:public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    void execute() override;

    static BaseCommand* create(ParsedCommand parsed) {
        auto input = InputResolver::resolve(parsed);
        auto output = OutputResolver::resolve(parsed);
        return new HeadCommand(std::move(parsed),std::move(input),std::move(output));

    }
    private:
    int parseLineCount();

};
#endif //OOP1PROJEKAT_HEADCOMMAND_H