//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_ECHOCOMMAND_H
#define OOP1PROJEKAT_ECHOCOMMAND_H
#include "BaseCommand.h"

class EchoCommand : public BaseCommand {
public:
    explicit EchoCommand(std::vector<std::string> args);
    void execute() override;
};
#endif //OOP1PROJEKAT_ECHOCOMMAND_H