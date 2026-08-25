//
// Created by vladi on 8/25/2026.
//

#ifndef OOP1PROJEKAT_WCCOMMAND_H
#define OOP1PROJEKAT_WCCOMMAND_H
#include "../Command/BaseCommand.h"
#include "../IOResolver/OutputResolver.h"
#include "../IOResolver/InputResolver.h"

class WcCommand:public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    void execute() override;
    static BaseCommand* create(ParsedCommand parsed) {
        auto input = InputResolver::resolve(parsed);
        auto output = OutputResolver::resolve(parsed);
        return new WcCommand(std::move(parsed), std::move(input), std::move(output));
    }
    private:
    int CountWords() ;
    int CountCharacters();

};
#endif //OOP1PROJEKAT_WCCOMMAND_H