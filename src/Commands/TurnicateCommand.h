//
// Created by vladi on 8/26/2026.
//

#ifndef OOP1PROJEKAT_TURNICATECOMMAND_H
#define OOP1PROJEKAT_TURNICATECOMMAND_H
#include "../Command/BaseCommand.h"
class TurnicateCommand:public BaseCommand {
public:
    using BaseCommand::BaseCommand;
    void execute() override;
    bool hasInput() const override{return false;}

    static BaseCommand* create(ParsedCommand parsed) {
        return new TurnicateCommand(std::move(parsed), nullptr, nullptr);
    }
};
#endif //OOP1PROJEKAT_TURNICATECOMMAND_H