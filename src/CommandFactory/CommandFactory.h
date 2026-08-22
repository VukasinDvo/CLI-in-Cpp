//
// Created by vladi on 8/21/2026.
//

#ifndef OOP1PROJEKAT_COMMANDFACTORY_H
#define OOP1PROJEKAT_COMMANDFACTORY_H
#include <string>
#include <unordered_map>
#include "../Command/BaseCommand.h"

class CommandFactory {
    public:
    CommandFactory();
    BaseCommand* create(const ParsedCommand& parsed) const;

    private:
    std::unordered_map<std::string,BaseCommand::FunWraper> commands;
};
#endif //OOP1PROJEKAT_COMMANDFACTORY_H