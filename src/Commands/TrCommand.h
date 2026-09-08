//
// Created by vladi on 9/6/2026.
//

#ifndef OOP1PROJEKAT_TRCOMMAND_H
#define OOP1PROJEKAT_TRCOMMAND_H
#include "../Command/BaseCommand.h"
#include "../IOResolver/OutputResolver.h"
#include "../IOResolver/InputResolver.h"
class TrCommand:public BaseCommand {
    public:
    using BaseCommand::BaseCommand;
    void execute() override;
    bool hasInput() const override{return false;}

    static BaseCommand* create(ParsedCommand parsed) {
        auto input= InputResolver::resolve(parsed);
        auto output= OutputResolver::resolve(parsed);
        return new TrCommand(std::move(parsed), std::move(input), std::move(output));

    }



};
#endif //OOP1PROJEKAT_TRCOMMAND_H